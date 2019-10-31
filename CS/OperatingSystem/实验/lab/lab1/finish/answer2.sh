#!/bin/bash
word=$1
filePath=$@
for file in $filePath
do
    if [ "$file" != "$word" ];then
        echo "删除前:";
        cat $file;
        sed -i "/$word/d" $file;
        echo "删除后:"
        cat $file;
    fi
done

    
