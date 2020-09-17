CC = gcc 
LD = gcc
FLAGS = -O2 -g -Wall -fmessage-length=0
OUTSDIR = bin

#find all c files in folder
SRCS = $(wildcard src/*.c)
OBJS = $(patsubst %c, %o, $(SRCS))

TARGET = bin/main

.PHONY: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)
	rm -f $(OBJS)

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS) $(TARGET)