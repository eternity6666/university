#!/bin/bash
echo "Enter the directory name:"
read dir
if [ -d $dir ];then
    cd $dir
    ls > file
    exec < file
    while read line
    do
        if [ -f $line ];then
            if [ -r $line -a -w $line -a -x $line ];then
                echo "$line has all permission"
            fi
        fi
    done
fi
