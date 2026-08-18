CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
SRC = src/main.c src/utils.c src/pointers_memory.c src/data_structures.c src/structs_unions.c src/function_pointers.c src/bitwise_ops.c src/file_io.c src/quiz.c
TARGET = c_education_intermediate

ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
    RM = del /Q /F
else
    RM = rm -f
endif

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	$(RM) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
