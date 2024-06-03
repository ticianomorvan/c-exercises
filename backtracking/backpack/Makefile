CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = backpack

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJECTS)
