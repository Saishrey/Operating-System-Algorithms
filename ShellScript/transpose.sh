#!/bin/bash
matrix=(1 2 3 4 5 6 7 8 9)

rows=3
cols=3

echo "Matrix: "
for(( i=0; i<$rows; i++ ))
do
    for(( j=0; j<$cols; j++ ))
    do
        index=$(($i*$cols+$j))
        echo -n "${matrix[$index]} "
    done
    echo " "
done

echo "Transpose: "
for(( i=0; i<$rows; i++ ))
do
    for(( j=0; j<$cols; j++ ))
    do
        index=$(($j*$cols+$i))
        echo -n "${matrix[$index]} "
    done
    echo " "
done