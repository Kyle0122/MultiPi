CC = clang
LD = clang
FLAGS = -O3 -Wall -fmessage-length=0 
# -I指定头文件目录
INCLUDE = -I./include
#Output directry
OUTPUTDIR = bin

#find all c files in folder
SRCS = $(wildcard src/*.c)
OBJS = $(patsubst %c, %o, $(SRCS))

TARGET = $(OUTPUTDIR)/main

.PHONY: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)
	rm -f $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $^ -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

getpic:
	gprof -q bin/main gmon.out  |gprof2dot|dot -Tpng -o time.png