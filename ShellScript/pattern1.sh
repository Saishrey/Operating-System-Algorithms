#!/bin/bash
k=1

for(( i=0; i<4; i++ ))
do
    for(( j=0; j<k; j++ ))
    do
        echo -n "$k"
    done
    echo " "
    k=$(($k+1))
done