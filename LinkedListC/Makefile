CC      := gcc
CFLAGS  := -Wall -Iinclude -g

SOURCES := main.c LinkedList.c
OBJECTS := $(SOURCES:.c=.o)
TARGET  := LL

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
