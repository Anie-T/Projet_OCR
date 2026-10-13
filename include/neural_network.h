#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H
#include <err.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/*
*/
struct Network
{
    // total number of neurone in network 
    size_t neurone_count ;
    // array of neurone's value of network
    double *neurones_value ;
    // array of neurone's bias of network
    double *neurones_bias ;
    // total number of layer in network 
    size_t layer_count ;
    // array of neurone's count in each layer from network
    size_t *layers ;
    // array of edge's weight from network
    double *edge ;
};

// network function return -1 nor NULL in error case

/* malloc a network
take a list of each neurone count in each layer and the layer count 
return pointer to network*/
struct Network *create_network(size_t *layer, size_t layer_count);

/* malloc a network from a file
take filename
return pointer to network*/
struct Network *load_network(char *filename);

/* save a network in a file
take filename
return pointer to network*/
struct Network *save_network(struct Network *network, char *filename);

/* free network's array, then free network
return -1 in error*/
int free_network(struct Network *network);

/* init the first layer of a network with given values
take a network, an array of value and the size of the array
trigger an error if values array to short*/
int set_network_inputs(struct Network *network, double *values);
/* return an array fill with the value of neurons' last layer
take a network*/
float *get_network_outputs(struct Network *network);

//set the bias of all neurone in the  network
int set_all_neurone_bias(struct Network *network, double *bias) ;
//set the bias of a layer of neurone in the network
int set_layer_neurone_bias(struct Network *network, size_t layer, double *bias) ;
//set the bias of one neurone
int set_one_neurone_bias(struct Network *network, size_t layer, size_t neuron_rank, double bias) ;

//set the values of all neurone in the  network
int set_all_neurone_values(struct Network *network, double *values, size_t input_size) ;
//set the values of a layer of neurone in the network
int set_layer_neurone_values(struct Network *network, double *values, size_t input_size) ;
//set the value of one neurone
int set_one_neurone_value(struct Network *network, size_t layer, size_t neuron_rank, double value) ;

double *get_neurone_value(struct Network *network, size_t layer, size_t neuron_rank) ;
double *get_neurone_bias(struct Network *network, size_t layer, size_t neuron_rank) ;

// compute the value of one neurone
int compute_neuron_value(struct Network *network, size_t layer, size_t neuron_rank);
/*compute the value of each neurone of a layer*/
int compute_layer_value(struct Network *network, size_t layer);
/*compute the value of each neurone of a network*/
int compute_layer_value(struct Network *network, size_t layer);


int set_layer_ouputs_bias(float *bias);
int set_layer_ouputs(float *outputs);




#endif // !NEURAL_NETWORK_H
