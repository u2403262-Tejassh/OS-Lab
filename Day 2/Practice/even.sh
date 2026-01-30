#1/bin/bash
echo "Enter limit: "
read N
I=0
while [ $I -le $N ]
do 
echo "$I"
I=`expr $I + 2`
done
