#include "../include/images.h"
#include <err.h>
#include <SDL2/SDL.h>

SDL_Surface *load_image(const char *path)
{
    if (path == NULL)
        errx(EXIT_FAILURE, "load_image : NULL path") ;

    SDL_Surface *image = SDL_LoadBMP(path);

    if (image == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    return image;
}

SDL_Texture *load_texture(SDL_Renderer *renderer, const char *path)
{
    if (path == NULL)
        errx(EXIT_FAILURE, "load_texture : NULL path");

    if (renderer == NULL)
        errx(EXIT_FAILURE, "load_texture : NULL renderer");

    SDL_Surface *image = SDL_LoadBMP(path);

    if (image == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    if (texture == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    return texture;
}

void save_image(SDL_Surface *image, const char *path)
{
    if (path == NULL)
        errx(EXIT_FAILURE, "save_image : NULL path") ;

    if (image == NULL)
        errx(EXIT_FAILURE, "save_image : NULL image");

    if (SDL_SaveBMP(image, path) != 0)
        errx(EXIT_FAILURE, "%s", SDL_GetError());
}

Uint32 get_pixel(SDL_Surface *surface, int x, int y)
{
    if (surface == NULL )
        errx(EXIT_FAILURE, "get_pixel : NULL surface");
    
    if ((*(*surface).format).BytesPerPixel != 4)
        errx(EXIT_FAILURE, "get_pixel : surface->format != 4");

    if (x < 0 || x >= (*surface).w || y < 0 || y >= (*surface).h)
        errx(EXIT_FAILURE, "get_pixel : pixel coord is out of bound");

    int index = (*surface).pitch * y + x * 4 ; 
    Uint8 *pixel = (Uint8 *)(*surface).pixels + index; 
    return *(Uint32 *)pixel;
}

void set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    if (surface == NULL )
        errx(EXIT_FAILURE, "get_pixel : NULL surface");
    
    if ((*(*surface).format).BytesPerPixel != 4)
        errx(EXIT_FAILURE, "get_pixel : surface->format != 4");

    if (x < 0 || x >= (*surface).w || y < 0 || y >= (*surface).h)
        errx(EXIT_FAILURE, "get_pixel : pixel coord is out of bound");

    int index = (*surface).pitch * y + x * 4 ; 
    Uint8 *p = (Uint8 *)(*surface).pixels + index; 
    *(Uint32 *)p = pixel;
}

SDL_Surface *convert_grayscale(SDL_Surface *surface)
{
    if (surface == NULL )
        errx(EXIT_FAILURE, "convert_grayscale : NULL surface");

    SDL_Surface *grayscale = SDL_DuplicateSurface(surface);

    if (grayscale == NULL )
        errx(EXIT_FAILURE, "convert_grayscale : %s", SDL_GetError());

    int width = (*grayscale).w; 
    int height = (*grayscale).h;

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            Uint32 pixel = get_pixel(grayscale, x, y);
            Uint8 r, g, b;
            SDL_GetRGB(pixel, (*grayscale).format, &r, &g, &b);
            // SDL_GetRGB décompose un pixel en r, g, b selon le format de la surface. 
            // Il existe plusieurs formats, alors décomposé nous même pourrait ne pas marcher.
            Uint8 gray = 0.299 * r + 0.587 * g + 0.114 * b; 
            Uint32 pixel_gray = SDL_MapRGB((*grayscale).format, gray, gray, gray);
            // SDL_MapRGB reconstruit un pixel à partir de r, g, b et du format de la surface.
            set_pixel(grayscale, x, y, pixel_gray);
        }
    }
    return grayscale ;
}

//modifie l'image
SDL_Surface *convert_black_and_white(struct SDL_Surface *grayscale, Uint8 seuil)
{
    if (grayscale == NULL )
        errx(EXIT_FAILURE, "convert_black_and_white : NULL grayscale");

    SDL_Surface *black_white = SDL_DuplicateSurface(grayscale);

    if (black_white == NULL )
        errx(EXIT_FAILURE, "convert_black_and_white : %s", SDL_GetError());

    int width = (*black_white).w; 
    int height = (*black_white).h;

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            Uint32 pixel = get_pixel(black_white, x, y);
            Uint8 r, g, b;
            SDL_GetRGB(pixel, (*black_white).format, &r, &g, &b);
            if (r < seuil)
            {
                Uint32 pixel_black = SDL_MapRGB((*black_white).format, 0, 0, 0);
                set_pixel(black_white, x, y, pixel_black);
            }
            else
            {
                Uint32 pixel_white = SDL_MapRGB((*black_white).format, 255, 255, 255);
                set_pixel(black_white, x, y, pixel_white);
            }
        }
    }
    return black_white ;
}