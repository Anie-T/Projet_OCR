#include "include/solver.h"
#include "include/neural_network.h"
#include "include/images.h"
#include "include/window.h"
#include <SDL2/SDL.h>

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

//test décoloration image
int test_decoloration(void)
{    
    SDL_Window *window ;
    SDL_Renderer *renderer ;

    init_window(&window, &renderer) ;

    char image_path[] = ".image/test_image.bmp" ;
    Uint8 seuil = 128 ;

    struct SDL_Surface *origin_image = load_image(image_path);
    struct SDL_Surface *grayscale_image = convert_grayscale(origin_image);
    struct SDL_Surface *black_white_image = convert_black_and_white(origin_image, seuil);
    save_image(grayscale_image, ".image/test_grayscale.png") ;
    save_image(black_white_image, ".image/test_black_white.png") ;
    printf("test_decoloration : grayscale_image as .image/test_grayscale.png\n") ;
    printf("test_decoloration : black_white_image as .image/test_black_white.png\n") ;

    SDL_FreeSurface(origin_image) ;
    SDL_FreeSurface(grayscale_image) ;
    SDL_FreeSurface(black_white_image) ;

    terminate(window, renderer) ;
    return 0 ;
}

int main(void)
{
    int fail = 0;
    fail += exit_test("test_success_addition", test_addition);
    fail += exit_test("test_failure_division", test_division);
    fail += exit_test("test_solver_words", test_solver_words);
    fail += exit_test("test_decoloration", test_decoloration);

    if (fail != 0)
        printf("[%i] test ont échoué\n", fail);
    else
        printf("Tous les tests ont réussit") ;
    return 1;
}
