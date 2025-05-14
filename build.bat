@echo off
echo [*] Compiling resources...

windres resource.rc -O coff -o resource.res
windres app.rc -O coff -o manifest.res

echo [*] Building executable...

g++ main.cpp resource.res manifest.res -o wifi-reset.exe -mwindows

echo [*] Done.
