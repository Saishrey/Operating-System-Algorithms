#!/bin/bash
read -p "Enter a number: " num

square_root=$(echo "$num" | awk '{print sqrt($num)}')
echo "Square root of $num is $square_root"
