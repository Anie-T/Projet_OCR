#ifndef DELETE_COLOR_PICTURE_H
#define DELETE_COLOR_PICTURE_H
#include <err.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


//structure pour stocker le code RGB d'un pixel 
struct tableau_rgb {
  unsigned char rouge;
  unsigned char vert;
  unsigned char bleu;
};

//struct qui contient la taille de l'image et un tableau contenant la valeur RGB de chacun de ses pixels
struct Image {
  size_t largeur_image;
  size_t hauteur_image;
  struct tableau_rgb *tableau_pixel_rgb;
  size_t taille_du_tableau;
};

//struct qui contient la taille de l'image et un tableau contenant la valeur 0 ou 255 (noir ou blanc) pour chaque pixel 
// unsigned char est un int de 1 octet au lieu de 4 pour réduire l'usage de la RAM
struct Image_bw {
  size_t largeur_image;
  size_t hauteur_image;
  unsigned char *tableau_noir_et_blanc; //contient le tableau grayscale puis noir et blanc
  size_t taille_du_tableau;
};


// créé une struct Image contenant les dimensions de l'image et le tableau des valeur RGB de chacun des pixels ainsi que la taille du tableau. 
// prend en paramètre le chemin vers l'image 
struct Image *load_picture(char *filepath_image); 

//utilise la struct Image et son tableau RGB et attribue une valeur par pixel. 
//retourne une struct image_bw contenant le nouveau tableau de "niveaux de gris"
struct Image_bw *convert_to_grayscale(struct Image *image_rgb);


//transforme le tableau grayscale (en place) en tableau contenant des 0 (noir) et des 255 (blanc). 
//toute valeur supérieur ou égale au seuil deviens un 255 et toute valeur inférieure deviens un 0.
struct Image_bw *convert_to_black_and_white(struct Image_bw *image_grayscale, unsigned char seuil);


//reprend l'image en noir et blanc et la struct Image initiale pour recréer l'image en noir et blanc dans un fichier name_file 
int write_picture(struct Image_bw *image_noir_et_blanc, struct Image *image, char *name_file);


//libère la mémoire allouée par la struct image et le tableau rgb
int free_image(struct Image *image);

//libère la mémoire allouée par le tableau noir et blanc et la struct Image_bw elle-même
int free_image_bw(struct Image_bw *image_noir_et_blanc);


#endif // !DELETE_COLOR_PICTURE_H
