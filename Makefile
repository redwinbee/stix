# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wpedantic -g

# Define the target binary name
TARGET = stix

# Collect all .c files in the current directory
SRC = $(wildcard *.c)

# Generate object file names by replacing .c with .o
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compile .c files into .o object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
