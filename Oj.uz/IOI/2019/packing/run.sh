#!/bin/bash
g++ packing.cpp -o packing
for x in {1..9};do
    ./packing < tests/0$x.in > outputs/0$x.out
done