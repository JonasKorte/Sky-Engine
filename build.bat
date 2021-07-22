@echo off

IF "%~1" == "" GOTO PrintHelp
IF "%~1" == "compile" GOTO Compile
IF "%~1" == "vspath" GOTO VsPath

vendor\premake5win\premake5.exe %1
GOTO Done

:PrintHelp

echo.
echo Enter 'build.bat action' where action is one of the following:
echo.
echo   compile           Will generate make file then compile using the make file.
echo   clean             Remove all binaries and intermediate binaries and project files.
echo   codelite          Generate CodeLite project files
echo   gmake2             Generate GNU makefiles for Linux
echo   vs2015            Generate Visual Studio 2015 project files
echo   vs2017            Generate Visual Studio 2017 project files
echo   vs2019            Generate Visual Studio 2019 project files
echo   xcode4            Generate Apple Xcode 4 project files

GOTO Done

:Compile

vendor\premake5win\premake5.exe %2

set /p vspath=<.vspath

echo Visual Studio Path: "%vspath%\Common7\Tools\VsDevCmd.bat"

call "%vspath%\Common7\Tools\VsDevCmd.bat"

set solutionFile="SkyEngine.sln"
msbuild /t:Build /p:Configuration=%3 /p:Platform=x64 %solutionFile%

GOTO Done

:VsPath

set path=%2
set path=%path:"=%

echo %path%>.vspath

:Done
