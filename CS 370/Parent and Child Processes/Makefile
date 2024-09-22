CC = gcc
CFLAGS = -Wall -g

FILES=Generator.c Fibonacci.c Perrin.c Composite.c

all: Generator Fibonacci Perrin Composite

Generator: Generator.c
	$(CC) $(CFLAGS) -o Generator Generator.c

Fibonacci: Fibonacci.c
	$(CC) $(CFLAGS) -o Fibonacci Fibonacci.c

Perrin: Perrin.c
	$(CC) $(CFLAGS) -o Perrin Perrin.c

Composite: Composite.c
	$(CC) $(CFLAGS) -o Composite Composite.c

clean:
	rm -f Generator Fibonacci Perrin Composite

# Command to prepare the submission
zip:
	zip -rv Nathan-Kopacz-HW2.zip $(FILES) Makefile README.txt