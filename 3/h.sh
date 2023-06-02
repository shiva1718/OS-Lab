# Fibonacci series
# 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377
echo "enter n"
read n
echo "fibonacci series upto $n terms is"
a=0
b=1
echo $a
echo $b
i=2
while [ $i -lt $n ]
do
c=`expr $a + $b`
echo $c
a=$b
b=$c
i=`expr $i + 1`
done
# Path: 3/i.sh