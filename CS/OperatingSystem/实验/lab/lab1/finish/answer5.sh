#!/bin/bash
# Write a Shell script to find factorial of a given integer
echo "Input an integer:"
read num

ans=1

while [ $num != 1 ]
do
    ans=$((ans * num))
    num=$((num - 1))
done

echo "The factorial is $ans"
