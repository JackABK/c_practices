#compiler 
CC = gcc 
LD = gcc
CFLAGS = -Wall -c 
SRCS = uart_read.c
OBJS = uart_read.o

INCLUS = -I.
LDPATH = -L.
LDFLAGS = -lpthread
TARGET = uart_read


.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)

%o: %c
	$(CC) $(LDPATH) $(LDFLAGS) $(INCLUS) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o $(TARGET)

