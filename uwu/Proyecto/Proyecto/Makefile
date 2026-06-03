# Makefile sencillo para el proyecto

CC      = gcc
CFLAGS  = -Wall
TARGET  = programa

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe

.PHONY: run clean
