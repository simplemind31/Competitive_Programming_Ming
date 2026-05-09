#!/bin/bash
g++ A.cpp -o A
for i in {1..5}
do 
    ./A.exe
done