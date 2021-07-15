#!/bin/sh

PrintHelp()
{
echo Enter 'build.sh action' where action is one of the following:
echo 
echo clean                Remove all binaries and generated files
echo codelite           Generate CodeLite project files
echo gmake2           Generate GNU makefiles for POSIX, MinGW, and Cygwin
echo vs2013            Generate Visual Studio 2013 project files
echo vs2015            Generate Visual Studio 2015 project files
echo vs2017            Generate Visual Studio 2017 project files
echo vs2019            Generate Visual Studio 2019 project files
echo xcode4            Generate Apple Xcode 4 project files
}

if [ "$1" = "" ] ;then 
PrintHelp
else
if [ "$2" = "mac" ] ;then
    echo using mac
    ./vendor/premake5mac/premake5 $1
    exit
fi
if [ "$2" = "linux" ] ;then
    echo using linux
    ./vendor/premake5lin/premake5 $1
    exit
fi
if [ "$(uname)" = "Darwin" ]; then
    echo using mac
    ./vendor/premake5mac/premake5 $1
elif [ "$(expr substr "$(uname -s)" 1 5)" = "Linux" ]; then
    echo using linux
        ./vendor/premake5lin/premake5 $1
    fi
fi