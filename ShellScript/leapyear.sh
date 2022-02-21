#!/bin/bash
list=()
size=0

i=2000
while [ $i -le 2500 ]
do
    if [ $(($i%400)) -eq 0 ]; then
        list[$size]=$i
        size=$(($size+1))
    elif [ $(($i%100)) -ne 0 -a $(($i%4)) -eq 0 ]; then
        list[$size]=$i
        size=$(($size+1))
    fi

    i=$(($i+1))
done

for(( i=0; i<$size; i++ ))
do
    echo -n "${list[$i]} "
done


