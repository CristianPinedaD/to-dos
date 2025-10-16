CC = g++
FLAGS = -Wall -Wpedantic -Wextra 

all: main

main: main.cpp todo.o
	$(CC) $(FLAGS) main.cpp todo.o -o main

todo.o: todo.cpp
	$(CC) $(FLAGS) -c todo.cpp -o todo.o

clean: 
	rm main *.o 