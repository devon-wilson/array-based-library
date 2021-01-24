//project3 Devon WIlson
C=g++
CFLAGS= -c -Wall
all: prog
prog:carmain.o car.o
        $(CC) carmain.o car.o -o prog
carmain.o: carmain.cpp
        $(CC) $(CFLAGS) carmain.cpp
car.o: car.cpp
        $(CC) $(CFLAGS) car.cpp
