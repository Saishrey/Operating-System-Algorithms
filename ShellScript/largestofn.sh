#!/bin/bash

list=()

read -p "Enter the size of the list: " size

echo "Enter the elements of the list: "

for(( i=0; i<$size; i++ ))
do
    read num
    list[$i]=$num
done

max=0

echo -n "List: "
for(( i=0; i<$size; i++ ))
do
    if [ ${list[$i]} -gt $max ]; then
        max=${list[$i]}
    fi
    echo -n "${list[$i]} "
done

echo " "
echo "$max is the largest number."

