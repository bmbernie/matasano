# Debugging

## Setup

1. Firmware -> I included the prebuilt elf binary in [firmware](firmware/).
2. Launchpad working and connected to computer (micro usb -> usb) (LED On)

## Flashing Firmware (Terminal 1)

Connect the LaunchPad and start MSPDebug:

```bash
mspdebug rf2500
```

At the MSPDebug prompt, program the firmware:

```text
prog ./firmware/inception.elf
```

To run the firmware normally:

```text
reset
run
```

`reset` resets and halts the MCU. `run` is required to begin executing the firmware.

After startup, the red LED should illuminate and the device will wait for a password over UART.

## UART Serial Port (Terminal 2)

In another terminal, start the USB UART bridge:

```bash
python3 launchpad_usb_uart_bridge.py
```

The bridge displays output from the MSP430 and sends a line to the UART when Enter is pressed.

## Connecting the Debugger

In another terminal, `lldb` connects to the msp430 via the MSPDebug's GDB remote server.

```bash
"$(brew --prefix lldb)/bin/lldb"
```

Configure LLDB for the MSP430 target:

```text
settings set target.default-arch msp430
settings set plugin.process.gdb-remote.target-definition-file ./msp430_mspdebug.py
settings set plugin.process.gdb-remote.use-g-packet-for-reading true
settings set target.use-fast-stepping false
```

Load the local ELF for symbols and source information (optional/spoiler):

```text
target create ./firmware/inception.elf
```

Connect to MSPDebug when server is listening:

```text
gdb-remote 127.0.0.1:2000
```

If all goes well you should now be connected.

```asm
(lldb) gdb-remote 127.0.0.1:2000
Process 1 stopped
* thread #1, stop reason = signal SIGTRAP
       frame #0: 0xc04c new_orleans_G2553.elf`_start
new_orleans_G2553.elf`_start:
    0xc04c <+0>: mov    #1024, r1

new_orleans_G2553.elf`__crt0_init_bss:
    0xc050 <+0>: mov    #512, r12
    0xc054 <+4>: clr    r13
    0xc056 <+6>: mov    #8, r14
(lldb) image lookup -n main
1 match found in /Users/b/Downloads/microcorruption-ghidra-pilot/hardware/new_orleans_G2553.elf:
        Address: new_orleans_G2553.elf[0xc1ac] (new_orleans_G2553.elf.PT_LOAD[0]..text + 352)
        Summary: new_orleans_G2553.elf`main at new_orleans_G2553.c:125:1
(lldb) image lookup -n create_password
1 match found in /Users/b/Downloads/microcorruption-ghidra-pilot/hardware/new_orleans_G2553.elf:
        Address: new_orleans_G2553.elf[0xc150] (new_orleans_G2553.elf.PT_LOAD[0]..text + 260)
        Summary: new_orleans_G2553.elf`create_password at new_orleans_G2553.c:103:26
(lldb) image lookup -n get_password
1 match found in /Users/b/Downloads/microcorruption-ghidra-pilot/hardware/new_orleans_G2553.elf:
        Address: new_orleans_G2553.elf[0xc146] (new_orleans_G2553.elf.PT_LOAD[0]..text + 250)
        Summary: new_orleans_G2553.elf`get_password at new_orleans_G2553.c:97:5
(lldb) image lookup -n check_password
1 match found in /Users/b/Downloads/microcorruption-ghidra-pilot/hardware/new_orleans_G2553.elf:
        Address: new_orleans_G2553.elf[0xc184] (new_orleans_G2553.elf.PT_LOAD[0]..text + 312)
        Summary: new_orleans_G2553.elf`check_password at new_orleans_G2553.c:112:30
(lldb) breakpoint set -n main
Breakpoint 1: where = new_orleans_G2553.elf`main + 6 at new_orleans_G2553.c:127:5, address = 0xc1b2
(lldb) process continue
Process 1 resuming
Process 1 stopped
* thread #1, stop reason = breakpoint 1.1
       frame #0: 0xc1b2 new_orleans_G2553.elf`main at new_orleans_G2553.c:127:5
   124  int main(void)
   125  {
   126      char password[100];
-> 127      board_init();
   128      create_password();
   129      uart_puts("Enter the password to continue");
   130      get_password(password);
(lldb) register read
General Purpose Registers:
   pc = 0x0000c1b2
   sp = 0x00000398
   r2 = 0x00000001
   r3 = 0x00000000
   fp = 0x00000efd
   r5 = 0x00007bf3
   r6 = 0x0000deff
   r7 = 0x0000f9ff
   r8 = 0x0000fff1
   r9 = 0x000037fb
  r10 = 0x00000000
  r11 = 0x00000000
  r12 = 0x00000000
  r13 = 0x00000000
  r14 = 0x00000208
  r15 = 0x00000208

(lldb) disassemble -n main
new_orleans_G2553.elf`main:
    0xc1ac <+0>:  push   r10
    0xc1ae <+2>:  sub    #100, r1
->  0xc1b2 <+6>:  call   #49252
    0xc1b6 <+10>: call   #49488
    0xc1ba <+14>: mov    #49382, r10
    0xc1be <+18>: mov    #49152, r12
    0xc1c2 <+22>: call   r10
    0xc1c4 <+24>: mov    r1, r12
    0xc1c6 <+26>: call   #49478
    0xc1ca <+30>: mov    r1, r12
    0xc1cc <+32>: call   #49540
    0xc1d0 <+36>: tst    r12
    0xc1d2 <+38>: jeq    $+24
    0xc1d4 <+40>: mov    #49183, r12
    0xc1d8 <+44>: call   r10
    0xc1da <+46>: call   #49568
    0xc1de <+50>: bit.b  #1, &101
    0xc1e2 <+54>: jne    $-4
    0xc1e4 <+56>: bis    #240, r2
    0xc1e8 <+60>: jmp    $-4
    0xc1ea <+62>: mov    #49199, r12
    0xc1ee <+66>: call   r10
    0xc1f0 <+68>: jmp    $-18
```

## Flag

~~~text
YOURANSWERHERE
~~~
