@echo off
set PWD=%~sdp0
cmd /k "cd /d %PWD%\output&&HexMerge.exe"
exit
@echo off