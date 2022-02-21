#!/bin/bash
echo "Enter the constants for the following quadratic equation: ax^(2) + bx + c"
read -p "a : " a
read -p "b : " b
read -p "c : " c

square=$(($b*$b-4*$a*$c))
square_root=$(echo "$square" | awk '{print sqrt($square)}')

root1=$((($square_root-$b)/2*a))
root2=$((-(($square_root+$b)/2*a)))

echo "Roots for ($a)x^2 + ($b)x + $c = ($root1) and ($root2)"