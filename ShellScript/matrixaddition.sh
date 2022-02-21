#!/bin/bash
matrix1=(1 2 3 4 5 6 7 8 9)
matrix2=(11 12 13 14 15 16 17 18 19)

rows=3
cols=3

echo "Matrix1"
for(( i=0; i<$rows; i++ ))
do
    for(( j=0; j<$cols; j++ ))
    do
        index=$(($i*$cols+$j))
        echo -n "${matrix1[$index]} "
    done
    echo " "
done

echo " "
echo "Matrix2"
for(( i=0; i<$rows; i++ ))
do
    for(( j=0; j<$cols; j++ ))
    do
        index=$(($i*$cols+$j))
        echo -n "${matrix2[$index]} "
    done
    echo " "
done

k=0
matrix3=()
for(( i=0; i<$rows; i++ ))
do
    for(( j=0; j<$cols; j++ ))
    do
        index=$(($i*$cols+$j))
        matrix3[$k]=$((${matrix1[$index]}+${matrix2[$index]}))
        k=$(($k+1))
    done
done

echo " "
echo "Matrix3 = Matrix1 + Matrix2"
for(( i=0; i<$rows; i++ ))
do
    for(( j=0; j<$cols; j++ ))
    do
        index=$(($i*$cols+$j))
        echo -n "${matrix3[$index]} "
    done
    echo " "
done


