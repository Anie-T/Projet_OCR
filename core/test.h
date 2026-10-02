#ifndef TEST_H
#define TEST_H
#include "neural_network.h"

// Prend le nom d'un test et la fonction de test
// La fonction de test ne prend pas d'argument
// La fonction de test doit retourner 0 en cas de succées
// La fonction de test doit retourner 1 en cas d'échec
int exit_test(const char *name, int (*test_func)(void));

#endif // !TEST_H