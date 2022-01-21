# -*- Makefile -*-
CC=gcc
AR=ar
FLAGS= -Wall -g
 
all: QuesAnswers.a helpers.a stringProg

stringProg: Main.o QuesAnswers.a helpers.a
	$(CC) $(FLAGS) -o stringProg main.o helpers.a QuesAnswers.a

Main.o: Main.c
	$(CC) $(FLAGS) -c main.c

QuesAnswers.a: Q1.o Q2.o Q3.o QuesAnswers.h
	$(AR) -rcs QuesAnswers.a Q1.o Q2.o Q3.o

Q1.o: Q1.c QuesAnswers.h
	$(CC) $(FLAGS) -c Q1.c


Q2.o: Q2.c QuesAnswers.h
	$(CC) $(FLAGS) -c Q2.c


Q3.o: Q3.c QuesAnswers.h
	$(CC) $(FLAGS) -c Q3.c


helpers.a: helpers.o
	$(AR) -rcs helpers.a helpers.o

helpers.o: helpers.c helpers.h
	$(CC) $(FLAGS) -c helpers.c

.PHONY: clean all
clean:
	rm -f *.o *.a *.so stringProg
