
~~~text
inception/
├── COMPILE.md                    - Instructions on how to compile firmware
├── DEBUGGING.md                  - Get started debugging on device
├── README.md                     - Starting point
├── SETUP.md                      - Prepare system for CTF
├── firmware/                     - Pre-built inception.elf (w/ symbols)
├── img/                          - images
├── src/                          - inception.c
├── launchpad_usb_uart_bridge.py  - USB UART serial bridge
└── msp430_mspdebug.py            - Compatibility shim between LLDB and 
                                    MSPDebug's old/minimal GDB remote server.
~~~

`msp430_mspdebug.py` provides LLDB with the MSP430 register layout used by MSPDebug's GDB remote protocol, allowing LLDB to correctly decode registers, the program counter, stack pointer, and execution state when debugging the physical MSP430G2553. This is required, otherwise `lldb` is going to not be useful.
