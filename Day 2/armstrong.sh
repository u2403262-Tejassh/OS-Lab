#!/bin/bash
echo "Enter a 3 digit number:"
read num
copy=$num
armst=0
while [ $num -gt 0 ]
do
	digit=$((num%10))
	armst=$((armst+digit*digit*digit))
	num=$((num/10))
done
if [ $armst -eq $copy ]
then
	echo "$copy is an armstrong number"
else
	echo "$copy is not an armstrong number"
fi
