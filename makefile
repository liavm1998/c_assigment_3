# -*- Makefile -*-
CC=gcc
AR=ar
FLAGS= -Wall -g

all: ans
 
ans: QuesAnswers helpers main

main: main.o QuesAnswers.a helpers.a
	$(CC) $(FLAGS) -o stringProg main.o helpers.a QuesAnswers.a

main.o: main.c
	$(CC) $(FLAGS) -c main.c
QuesAnswers: Q1 Q2 Q3 QuesAnswers.h
	$(AR) -rcs QuesAnswers.a Q1.o Q2.o Q3.o

Q1: Q1.c QuesAnswers.h
	$(CC) $(FLAGS) -c Q1.c


Q2: Q2.c QuesAnswers.h
	$(CC) $(FLAGS) -c Q2.c


Q3: Q3.c QuesAnswers.h
	$(CC) $(FLAGS) -c Q3.c


helpers: helpers.o
	$(AR) -rcs helpers.a helpers.o

helpers.o: helpers.c helpers.h
	$(CC) $(FLAGS) -c helpers.c

.PHONY: clean all
clean:
	rm -f *.o *.a *.so stringProg