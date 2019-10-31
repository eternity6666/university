#!/bin/bash

sum()
{
    x=$1
    y=$2
    k=0
    k=$(( $x + $y ))
    return $k
}

sum 7 5
echo "Sum of two no is:$?"
exit 0
