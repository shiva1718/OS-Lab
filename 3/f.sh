# arithematic operations using switch case
echo "Enter two numbers"
read a b
echo "menu"
echo "1.addition"
echo "2.subtraction"
echo "3.multiplication"
echo "4.division"
echo "enter your choice"
read ch
case $ch in
1)sum=`expr $a + $b`
echo "sum="$sum;;
2)sub=`expr $a - $b`
echo "sub="$sub;;
3)mul=`expr $a \* $b`
echo "mul="$mul;;
4)div=`expr $a / $b`
echo "div="$div;;
*)echo "invalid choice";;
esac
