from lldb import *

registers = []

names = [
    ("pc", "r0", LLDB_REGNUM_GENERIC_PC),
    ("sp", "r1", LLDB_REGNUM_GENERIC_SP),
    ("r2", None, LLDB_INVALID_REGNUM),
    ("r3", None, LLDB_INVALID_REGNUM),
    ("fp", "r4", LLDB_REGNUM_GENERIC_FP),
    ("r5", None, LLDB_INVALID_REGNUM),
    ("r6", None, LLDB_INVALID_REGNUM),
    ("r7", None, LLDB_INVALID_REGNUM),
    ("r8", None, LLDB_INVALID_REGNUM),
    ("r9", None, LLDB_INVALID_REGNUM),
    ("r10", None, LLDB_INVALID_REGNUM),
    ("r11", None, LLDB_INVALID_REGNUM),
    ("r12", None, LLDB_INVALID_REGNUM),
    ("r13", None, LLDB_INVALID_REGNUM),
    ("r14", None, LLDB_INVALID_REGNUM),
    ("r15", None, LLDB_INVALID_REGNUM),
]

for i, (name, alt_name, generic) in enumerate(names):
    r = {
        "name": name,
        "set": 0,

        # MSPDebug serializes each MSP430 register as one
        # 32-bit little-endian value in its GDB 'g' packet.
        "bitsize": 32,
        "offset": i * 4,

        "encoding": eEncodingUint,
        "format": eFormatHex,

        "gcc": i,
        "dwarf": i,
        "gdb": i,
    }

    if alt_name is not None:
        r["alt-name"] = alt_name

    if generic != LLDB_INVALID_REGNUM:
        r["generic"] = generic

    registers.append(r)


def get_target_definition():
    return {
        "sets": [
            "General Purpose Registers",
        ],
        "registers": registers,
        "host-info": {
            "triple": "msp430-none-elf",
            "endian": eByteOrderLittle,
        },

        # 16 registers * 4 bytes each, as returned by MSPDebug.
        "g-packet-size": 64,
    }


def get_dynamic_setting(_, setting_name):
    if setting_name == "gdb-server-target-definition":
        return get_target_definition()

    return None
