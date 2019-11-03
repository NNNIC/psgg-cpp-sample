@echo off
echo :            clean src and doc folders.
echo: 
pause
del /s /q src\*.*
copy ..\reference\*.* src\*.*
pause