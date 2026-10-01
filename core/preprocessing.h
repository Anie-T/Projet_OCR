#ifndef PREPROCESSING_H
#define PREPROCESSING_H
#include <err.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "delete_color_picture.h"


//certaine struct utilisée ici et fonction évoqué sont définies dans delete_color_picture.h


//transforme des degrés en radian
double degrees_to_radian(double angle_degres);


//prend une struct d'image en noir et blanc et applique la rotation pour créé une nouvelle image à partir d'un angle 
//l'ancienne image doit être libérée si plus utilisée 
struct Image_bw *rotate_black_and_white(struct Image_bw *image_noir_et_blanc, double angle_radian);


//prend une struct d'image en noir et blanc et trouve l'angle à utiliser pour la rotation  
//appelle rotate_black_and_white une fois l'angle trouvé
struct Image_bw *auto_rotate_bw(const struct Image_bw *image_noir_et_blanc);


//retire les bruits parasites d'une image en noir et blanc 
int denoise_median_bw_inplace(struct Image_bw *image_bw);


//renforce les contrastes de l'image
//doit être utilisée sur une image grayscale (entre convert_to_grayscale() et convert_to_black_and_white)
int equalize_histogram(struct Image_bw *image_bw);

#endif // !PREPROCESSING_H

