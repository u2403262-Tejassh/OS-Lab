#!bin/bash
echo "Enter number: "
read NUM
flag=0
if [ $NUM -le 1 ]
then
	echo "$NUM is neither prime nor composite"
elif [ $NUM -le 3 ]
then
	echo "$NUM is prime"
elif [ $((NUM%2)) -eq 0 -o $((NUM%3)) -eq 0 ]
then
	echo "$NUM is composite"
fi
for (( I=5; I*I<=NUM; I=I+6 ))
do
	if [ $(( $NUM%I )) -eq 0 -a $(( NUM%(I+2) )) -eq 0 ]
	then
		echo "$NUM is composite"
		flag=1
	fi
done
if [ $flag -eq 1 ]
then
	echo "$NUM is prime"
fi
