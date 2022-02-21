#!/bin/bash
for(( i=1; i<=4; i++ ))
do
	for(( s=4-i; s>0; s--))
	do
		echo -n " "
	done

	for(( j=i; j>0; j-- ))
	do
		echo -n "* "
	done
	echo ""
done
