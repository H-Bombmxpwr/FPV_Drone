# Crazyradio Firmware Installation and Debugging Guide for macOS

This document provides instructions for installing Crazyradio control software, building firmware, and troubleshooting common issues on macOS.

## Initial Setup

### Install Control Software from Source
Clone the Crazyflie Python library and install `cflib`:

```bash
git clone https://github.com/bitcraze/crazyflie-lib-python.git
cd crazyflie-lib-python
pip install -e .
```

To test the installation, run `cfclient` in the terminal to scan for and connect to the drone.

If the Crazyradio connection fails with packets lost error when moving drone around:

Check you are using the correct firmware. For Crazyradio PA, ensure you are using a PA-specific firmware version. This covered in detial below. if it works, congrats you don't have to deal with firmware

## Firmware Build Instructions

Navigate to the firmware directory after cloning the repository and select the appropriate `make` command based on your Crazyradio version.

Clone the repo:
```bash
git clone https://github.com/bitcraze/crazyflie-firmware.git
```

### Install Build Tools Using Homebrew
Install SDCC and Binutils on your mac:

```bash
brew install sdcc
brew install binutils
ln -s /usr/local/opt/binutils/bin/gobjcopy /usr/local/bin/objcopy
```

### Build Firmware
For the standard Crazyradio:

```bash
make CRPA=0
```

For Crazyradio PA:

```bash
make CRPA=1
```

## Flashing the Firmware

Ensure the Crazyradio is plugged into your computer, then run the following commands from the firmware directory:

```bash
python ../usbtools/launchBootloader.py
sudo python ../usbtools/nrfbootload.py flash bin/cradio.bin
```

After successful flashing, unplug and replug the Crazyradio. Refer to the [Crazyradio Programming Wiki](https://wiki.bitcraze.io/projects:crazyradio:programming) for more information.

## Troubleshooting and Debugging

If you encounter issues during the build or flashing process, follow these steps to troubleshoot.

### If You Encounter a `binutils` Error During Build
If the build process fails due to a `binutils` error,
specifically:

```bash
objcopy -I ihex bin/cradio.ihx -O binary bin/cradio.bin
make: objcopy: No such file or directory
make: *** [cradio.bin] Error 1
```

Download the `binutils-2.42` source from [GNU Binutils](https://ftp.gnu.org/gnu/binutils/binutils-2.42.tar.xz) and compile it manually in the terminal.

```bash
tar -xvf binutils-2.42.tar.xz
cd binutils-2.42
./configure
make
```

Manually use `objcopy` from the compiled `binutils`:

```bash
/Users/yourusername/Downloads/binutils-2.42/binutils/objcopy -I ihex bin/cradio.ihx -O binary bin/cradio.bin
```

Afterward, run `make CRPA=1` to build for Crazyradio PA or `make CRPA=0` for Crazyradio.

### If You Experience the `NoBackendError` When Flashing Firmware

This error indicates that `pyusb` can't find `libusb`. To fix:

#### Confirm `libusb` Installation

```bash
brew list libusb
```

If not present:

```bash
brew install libusb
```

#### Set Environment Variable for libusb

```bash
export DYLD_LIBRARY_PATH="/opt/homebrew/lib:$DYLD_LIBRARY_PATH"
```

#### Create a Symlink for libusb

```bash
sudo ln -s /opt/homebrew/lib/libusb-1.0.dylib /usr/local/lib/libusb-1.0.dylib
```

Run the firmware flashing commands again.
