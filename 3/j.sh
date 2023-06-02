# sum of even numbers upto n
echo "enter n"
read n
i=2
s=0
while [ $i -le $n ]
do
s=`expr $s + $i`
i=`expr $i + 2`
done
echo "sum of $n even numbers is $s"
# Path: 3/k.sh