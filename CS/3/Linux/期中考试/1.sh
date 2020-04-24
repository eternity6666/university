#! /bin/bash
printfFile(){
    echo $(stat --printf="%n %s % i %y" $1)
}
printfDirectory(){
    for file in $(ls $1)
    do
        if [[ -f $1"/"$file ]]
        then
        printfFile $1"/"$file
        else
        printFile $1"/"$file
        fi
    done
}
if [[ $# != 1 ]]
then
    echo "Arguments error. Too more arguments"
elif [[ -f $1 ]]
then
    echo "fileName size(bytes) inode changeDate"
    printfFile $1
elif [[ -d $1 ]]
then
    echo "fileName size(bytes) inode changeDate"
    printfDirectory $1
else
    echo "$1 is not a file or a directory."
fi
