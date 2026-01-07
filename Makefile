CC      := gcc
AR      := ar
CFLAGS  := -std=c11 -Wall -Wextra -Wpedantic -Iinclude
ARFLAGS := rcs

SRC_DIR   := src
TEST_DIR  := tests
OBJ_DIR   := obj
TEST_BIN  := test_bin
LIB       := libcphys.a

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
TEST_BINS := $(patsubst $(TEST_DIR)/%.c,$(TEST_BIN)/%,$(TEST_SRCS))

.PHONY: all clean tests

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

tests: $(TEST_BINS)

$(TEST_DIR)/%.c: $(TEST_BIN)/%

$(TEST_BIN)/%: $(TEST_DIR)/%.c $(LIB) | $(TEST_BIN)
	$(CC) $(CFLAGS) $< -L. -lcphys -o $@

$(TEST_BIN):
	mkdir -p $(TEST_BIN)

clean:
	rm -rf $(OBJ_DIR) $(TEST_BIN) $(LIB)
