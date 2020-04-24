#! /bin/bash
echo "please input 10 number"
i=0
while(( $i<5 ))
do
    read numbers[i]
    let "i++"
done
i=0
while(( $i<5 ))
do
    read numbers2[i]
    let "i++"
done
i=0
sum=0
while(( $i<5 ))
do
    ((sum+=(${numbers[i]} - ${numbers2[i]}) * (${numbers[i]} - ${numbers2[i]}) ))
    let "i++"
done
result=$(echo "scale=6; sqrt($sum)" | bc)
echo "The Euclidean distance of two array is: $result"
