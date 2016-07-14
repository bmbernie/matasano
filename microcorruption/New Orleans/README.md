# New Orleans Analysis

**Finding:** A plaintext credential is generated and stored in unsecured device memory.

**Location:** `create_password`

## Impact

An attacker can retreive the device password, allowing them to authenticate at will.

## Description

`create_password` writes the expected bytes into a buffer in RAM at address `0x2400`. `check_password` compares the users input with the password stored in RAM and if it matches the program calls `unlock_door`.

Assume `global password[8]`

```asm
447e <create_password>
447e:  3f40 0024      mov	#0x2400, r15    ; r15 stores pointer to password
4482:  ff40 6500 0000 mov.b	#0x65, 0x0(r15) ; password[0] = 'e'
4488:  ff40 4500 0100 mov.b	#0x45, 0x1(r15) ; password[1] = 'E'
448e:  ff40 4700 0200 mov.b	#0x47, 0x2(r15) ; password[2] = 'G'
4494:  ff40 4a00 0300 mov.b	#0x4a, 0x3(r15) ; password[3] = 'J'
449a:  ff40 2100 0400 mov.b	#0x21, 0x4(r15) ; password[4] = '!'
44a0:  ff40 2600 0500 mov.b	#0x26, 0x5(r15) ; password[5] = '&'
44a6:  ff40 2500 0600 mov.b	#0x25, 0x6(r15) ; password[6] = '%'
44ac:  cf43 0700      mov.b	#0x0, 0x7(r15)  ; password[7] = '\0'
44b0:  3041           ret                   ; return
```

This stores the password in memory starting at `0x2400`.  To demonstrate, set a breakpoint on`check_password`, hit `c` to continue to program to the breakpoint.  Enter a password guess and then return to the live memory dump.

~~~hexdump
2400: 6545 474a 2126 2500 0000 0000 0000 0000   eEGJ!&%.........
~~~

A secret stored in attacker-readable firmware or RAM cannot serve as a trust boundary.

## Flag

```text
eEGJ!&%

```
