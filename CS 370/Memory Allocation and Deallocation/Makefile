CC=gcc
CFLAGS=-Wall -g

FILES=Driver.c Primes.c
OUT_EXE=Driver

TEST_FILES=test_primes.c
TEST_EXEC=Test
FLAGS=-lm

# This is the default make target
all: $(OUT_EXE)

# The command to build the project
$(OUT_EXE): $(FILES)
	$(CC) $(CFLAGS) $(FLAGS) -o $(OUT_EXE) $(FILES)

# Command to remove all compiled files
clean:
	rm -f $(OUT_EXE) *.o

# Command to prepare the submission
zip:
	zip -rv Nathan-Kopacz-HW1.zip $(FILES) Primes.h Makefile README.txt