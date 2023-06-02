# find the biggest amoung three numbers
echo "Enter the numbers"
read n1 n2 n3
if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]
then
echo "$n1 is the biggest number"
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ]
then
echo "$n2 is the biggest number"
else
echo "$n3 is the biggest number"
fi
