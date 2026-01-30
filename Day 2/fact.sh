#!/bin/bash
echo "Enter a number"
read num
fact=1
for(( i=num; i>0;  i=i-1 ))
do
	fact=$((fact*i))
done
echo "Factorial of $num is $fact"
