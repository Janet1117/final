build = $(wildcard build/*.o)

.PHONY: main

main: main.o
	gcc $(build) -o bin/main -lm

main.o:
	gcc -c src/main.c -o build/main.o
