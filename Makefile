CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = mypreprocessor
SOURCES = preprocessor.c comment_removal.c macro_handler.c file_inclusion.c
OBJECTS = $(SOURCES:.c=.o)
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) temp.c output.i

.PHONY: all clean
