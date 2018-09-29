@echo off
cd /d %~dp0
copy ..\reference\*.* src\*.*
pushd src
echo . | make.bat
popd
pause