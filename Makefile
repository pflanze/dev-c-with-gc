main: main.c
	gcc -o main -Wall -O2 main.c

expansion.c: main.c
	gcc -E main.c | grep -v '^#' > expansion.c

expansion: expansion.c
	gcc -o expansion -Wall -O2 expansion.c

test: main
	tests/t1

