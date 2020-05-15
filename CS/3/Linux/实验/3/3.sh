#!/bin/bash
str1=$1
str2=$2
if [ ${str1} = ${str2} ]
then
    echo "相同"
else
    echo "不同"
fi