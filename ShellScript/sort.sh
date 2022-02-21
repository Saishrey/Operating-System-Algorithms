#!/bin/bash
list=(5 2 4 8 1 3 7 9 6)
size=9

echo "List before sorting: "
for(( i=0; i<$size; i++ ))
do
    echo -n "${list[$i]} "
done

echo " "

for(( i=0; i<$size; i++))
do
    for(( j=0; j<$(($size-$i-1)); j++ ))
    do
        if [ ${list[$j]} -gt ${list[$(($j+1))]} ]; then
            temp=${list[$j]}
            list[$j]=${list[$(($j+1))]}
            list[$(($j+1))]=$temp
        fi
    done
done

echo "List after sorting: "
for(( i=0; i<$size; i++ ))
do
    echo -n "${list[$i]} "
done