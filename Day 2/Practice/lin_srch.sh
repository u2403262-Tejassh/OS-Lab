#!/bin/bash
echo "Enter limit of array"
read n
echo "Enter elements in the
array"
for(( i=0; i<n; i++ ))
do
read a[$i]
don
echo "Elements in the array are:"
for(( i=0; i<n; i++ ))
do
echo "${a[$i]}"
done
echo "Enter the element to be searched"
read element
flag=0
for(( i=0; i<n; i++ ))
do
if [ ${a[$i]} -eq $element ]
then
flag=1
break
fi
done
if [ $flag -eq 1 ]
then
echo "$ele is found"
else
echo "$ele is not found"
fi
