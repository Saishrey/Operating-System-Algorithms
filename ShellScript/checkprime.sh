#!/bin/bash
read -p "Enter a number: " num

primecount=0

str="$num is non prime."

for(( i=1; i<=num; i++))
do
	if [ $(($num%$i)) -eq 0 ]; then
		primecount=$(($primecount+1))
	fi
done

if [ $primecount -eq 2 ]; then
	str="$num is a prime number."
fi

echo $str
