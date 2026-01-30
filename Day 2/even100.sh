#!/bin/bash
for(( i=1; i<101; i=i+1 ))
do
	if [ $((i%2)) -eq 0 ]
	then
		echo -n "$i "
	fi
done
echo
