#include "../include/window.h"
#include <err.h>
#include <stdio.h>

void init_window(SDL_Window **window, SDL_Renderer **renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
        errx(EXIT_FAILURE, "SDL_init: %s", SDL_GetError());

    *window = SDL_CreateWindow("Projection", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        WINDOW_WIDTH, WINDOW_HEIGHT, 0) ; 
    if (*window == NULL)
        errx(EXIT_FAILURE, "SDL_CreateWindow :%s", SDL_GetError()) ;

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_SOFTWARE | SDL_RENDERER_PRESENTVSYNC) ;

    if (*renderer == NULL)
        errx(EXIT_FAILURE, "SDL_CreateRenderer :%s", SDL_GetError()) ;
}

void terminate(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_DestroyRenderer(renderer) ;
    SDL_DestroyWindow(window) ;
    SDL_Quit() ;
}
