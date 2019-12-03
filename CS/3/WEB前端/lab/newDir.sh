if [[ $# -eq 2 ]];then
	w=$1
	num=$2
	mkdir "lab$1"
	cd "lab$1"
	for((x=1;x<=$num;x++))
	do
		s1="sy$w-$x.html"
		s2="sy$w-$x.css"
		s3="sy$w-$x.js"
		s='<!DOCTYPE html>\n
		<html lang="en">\n<head>\n
		<meta charset="UTF-8">\n
		<meta name="viewport" content="width=device-width, initial-scale=1.0">\n
		<meta http-equiv="X-UA-Compatible" content="ie=edge">\n
		<title>实验'$w'步骤'$x'</title>\n
	    <link rel="stylesheet" href="./'$s2'">\n
	    <script src="./'$s3'"></script>\n
		</head>\n
		<body>\n</body>\n
		</html>\n'
		echo -e $s > $s1
		echo "" > $s2
		echo "" > $s3
		mkdir "sy$w-$x"
		mv $s1 "sy$w-$x/"
		mv $s2 "sy$w-$x/"
		mv $s3 "sy$w-$x/"
	done
else
	echo "参数错误"
fi
