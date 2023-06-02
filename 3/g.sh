# find area of circle, square, rectangle, triangle
echo "1. circle"
echo "2. square"
echo "3. rectangle"
echo "4. triangle"
echo "enter your choice"
read ch
case $ch in
1) echo "enter radius"
read r
area=`echo 3.1415 \* $r \* $r | bc`
echo "area of circle is $area";;
2) echo "enter side"
read s
area=`echo $s \* $s | bc`
echo "area of square is $area";;
3) echo "enter length and breadth"
read l b
area=`echo $l \* $b | bc`
echo "area of rectangle is $area";;
4) echo "enter base and height"
read b h
area=`echo 0.5 \* $b \* $h | bc`
echo "area of triangle is $area";;
*) echo "invalid choice";;
esac
