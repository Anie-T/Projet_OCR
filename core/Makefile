CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla -fsanitize=address,undefined -g
SRC_C = neural_network.c main.c
SRC_O = neural_network.o


all: ${SRC_O}
	${CC} $^ -o main ${CFLAGS} 

compile : 
	${CC} ${SRC_C} -o main

%.o : %.c
	${CC} -c $< -o $@ ${CFLAGS}

clean:
	$(RM) main *.o
