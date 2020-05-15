#!/bin/bash
path=/home/yzh/.local/share/Trash/files
echo "All files :"
ls ${path}
files=$(ls ${path})
for filename in ${files}
do
    read -p "Are you sure remove ${filename} forever?[y/n]" sure
    if [ ${sure} = "y" ]
    then
        rm -rf ${path}/${filename}
        echo "ok"
    fi
done
echo "剩余文件:"
ls ${path}