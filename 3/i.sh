# check if given number is armstrong or not
echo "enter a number"
read n
s=0
t=$n
while [ $n -gt 0 ]
do
r=`expr $n % 10`
i=`expr $r \* $r \* $r`
s=`expr $s + $i`
n=`expr $n / 10`
done
if [ $s -eq $t ]
then
echo "$t is an armstrong number"
else
echo "$t is not an armstrong number"
fi