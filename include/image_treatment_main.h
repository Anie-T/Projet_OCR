#ifndef IMAGE_TREATMENT_MAIN
#define IMAGE_TREATMENT_MAIN
#include <err.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


//Cette fonction va servir de main pour les fonctions de traitements d'images
//elle appellera les fonctions pour convertir l'image en noir et blanc et celle de preprocessing
//il suffira d'appeller cette fonction pour effectuer le traitement


int main_preprocessing(char *filepath_image_source, char *filepath_image_res);

#endif // !IMAGE_TREATMENT_MAIN
