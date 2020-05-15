mymain: mymax.o mymin.o mysum.o myavg.o mymain.o
	gcc -o mymain mymax.o mymin.o myavg.o mysum.o mymain.o
mymain.o: mymain.c my.h
	gcc mymain.c -c
myavg.o: myavg.c
	gcc myavg.c -c
mysum.o: mysum.c
	gcc mysum.c -c
mymin.o: mymin.c
	gcc mymin.c -c
mymax.o: mymax.c
	gcc mymax.c -c
