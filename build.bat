@echo off
setlocal

if not exist build mkdir build
cd build

cmake ..
cmake --build .

cd Debug
.\console-manager.exe

cd ../..

endlocal