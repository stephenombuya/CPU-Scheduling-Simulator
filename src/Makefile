CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = scheduler

all: $(TARGET)

$(TARGET): scheduler.c
	$(CC) $(CFLAGS) -o $(TARGET) code.c

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
