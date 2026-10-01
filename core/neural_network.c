#include "neural_network.h"

/* Les spécifications de fonction sont dans le header*/

struct Network *init_network(size_t *neurone_count_per_layer, size_t layer_count)
{
    return NULL;
}

struct Layer *init_layer(size_t neurone_count)
{
    return NULL;
}

struct Network *load_network(char *filename)
{
    return NULL;
}

struct Layer *load_layer(char *layer_inline)
{
    return NULL;
}

int set_layer_inputs(float *weight, size_t input_size)
{
    return -1;
}

int set_layer_ouputs_bias(float *bias)
{
    return -1;
}

int set_layer_ouputs(float *outputs)
{
    return -1;
}

int set_network_inputs(float *inputs_value)
{
    return -1;
}

int compute_neuron_output(struct Layer *layer, size_t neuron_rank)
{
    return -1;
}

int compute_layer_ouputs(struct Layer *layer)
{
    return -1;
}

float *compute_network_outputs(struct Network *network)
{
    return NULL;
}

int free_layer(struct Layer *layer)
{
    return -1;
}

int free_network(struct Network *network)
{
    return -1;
}
