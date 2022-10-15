@echo OFF 
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
echo "Attempting to build MeetApp Project"
echo .  
devenv "C:\Users\ruheg\OneDrive\Documents\MeetApp_Project\MeetApp\MeetApp.sln" /build Debug 
echo . 
echo "MeetApp build completed." 
echo "Attempting to run unit tests"
echo .
cd C:\Users\ruheg\OneDrive\Documents\MeetApp_Project\MeetApp\Debug
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" 
vstest.console.exe MeetApp_Test.dll /logger:trx
pause
