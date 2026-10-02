#include "delete_color_picture.h"

//librairie image
#include "stb_image.h"
#include "stb_image_write.h"

struct Image *load_picture(const char *filepath_image)
{

    if (filepath_image == NULL)
    {
        fprintf(stderr, "ERREUR : chemin de fichier NULL (delete_color_picture.c)\n");
        return NULL;
    }

    int hauteur;
    int largeur;
    int channels;
    
    //renvoi un tableau avec le code rgb pour chacune des 3 couleurs pour chacun des pixels
    //[rouge_pixel1, vert_pixel1, bleu_pixel1, rouge_pixel2 ...]
    unsigned char *data = stbi_load(filepath_image, &largeur, &hauteur, &channels, 3);
    if(data == NULL)
    {
        fprintf(stderr, "ERREUR stbi_load sur '%s' : %s (delete_color_picture.c)\n", filepath_image, stbi_failure_reason());
        return NULL;
    }

    
    struct Image *image = malloc(sizeof(struct Image));
    if(image == NULL)
    {
        fprintf(stderr, "ERREUR : l'allocation de la struct Image a échoué (delete_color_picture.c)\n");
        stbi_image_free(data); //libère le tableau allouer par stbi_load
        return NULL;
    }

    image->hauteur = (size_t)hauteur;
    image->largeur = (size_t)largeur;
    image->taille_du_tableau = hauteur * largeur;
    
    struct tableau_rgb *tableau_rgb = malloc(sizeof(struct tableau_rgb)* (image->taille_du_tableau));
    if(tableau_rgb == NULL)
    {
        fprintf(stderr, "ERREUR : l'allocation du tableau RGB a échoué (delete_color_picture.c)\n");
        free(image);
        stbi_image_free(data); //libère le tableau allouer par stbi_load
        return NULL;
    }
    
    for(size_t i = 0; i < image->taille_du_tableau; i++)
    {
        tableau_rgb[i].rouge = data[i*3];  //le rouge est toute les 3 données dans data
        tableau_rgb[i].vert = data[i*3+1]; //ensuite le vert
        tableau_rgb[i].bleu = data[i*3+2]; //puis le bleu

    }

    image->tableau_pixel_rgb = tableau_rgb;
    stbi_image_free(data); //libère le tableau allouer par stbi_load
    return image;
}



struct Image_bw *convert_to_grayscale(const struct Image *image_rgb)
{
    if (image_rgb == NULL || image_rgb->tableau_pixel_rgb == NULL)
    {
        fprintf(stderr, "ERREUR : pointeur d'image source NULL (delete_color_picture.c)\n");
        return NULL;
    }

    struct Image_bw *image_grayscale = malloc(sizeof(struct Image_bw));
    if(image_grayscale == NULL)
    {
        printf("ERREUR : l'allocation de la struct Image_bw à échouer (delete_color_picture.c)\n");
        return NULL;
    }

    image_grayscale->hauteur = image_rgb->hauteur;
    image_grayscale->largeur = image_rgb->largeur;
    image_grayscale->taille_du_tableau = image_rgb->taille_du_tableau;
    
    unsigned char *tab_grayscale = malloc(sizeof(unsigned char)* image_grayscale->taille_du_tableau);
    if(tab_grayscale == NULL)
    {
        fprintf(stderr, "ERREUR : l'allocation du tableau grayscale a échoué (delete_color_picture.c)\n");
        free(image_grayscale);
        return NULL;
    }

    for(size_t i = 0; i < image_grayscale->taille_du_tableau; i++) //les 2 tableaux font la même taille
    {
        //applique la formule qui transforme le rgb en grayscale 
        tab_grayscale[i] = image_rgb->tableau_pixel_rgb[i].rouge * 0.2126 + image_rgb->tableau_pixel_rgb[i].vert * 0.7152 + image_rgb->tableau_pixel_rgb[i].bleu * 0.0722;
    }
    
    image_grayscale->tableau_noir_et_blanc = tab_grayscale; // ATTENTION: pour le moment le tableau est en grayscale pas encore en noir et blanc
    return image_grayscale;
}


struct Image_bw *convert_to_black_and_white(struct Image_bw *image_grayscale, unsigned char seuil)
{
    if (image_grayscale == NULL || image_grayscale->tableau_noir_et_blanc == NULL)
    {
        fprintf(stderr, "ERREUR : pointeur d'image grayscale NULL (delete_color_picture.c)\n");
        return NULL;
    }

    for(size_t i = 0; i < image_grayscale->taille_du_tableau; i++) 
    {
        //le seuil est généralement 128 (256/2) mais il peut être adapter pour avoir une image plus sombre ou plus clair
        if(image_grayscale->tableau_noir_et_blanc[i] >= seuil)
        {
            image_grayscale->tableau_noir_et_blanc[i] = 255; //blanc
        }
        else 
        {
            image_grayscale->tableau_noir_et_blanc[i] = 0; //noir
        }
    }
    return image_grayscale; //maintenant une image en noir et blanc
}



int write_picture(const struct Image_bw *image_noir_et_blanc, const char *name_file)
{
    if (image_noir_et_blanc == NULL || image_noir_et_blanc->tableau_noir_et_blanc == NULL || name_file == NULL)
    {
        fprintf(stderr, "ERREUR : paramètre NULL dans write_picture (delete_color_picture.c)\n");
        return -1;
    }
    
    //recréer l'image en noir et blanc à partir du tableau 
    //l'image créé est dans name_file
    int result = stbi_write_png(name_file, image_noir_et_blanc->largeur, image_noir_et_blanc->hauteur, 1, image_noir_et_blanc->tableau_noir_et_blanc, image_noir_et_blanc->largeur);
    
    if (result == 0) //erreur de stbi_write_png
    {
        fprintf(stderr, "ERREUR : échec de l'écriture de l'image '%s' (delete_color_picture.c)\n", name_file);
        return -1;
    }

    return 0;
}


//libère les structures allouer dynamiquement
void free_image(struct Image *image)
{
    if (image == NULL)
    {
        return;
    }
    if (image->tableau_pixel_rgb != NULL)
    {
        free(image->tableau_pixel_rgb);
    }
    free(image);
}

void free_image_bw(struct Image_bw *image_noir_et_blanc)
{
    if (image_noir_et_blanc == NULL)
    {
        return;
    }
    if (image_noir_et_blanc->tableau_noir_et_blanc != NULL)
    {
        free(image_noir_et_blanc->tableau_noir_et_blanc);
    }
    free(image_noir_et_blanc);
}







