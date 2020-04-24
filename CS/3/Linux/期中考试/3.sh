#!/bin/bash
echo -n "please input a number greater than 1: "
while [ 1 ]
do
    read num
    expr $num + 6 &>/dev/null
    if [[ $? -eq 0 && $num -ge 1 ]]
    then
        break
    fi
    echo -n "input error, please input a number greater than 1: "
done
i=2
sum="1"
while [ $i -le $num ]
do
    sum="$sum+1/$i"
    let "i++"
done
result=$(echo "scale=3; $sum" | bc)
echo "result is: $result"
