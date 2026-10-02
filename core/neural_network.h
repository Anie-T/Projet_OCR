#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H
#include <err.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Layer
{
    size_t input_size;
    // nombre de lien vers la couche
    // (nb neurone couche * nb neurone couche précédente)
    size_t output_size; //
    // nombre de neurone sur la couche

    float *weight;
    // représentation linéaire d'un tableau
    // weights[i * output_size + j] pour accéder au j-ieme poids du i-ieme neurone
    float *bias;
    // list des biais des neurone de la couche

    float *outputs;
    // valeur des neurones de la couche
};

struct Network
{
    struct Layer *layers;
    // liste des couches du réseau
    // layers[0] = couche d'entré ; layer[layer_count - 1] = couche de sortie
    size_t layer_count;
    // nombre de couche du réseau
};

// pour toute les fonctions : retourne -1 ou NULL en cas d'erreure

// alloue la mémoire pour un réseau
// prend la liste du nombre de neurone par couche et la nombre de couche
struct Network *init_network(size_t *neurone_count_per_layer, size_t layer_count);

// alloue la mémoire pour une couche
// prends le nombre de neurone de la couche
struct Layer *init_layer(size_t neurone_count);

// charge un réseau depuis un fichier
// La première ligne du fichier est consacrée au métadonnée (nombre de couche)
// Les lignes suivante représentent les couches.
struct Network *load_network(char *filename);

// transforme une chaine de caractère en couche initialisé
struct Layer *load_layer(char *layer_inline);

int set_layer_inputs(float *weight, size_t input_size);
int set_layer_ouputs_bias(float *bias);
int set_layer_ouputs(float *outputs);
int set_network_inputs(float *inputs_value);
int compute_neuron_output(struct Layer *layer, size_t neuron_rank);
int compute_layer_ouputs(struct Layer *layer);

// calcule les états de toute les couches et retourne la liste des valeurs de la couche de sortie
float *compute_network_outputs(struct Network *network);

int free_layer(struct Layer *layer);
int free_network(struct Network *network);

#endif // !NEURAL_NETWORK_H
