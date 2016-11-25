CC=g++
FLAGS=-c -g -Wall -Wextra -std=c++11

all: obj

obj: main.o response.o string_util.o
	$(CC) main.o response.o string_util.o -o SecServer

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

response.o: response.cpp
	$(CC) $(FLAGS) response.cpp

string_util.o: string_util.cpp
	$(CC) $(FLAGS) string_util.cpp


# TODO: Make clean