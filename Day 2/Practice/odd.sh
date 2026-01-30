#1/bin/bash
echo "Enter limit: "
read N
for(( I=1; I<N; I=I+2))
do
echo "$I"
done
