#!/bin/bash
for(( i=1; i<=5; i++ ))
do
	for(( s=5-i; s>0; s--))
	do
		echo -n " "
	done

	for(( j=i; j>0; j-- ))
	do
		echo -n "$i "
	done
	echo ""
done
