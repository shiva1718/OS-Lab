# check if a number is odd or even
echo -n "enter the number:"
read num
if [ $((num%2)) -eq 0 ]
then
echo "the number is even"
else
echo "the number is odd"
fi
