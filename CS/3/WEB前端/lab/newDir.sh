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
		s='<!DOCTYPE html>
		<html lang="en"><head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<meta http-equiv="X-UA-Compatible" content="ie=edge">
		<title>实验'$w'步骤'$x'</title>
	    <link rel="stylesheet" href="./'$s2'">
	    <script src="./'$s3'"></script>
		</head>
		<body></body>
		</html>'
		echo $s > $s1
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
