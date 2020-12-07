CC = gcc
FLAGS = -Wall -g

all:myBanks RunBank

myBanks:libmyBank.a

libmyBank.a:myBank.o myBank.h
	ar rcs libmyBank.a myBank.o myBank.h

myBank.o:myBank.c myBank.h
	$(CC) $(FLAGS) -fPIC -c myBank.c

main.o:main.c myBank.h
	$(CC) $(FLAGS) -c main.c

RunBank:main.o libmyBank.a
	$(CC) $(FLAGS) -o RunBank main.o libmyBank.a 

.PHONY:clean all

clean:
	rm -f *.o *.a *.so RunBank