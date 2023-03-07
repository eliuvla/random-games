# the compiler: gcc for C program, define as g++ for C++
CC = g++
 
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings

 
CFLAGS  = -Wall -O3


main: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main

clean:
	del *.o main.exe