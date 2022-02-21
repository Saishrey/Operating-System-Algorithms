#!/bin/bash
echo "To display numbers between 50-100 divisible by 3 and not by 5."

i=50
while [ $i -le 100 ]
do
    if [ $(($i%3)) -eq 0 -a $(($i%5)) -ne 0 ]
    then
        echo $i
    fi
    i=$(($i+1))
done

