CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = where_to_refuel 

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJECTS)
