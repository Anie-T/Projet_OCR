CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla -fsanitize=address,undefined -g -lm
SRC_C = neural_network.c 
SRC_O = neural_network.o

main: ${SRC_O}
	${CC} $^ main.c -o main ${CFLAGS} 

test: ${SRC_O}
	${CC} $^ test.c -o test ${CFLAGS} 

mainOF :  # Compile un main Sans flag
	${CC} ${SRC_C} main.c -o main

testOF : # Compile un test Sans flag
	${CC} ${SRC_C} test.c -o test

%.o : %.c
	${CC} -c $< -o $@ ${CFLAGS}

clean:
	$(RM) main test *.o
