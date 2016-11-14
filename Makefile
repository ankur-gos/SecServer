all: obj

obj: main.o response.o string_util.o
    g++ main.o response.o string_util.o -o SecServer

main.o: main.cpp
    g++ -c main.cpp

response.o: response.cpp
    g++ -c response.cpp

string_util.o: string_util.cpp
    g++ -c response.cpp