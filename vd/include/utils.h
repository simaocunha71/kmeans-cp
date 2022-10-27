#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N_SAMPLES 10000000
#define K_CLUSTERS 4

/**
 * @brief Create a int array
 * @param size Array size
 * @return int* Array allocated
 */
int* create_iarray(int size);

/**
 * @brief Create a int array
 * @param size Array size
 * @return float* Array allocated
 */
float* create_farray(int size);



void fill(float* space_x,float* space_y, float* clusters_x,float* clusters_y, int* samples_id);

float euclidian_distance(float x1, float y1, float x2, float y2);


int update_clusters(float* space_x,float* space_y, float* clusters_x,float* clusters_y, int* samples_id, int* clusters_npoints);

int has_converged(int* samples_id_old, int* samples_id);

void print_output(float* clusters_x,float* clusters_y,int* clusters_npoints, int iterations);