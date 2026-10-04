#include "test.h"
#include "delete_color_picture.h"
#include "preprocessing.h"
#include "image_treatment_main.h" 

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


int check_word(char **grid, size_t rows, size_t cols, const char *word, int found, int x0, int y0, int x1, int y1)
{
    struct match m = solve_word(grid, rows, cols, word);

    if (m.found != found)
        return 1;

    if (found && (m.start.x != x0 || m.start.y != y0 || m.end.x != x1 || m.end.y != y1))
        return 1;

    return 0;
}


int test_solver_words(void)
{
    char *grid[] =
    {
        "HORIZONTAL",
        "DXRAHCLBGA",
        "DIKCILEOKC",
        "IGAJHYLYHI",
        "HGFGODTIOT",
        "GDLROWKBFR",
        "PLNRDNERGE",
        "JHAIDUAJGV",
        "UKGFFOLLEH"
    };
    size_t rows = 9;
    size_t cols = 10;
    int fail = 0;

    fail += check_word(grid, rows, cols, "horizontal", 1, 0, 0, 9, 0);
    fail += check_word(grid, rows, cols, "vertical", 1, 9, 7, 9, 0);
    fail += check_word(grid, rows, cols, "diagonal", 1, 0, 1, 7, 8);
    fail += check_word(grid, rows, cols, "find", 1, 4, 8, 1, 5);
    fail += check_word(grid, rows, cols, "hello", 1, 9, 8, 5, 8);
    fail += check_word(grid, rows, cols, "world", 1, 5, 5, 1, 5);
    fail += check_word(grid, rows, cols, "goldorak", 1, 8, 1, 1, 8);
    fail += check_word(grid, rows, cols, "testdelamort", 0, 0, 0, 0, 0);

    return fail != 0;
}

int main(void)
{
    int fail = 0;
    fail += exit_test("test_success_addition", test_addition);
    fail += exit_test("test_failure_division", test_division);
    fail += exit_test("test_solver_words", test_solver_words);
    
    //test décoloration image
    fail += main_preprocessing("core/test_image.png", "test_res.png"); //fichier à transformer, nom du fichier final
    if (fail != 0)
    {
        printf("[%i] test ont échoué\n", fail);
    }
    else
    {
    }
    return 1;
}
