#!/bin/bash
mkdir -p build
cmake --build build --config Debug --target monty
# clear
cd build/bin
echo "----------------------------------"
./monty
