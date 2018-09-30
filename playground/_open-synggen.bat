cd /d %~dp0
if exist doc/TestControl.psgg goto :_open

start  SYN-G-GEN
:: Please set path for SYN-G-GEN if it does not work
pause
exit

:_open
start doc/TestControl.psgg
pause