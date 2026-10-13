#!/usr/bin/env python3

import select
import sys

import usb.core
import usb.util


VID = 0x0451
PID = 0xF432

UART_INTERFACE = 0

EP_OUT = 0x03
EP_IN = 0x83

BAUD = 9600

def drain_input(dev):
    """Discard any stale UART data already buffered by the USB interface."""
    while True:
        try:
            dev.read(
                EP_IN,
                512,
                timeout=20,
            )
        except usb.core.USBTimeoutError:
            break

def set_line_coding(dev):
    """
    Configure the LaunchPad backchannel UART for 9600 8N1.

    CDC SET_LINE_CODING payload:
        uint32_t baud
        uint8_t  stop_bits
        uint8_t  parity
        uint8_t  data_bits
    """
    payload = (
        BAUD.to_bytes(4, "little")
        + bytes([
            0,  # 1 stop bit
            0,  # no parity
            8,  # 8 data bits
        ])
    )

    dev.ctrl_transfer(
        0x21,               # Host-to-device | Class | Interface
        0x20,               # SET_LINE_CODING
        0,
        UART_INTERFACE,
        payload,
    )


def main():
    dev = usb.core.find(
        idVendor=VID,
        idProduct=PID,
    )

    if dev is None:
        print(
            f"LaunchPad {VID:04x}:{PID:04x} not found.",
            file=sys.stderr,
        )
        return 1

    try:
        try:
            dev.get_active_configuration()
        except usb.core.USBError:
            dev.set_configuration()

        usb.util.claim_interface(
            dev,
            UART_INTERFACE,
        )

        try:
            set_line_coding(dev)
        except usb.core.USBTimeoutError:
            print(
                "[SET_LINE_CODING timed out; continuing with "
                "the LaunchPad's existing UART configuration]",
                file=sys.stderr,
            )

        drain_input(dev)

        print(
            f"[LaunchPad UART: {BAUD} 8N1 "
            f"interface={UART_INTERFACE} "
            f"IN=0x{EP_IN:02x} OUT=0x{EP_OUT:02x}]",
            file=sys.stderr,
        )
        print(
            "[Ctrl-C to exit]",
            file=sys.stderr,
        )

        while True:
            #
            # Drain any UART data currently available.
            #
            try:
                data = bytes(
                    dev.read(
                        EP_IN,
                        512,
                        timeout=20,
                    )
                )

                if data:
                    sys.stdout.buffer.write(data)
                    sys.stdout.buffer.flush()

            except usb.core.USBTimeoutError:
                pass

            #
            # stdin is in normal terminal canonical mode.
            #
            # select() becomes readable after the user presses Enter.
            #
            ready, _, _ = select.select(
                [sys.stdin],
                [],
                [],
                0,
            )

            if not ready:
                continue

            line = sys.stdin.readline()

            if line == "":
                break

            #
            # Strip the terminal newline and transmit a CR,
            # matching what the MSP430 firmware expects from Enter.
            #
            line = line.rstrip("\r\n")

            payload = line.encode("utf-8") + b"\r"

            dev.write(
                EP_OUT,
                payload,
                timeout=1000,
            )

    except KeyboardInterrupt:
        print(
            "\n[UART closed]",
            file=sys.stderr,
        )

    finally:
        try:
            usb.util.release_interface(
                dev,
                UART_INTERFACE,
            )
        except Exception:
            pass

        usb.util.dispose_resources(dev)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
