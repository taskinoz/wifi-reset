![logo](./wifi_reset_icon.png)

# WiFi Reset Utility (Windows)

A lightweight C++ tool that toggles your Wi-Fi adapter off and back on to quickly resolve connectivity issues after sleep/hibernate. Optionally shows a message box or plays a sound.

## Features

- Silent, no UI window unless `message` argument is passed
- Automatically disables and re-enables your Wi-Fi adapter
- Optional notification (message box or sound)
- Icon included
- UAC auto-elevation using embedded manifest

## Requirements

- Windows 10 or later
- [MinGW-w64](https://www.mingw-w64.org/) with `g++`, `windres`, and `make` in PATH
- Run as Administrator to allow adapter toggling via `netsh`

## Usage

```bash
wifi-reset.exe             # toggles adapter, plays sound
wifi-reset.exe message     # toggles adapter, shows alert box
```

## Build Instructions
Use the included `build.bat` script:

```bash
@echo off
echo [*] Compiling resources...

windres resource.rc -O coff -o resource.res
windres app.rc -O coff -o manifest.res

echo [*] Building executable...

g++ main.cpp resource.res manifest.res -o wifi-reset.exe -mwindows

echo [*] Done.
```

>⚠️ Ensure g++ and windres are in your PATH (install MinGW and set env vars if needed).

## Notes
- You must run as Administrator to allow toggling the Wi-Fi interface via netsh.

- Make sure your adapter is named "Wi-Fi" or adjust the wifiAdapterName variable in main.cpp.

## License
MIT — feel free to use, modify, and distribute.