#include "delete_color_picture.h"


//Ce fichier va servir de main pour les fonctions de traitements d'images
//il appellera les fonctions pour convertir l'image en noir et blanc et celle de preprocessing
//il suffira d'appeller cette fonction pour effectuer le traitement


int main_preprocessing(char *filepath_image_source, char *filepath_image_res)
{
    struct Image *image = load_picture(filepath_image_source);
    if(image == NULL)
    {
        fprintf(stderr, "ERREUR : load_picture a échoué pour %s\n", filepath_image_source);
        return -1;
    }
    struct Image_bw *image_bw = convert_to_grayscale(image);
    if(image_bw == NULL)
    {
        fprintf(stderr, "ERREUR : convert_to_grayscale a échoué.\n");
        free_image(image); // Libération avant de quitter
        return -1;
    }
    if(convert_to_black_and_white(image_bw, 128) == NULL)
    {
        fprintf(stderr, "ERREUR : convert_to_black_and_white a échoué.\n");
        free_image(image);
        free_image_bw(image_bw);
        return -1;
    }

    if(write_picture(image_bw, filepath_image_res) != 0)
    {
        fprintf(stderr, "ERREUR : write_picture a échoué pour %s\n", filepath_image_res);
        free_image(image);
        free_image_bw(image_bw);
        return -1;
    }

    free_image(image);
    free_image_bw(image_bw);

    printf("Prétraitement terminé avec succès -> %s\n", filepath_image_res); //temporaire pour les tests
    return 0;
}

//temporaire pour tester la fonction
int main()
{
    return main_preprocessing("core/test_image.png", "test_res.png"); //fichier à transformer, nom du fichier final
}
