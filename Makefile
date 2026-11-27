CC      ?= cc
CFLAGS  ?= -std=c11 -O2 -Wall -Wextra -Wpedantic
LDLIBS  := -lm

BIN     := usual-problems
TESTBIN := test-problems

.PHONY: all run test clean

all: $(BIN)

$(BIN): src/main.c src/problems.c src/problems.h
	$(CC) $(CFLAGS) -o $@ src/main.c src/problems.c $(LDLIBS)

$(TESTBIN): tests/test_problems.c src/problems.c src/problems.h
	$(CC) $(CFLAGS) -o $@ tests/test_problems.c src/problems.c $(LDLIBS)

run: $(BIN)
	./$(BIN)

test: $(TESTBIN)
	./$(TESTBIN)

clean:
	rm -f $(BIN) $(TESTBIN)
