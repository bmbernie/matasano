# Compiling Firmware (Optional)

Compiling the firmware is optional. A prebuilt firmware is included with the project and can be flashed directly using the instructions in `DEBUGGING.md`.

## Setup

This assumes you have already completed the steps in `SETUP.md`

## Compile

Compile the firmware:

```bash
msp430-elf-gcc \
    -mmcu=msp430g2553 \
    -mcpu=msp430 \
    -mdevices-csv-loc="$MSP430_GCC_INCLUDE_DIR/devices.csv" \
    -Os \
    -g \
    -std=c99 \
    -Wall \
    -Wextra \
    -I"$MSP430_GCC_INCLUDE_DIR" \
    -L"$MSP430_GCC_INCLUDE_DIR" \
    -o build/inception.elf \
    src/inception.c
```

The compiler options are:

- `-mmcu=msp430g2553` — target the MSP430G2553.
- `-mcpu=msp430` — generate MSP430 instructions.
- `-Os` — optimize for code size.
- `-g` — include debugging information for LLDB.
- `-std=c99` — compile the source as C99.

A successful build produces:

```text
inception.elf
```

The ELF contains the executable firmware together with the symbols and debugging information used by MSPDebug and LLDB.

## Optional Intel HEX Output

If an Intel HEX image is needed for another programmer or a debugging tool like Ghidra, generate one from the ELF:

```bash
msp430-elf-objcopy \
    -O ihex \
    build/inception.elf \
    build/inception.hex
```

The normal project workflow flashes the ELF directly, so the HEX file is not required.
