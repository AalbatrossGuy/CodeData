@echo off
if not exist build mkdir build 
pushd build
gcc ..\test.c -o main.exe
popd 