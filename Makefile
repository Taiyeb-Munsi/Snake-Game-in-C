
PROJECT_NAME = tictactoe

CC = gcc
CFLAGS = -Wall -Iinclude

LIBS = -lncurses

SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

TARGET = $(BIN_DIR)/$(PROJECT_NAME)

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) $(LIBS) -o $@
	@echo "Build successful! Executable: $@"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Cleaned build files."

.PHONY: all clean

