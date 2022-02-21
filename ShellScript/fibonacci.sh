#!/bin/bash
read -p "Enter n: " num

echo "Fibonacci series: "
a=0
b=1

for(( i=0; i<$num; i++ ))
do
    echo -n "$b "
    fib=$(($a+$b))
    a=$b
    b=$fib
done

