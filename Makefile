cc = gcc
ncc = x86_64-w64-mingw32-gcc
flags = -Wall -lpthread -Iinclude -g

all : obj main

obj : mkdir -p obj

main : obj/file.o  obj/encoder.o obj/main.o 
	$(cc) obj/file.o obj/encoder.o obj/main.o $(flags) -o main


obj/main.o : src/main.c include/file.h include/encoder.h include/thread.h
	$(cc) -c src/main.c $(flags) -o obj/main.o

obj/file.o : src/file.c include/file.h
	$(cc) -c src/file.c $(flags) -o obj/file.o

obj/thread.o : src/thread.c include/thread.h
	$(cc) -c src/thread.c $(flags) -o obj/thread.o

obj/encoder.o : src/encoder.c include/encoder.h
	$(cc) -c src/encoder.c $(flags) -o obj/encoder.o

clean :
	rm obj/*.o











