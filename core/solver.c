#include "solver.h"


char **load_grid(const char *path, size_t *rows, size_t *cols)
{
    return NULL;
}

void free_grid(char **grid, size_t rows)
{
    return;
}

static int check_direction(char **grid, size_t rows, size_t cols, const char *word, int x, int y, int dx, int dy)
{
    return -1;
}

struct match solve_word(char **grid, size_t rows, size_t cols, const char *word)
{
    struct match result = { 0, { 0, 0 }, { 0, 0 } };
    return result;
}