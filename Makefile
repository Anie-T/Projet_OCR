CC ?= gcc
CPPFLAGS := $(shell sdl2-config --cflags)
CFLAGS = -Wall -Wextra -Wvla -Werror -std=c99 -pedantic -I..
LDLIBS := $(shell sdl2-config --libs)

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

TARGET = OCR
TEST = test

all: $(TARGET) $(TEST)

$(TARGET): main.o $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(TEST): test.o $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

check: $(TEST)
	./$(TEST)

clean:
	$(RM) $(TARGET) $(TEST) main.o test.o $(OBJS)

.PHONY: all check clean