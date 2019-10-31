#!/bin/bash
filename=$1
start=$2
end=$3
sed -n "$start,$end p" $filename
exit 0
