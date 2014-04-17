CC = gcc
LD = gcc
CFLAGS = -Wall -c
INCLUS = -I.
LDPATH = -L.
LDFLAGS = -lpthread

#SRCS = $(wildcard *.c source/*.c)
#OBJS = $(patsubst %c, %o, $(SRCS))

SRCS = fork.c
OBJS = fork.o

TARGET = fork 
 
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD)  -o $@ $^ $(LDFLAGS)

%o: %c
	$(CC) $(LDPATH) $(LDFLAGS) $(INCLUS) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o $(TARGET)
