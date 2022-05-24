#!/bin/bash
if [ "$1" == "-w" ]; then
    sudo apt-get install libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev libsdl2-mixer-dev -y
elif [ "$1" == "-m" ]; then
    brew install libsdl2-dev libsdl2-image-dev -y
fi