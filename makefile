CC=gcc
CCFLAGS=-Wall
LDFLAGS=
SOURCES=$(wildcard src/*.c)
OBJECTS=$(SOURCES:.c=.o)
TARGET=app

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) 

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
