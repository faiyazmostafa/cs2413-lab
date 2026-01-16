CC ?= cc
CFLAGS = -std=c11 -Wall -Wextra -O2 -I./src

BIN_DIR = bin
TARGET  = $(BIN_DIR)/two_sum_run

SRC  = src/two_sum.c
MAIN = tests/test_two_sum.c

.PHONY: all run run_nobench clean

all: $(TARGET)

# Default build: benchmark ON
$(TARGET): $(SRC) $(MAIN) src/two_sum.h
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -DBENCHMARK=1 $(SRC) $(MAIN) -o $(TARGET)

# make run -> benchmark ON
run: $(TARGET)
	./$(TARGET)

# make run_nobench -> benchmark OFF
run_nobench:
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -DBENCHMARK=0 $(SRC) $(MAIN) -o $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BIN_DIR)
