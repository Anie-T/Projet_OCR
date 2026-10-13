#ifndef IMAGES_H
#define IMAGES_H

#include <SDL2/SDL.h>

SDL_Surface *load_image(const char *path);
void save_image(SDL_Surface *image, const char *path);
Uint32 get_pixel(SDL_Surface *surface, int x, int y);
void set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
SDL_Surface *convert_grayscale(SDL_Surface *surface);
SDL_Surface *convert_black_and_white(struct SDL_Surface *grayscale, Uint8 seuil);

#endif /* ! IMAGES_H */
