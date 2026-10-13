# SETUP 

- *Updated for macOS 27 -- Golden Gate -- 10/2026*

## Installing MSP430 Compiler

The firmware is written for the TI MSP430G2553 and is compiled with the TI MSP430 GCC toolchain.

Download the macOS package from [TI](https://www.ti.com/tool/MSP430-GCC-OPENSOURCE)

~~~
The tested release is:
    MSP430-GCC-OPENSOURCE 9.3.1.2
    GCC 9.3.1.11
    MSP430 support files 1.212
~~~

TI provides both a macOS installer containing the compiler and support files, and separate toolchain/support-file downloads. The combined macOS installer is the simplest option.

If using the standalone archive, install it somewhere under your home directory, for example:

```bash
mkdir -p ~/opt
tar -xjf msp430-gcc-9.3.1.11_macos.tar.bz2 -C ~/opt
```

Add the compiler's `bin` directory to your shell path. For example:

```bash
export PATH="$HOME/opt/msp430-gcc-9.3.1.11/bin:$PATH"
```

If the support files are installed separately, extract them alongside the compiler and configure the include/support path as appropriate for your local installation.

## Installing Rosetta

The TI macOS MSP430 GCC binaries are Intel binaries. On an Apple Silicon Mac, install Rosetta so they can run.

```bash
softwareupdate --install-rosetta
```

After Rosetta and the MSP430 GCC toolchain are installed, the compiler can be used normally.  See [COMPILING.md](COMPILING.md) for firmware build instructions.

## Python Environment

You will need Python to launch the UART bridge that I wrote. Everything was tested with the current version of Python at the time of writing (3.15). This is how I did it on my system.

1. Install and Configure Python

```bash
brew install pyenv

pyenv install 3.15.0
pyenv global 3.15.0
pyenv rehash
```

2. Configure the shell - `~/.zshrc`:

```bash
export PYENV_ROOT="$HOME/.pyenv"
[[ -d $PYENV_ROOT/bin ]] && export PATH="$PYENV_ROOT/bin:$PATH"
eval "$(pyenv init - zsh)"
```

3. Install USB stuff:

```bash
python3 -m pip install PyUSB==1.3.1

brew install libusb
```

## Debugger Tools

Apple's system `lldb` isn't sufficient for debugging this processor target so we need to get version that was compiled with the additional support.  

`mspdebug` provides the physical debug connection to the LaunchPad and exposes a GDB remote server that LLDB can connect to.

```bash
brew install mspdebug lldb
```
