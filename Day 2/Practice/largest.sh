#!/bin/bash
echo "Enter first number: "
read NUM1
echo "Enter second number: "
read NUM2
if [ $NUM1 -gt $NUM2 ]
then
echo "$NUM1 is largest"
elif [ $NUM1 -lt $NUM2 ]
then 
echo "$NUM2 is largest"
else
echo "Both numbers are equal"
fi
