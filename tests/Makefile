# Compiler and flags
CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -I../include

# Source files
TEST_SOURCES := test_crypt_utils.c
APP_SOURCES := ../src/crypt_utils.c  # Include application source files here

# Object files
TEST_OBJECTS := $(TEST_SOURCES:.c=.o)
APP_OBJECTS := $(APP_SOURCES:.c=.o)

# Executable name
TEST_EXECUTABLE := test_crypt_utils

# Libraries
LIBS := -lcmocka

# Targets
all: $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_OBJECTS) $(APP_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJECTS) $(APP_OBJECTS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TEST_OBJECTS) $(APP_OBJECTS) $(TEST_EXECUTABLE)

.PHONY: all clean
