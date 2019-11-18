if [[ $# -eq 2 ]];then
	w=$1
	num=$2
	for((x=1;x<=$num;x++))
	do
		s1="sy$w-$x.html"
		s2="sy$w-$x.css"
		touch $s1 $s2
	done
else
	echo "参数错误"
fi
