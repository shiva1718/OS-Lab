# nth power of a given numner
echo "enter base"
read base
echo "enter power"
read power
i=1
s=1
while [ $i -le $power ]
do
s=`expr $s \* $base`
i=`expr $i + 1`
done
echo "$base to the power $power is $s"
# Path: 3/l.sh