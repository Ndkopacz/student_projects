CC=gcc
CFLAGS=-Wall -g

FILES=Driver.c Primes.c
OUT_EXE=Driver

TEST_FILES=test_primes.c
TEST_EXEC=Test
LDFLAGS=-lcheck

# This is the default make target
all: $(OUT_EXE)

# The command to build the project
$(OUT_EXE): $(FILES)
	$(CC) $(CFLAGS) -o $(OUT_EXE) $(FILES)

# The command to run a test to check for project functionality
test: $(TEST_FILES)
	$(CC) $(CFLAGS) -o $(TEST_EXEC) $(TEST_FILES) $(LDFLAGS)
	./$(TEST_EXEC)

# Command to remove all compiled files
clean:
	rm -f $(OUT_EXE) *.o

# Command to prepare the submission
zip:
	zip -cvzf Nathan-Kopacz-HW1.tar $(FILES) Primes.h Makefile README.txt