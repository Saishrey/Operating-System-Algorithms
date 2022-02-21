#!/bin/bash
echo "To generate squares of first 20 numbers."

for (( i=1; i<=20; i++))
do
    square=$(($i**2))
    echo "$i^2 = $square"
done
