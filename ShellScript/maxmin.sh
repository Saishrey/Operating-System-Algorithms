#!/bin/bash
echo "Enter n: "
read num

temp=$num
max=0
min=9

while [ $temp -gt 0 ]
do
	if [ $(($temp%10)) -gt $max ]; then
		max=$(($temp%10))
	elif [ $(($temp%10)) -lt $min ]; then
		min=$(($temp%10))
	fi
	temp=$(($temp/10))
done

echo "Max = $max and Min = $min"
