windres resource.rc -O coff -o resource.res
windres app.rc -O coff -o manifest.res
g++ main.cpp resource.res manifest.res -o wifi-reset.exe -mwindows