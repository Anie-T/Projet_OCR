#ifndef PREPROCESSING_H
#define PREPROCESSING_H
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
  
};

// créé une struct Image contenant les dimensions de l'image et le tableau des valeur RGB de chacun des pixels. 
// prend en paramètre le chemin vers l'image et un pointeur qui contiendra la taille du tableau (mis à jour par la fonction)
struct Image *load_picture(char *filepath_image, size_t *taille_du_tableau); 

//utilise le tableau RGB de la struct Image et attribue 1 valeur par pixel. retourne un nouveau tableau de "niveaux de gris"
// unsigned char est un int de 1 octet au lieu de 4 pour réduire l'usage de la RAM
unsigned char *convert_to_grayscale(struct tableau_rgb *tableau_pixel_rgb, size_t taille_du_tableau);


//récupère le tableau grayscale et le transforme (en place) en tableau contenant des 0 (noir) et des 255 (blanc). 
//toute valeur supérieur ou égale au seuil deviens un 255 et toute valeur inférieure deviens un 0.
unsigned char *convert_to_black_and_white(unsigned char *tableau_grayscale, unsigned char seuil, size_t taille_du_tableau);


//reprend le tableau noir et blanc, sa taille et la struct Image initiale pour recréer l'image en noir et blanc dans un fichier name_file 
int write_picture(unsigned char *tableau_noir_et_blanc, size_t taille_du_tableau, char *name_file, struct Image *image);


//libère la mémoire allouée par la struct image, appelle free_tableau_rgb si nécessaire
int free_image(struct Image *image, size_t taille_du_tableau);

//libère la mémoire allouée par le tableau noir et blanc
int free_tableau_noir_et_blanc(unsigned char *tableau_noir_et_blanc, size_t taille_du_tableau);


#endif // !PREPROCESSING_H
