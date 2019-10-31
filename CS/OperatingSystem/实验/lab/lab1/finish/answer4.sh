#!/bin/bash
if [ $# == 0 ];then
    echo "Didn't input arguments"
else
    tr " " "
    " < $1 > temp
    shift
    for i in $*
    do
        tr " " "
        " < $i > temp1
        y=`wc -l < temp`
        j=1
        while [ $j -le $y ]
        do
            x=`head -n $j temp | tail -1`
            c=`grep -c "$x" temp1`
            echo $x $c
            j=$((j+1))
        done
    done
fi

