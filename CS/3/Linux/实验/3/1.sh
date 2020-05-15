#!/bin/bash
read -a numbers
cnt=${#numbers[*]}
sum=0
count=0
while [ ${count} -lt ${cnt} ]
do
    sum=`expr ${sum} + ${numbers[${count}]}`
    count=`expr ${count} + 1`
done
avg=`expr ${sum} / ${cnt}`
awk 'BEGIN{printf "average = %.1f\n",('${sum}'/'${cnt}')}'
count=0
S2n=0
xi=0
while [ ${count} -lt ${cnt} ]
do
    xi=`expr ${numbers[${count}]} - ${avg}`
    xi=`expr ${xi} \* ${xi}`
    S2n=`expr ${S2n} + ${xi}`
    count=`expr ${count} + 1`
done
#S2n=`expr ${S2n} / ${cnt}`
awk 'BEGIN{printf "Standard Deviation = %.1f\n",sqrt('${S2n}'/'${cnt}')}'