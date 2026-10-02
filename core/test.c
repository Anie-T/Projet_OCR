#include "test.h"

int exit_test(const char *name, int (*test_func)(void))
{
    int result = test_func();
    if (result == 0)
    {
        printf("[OK] %s\n", name);
    }
    else
    {
        printf("[FAIL] %s\n", name);
    }
    return result;
}

int test_addition(void)
{
    return 0; // succès
}

int test_division(void)
{
    return 1; // échec
}

int main(void)
{
    int fail = 0;
    fail += exit_test("test_success_addition", test_addition);
    fail += exit_test("test_failure_division", test_division);
    if (fail != 0)
    {
        printf("[%i] test ont échoué\n", fail);
    }
    else
    {
    }
    return 1;
}