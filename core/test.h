#ifndef TEST_H
#define TEST_H
#include "neural_network.h"
#include "solver.h"

// Prend le nom d'un test et la fonction de test
// La fonction de test ne prend pas d'argument
// La fonction de test doit retourner 0 en cas de succées
// La fonction de test doit retourner 1 en cas d'échec
int exit_test(const char *name, int (*test_func)(void));

// return 0 if the result matches the expectation, 1 otherwise
int check_word(char **grid, size_t rows, size_t cols, const char *word, int found, int x0, int y0, int x1, int y1);
int test_solver_words(void);

#endif // !TEST_H