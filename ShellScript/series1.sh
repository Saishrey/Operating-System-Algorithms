#!/bin/bash
echo "To generate the following series"

str=""

for i in 2 4 6 8
do 
    next=$(($i*2))
    if [ $i -eq 8 ]
    then
        str+="$i - $next"
    else
        str+="$i - $next + "
    fi
done

echo $str
