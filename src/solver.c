#include "../include/solver.h"


char **load_grid(const char *path, size_t *rows, size_t *cols)
{
    (void)path ;
    (void)rows ;
    (void)cols ;
    return NULL;
}

void free_grid(char **grid, size_t rows)
{
    (void)grid ;
    (void)rows ;
    return;
}

int check_direction(char **grid, size_t rows, size_t cols, const char *word, int x, int y, int dx, int dy)
{
    (void)grid ;
    (void)rows ;
    (void)cols ;
    (void)word ;
    (void)x ;
    (void)y ;
    (void)dx ;
    (void)dy ;
    return -1;
}

struct match solve_word(char **grid, size_t rows, size_t cols, const char *word)
{
    (void)grid ;
    (void)rows ;
    (void)cols ;
    (void)word ;
    struct match result = { 0, { 0, 0 }, { 0, 0 } };
    return result;
}