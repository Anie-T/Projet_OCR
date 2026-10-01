CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla -fsanitize=address,undefined -g
SRC = neural_network.o


all: ${SRC}
	${CC} $^ -o main ${CFLAGS} 

%.o : %.c
	${CC} -c $< -o $@ ${CFLAGS}

clean:
	$(RM) main *.o

clean_all : clean
	$(RM) Makefile
