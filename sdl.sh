#!/bin/bash
if [ "$1" == "lin" ]; then
    if [ "$2" == "-b" ]; then
        mv Makefile ./lin 
    else
        mv lin/Makefile ./
        if [ "$2" == "-d" ]; then
            sudo apt-get install libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev libsdl2-mixer-dev -y
        fi
    fi
elif [ "$1" == "mac" ]; then
    if [ "$2" == "-b" ]; then
        mv Makefile ./mac
    else
        mv mac/Makefile ./
        if [ "$2" == "-d" ]; then
            brew install libsdl2-dev libsdl2-image-dev -y
        fi
    fi
fi