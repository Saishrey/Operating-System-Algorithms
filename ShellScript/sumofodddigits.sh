#!/bin/bash
read -p "Enter a number: " num
oddsum=0
temp=$num
while [ $temp -gt 0 ]
do
    if [ $(($(($temp%10))%2)) -ne 0 ]; then
        sum=$(($sum+$(($temp%10))))
    fi
    temp=$(($temp/10))
done

echo "Odd sum = $sum"