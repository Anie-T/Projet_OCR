#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// position of a cell in the grid [(0,0) is the top left]
struct position
{
    int x;
    int y;
};

// result of a word search
struct match
{
    int found;              // 1 if the word was found, 0 otherwise
    struct position start;  // position of the first letter
    struct position end;    // position of the last letter
};

// loads a grid from a text file
// returns an array of rows (strings)
// fills *rows and *cols
// returns NULL on error
char **load_grid(const char *path, size_t *rows, size_t *cols);

// frees a grid returned by load_grid
void free_grid(char **grid, size_t rows);

// searches a word in the grid in the 8 directions
// the search is case insensitive
struct match solve_word(char **grid, size_t rows, size_t cols, const char *word);

#endif // !SOLVER_H