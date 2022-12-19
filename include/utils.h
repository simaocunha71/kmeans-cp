#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

#define N_SAMPLES 10000000
#define K_CLUSTERS 4

/**
 * @brief Point struct
 */
typedef struct point {
    float x; //Value of x
    float y; //Value of y
} POINT;

/**
 * @brief Create a int array
 * @param size Array size
 * @return int* Array allocated
 */
int* create_iarray(int size);

/**
 * @brief Create a vector object
 * @param size Vector size
 * @return POINT* Vector allocated
 */
POINT* create_vector(int size);


/**
 * @brief Fill sample's space and clusters with random values according with a certain seed and calculus
 * @param space Sample's space
 * @param clusters Clusters' vector
 */
void fill(POINT* space, POINT* clusters, int* samples_id);

int assign_points(POINT* space, POINT* clusters, int* samples_id, int* clusters_npoints, float* sumX, float* sumY, int world_size);

void compute_new_centroids(POINT* clusters,  int* clusters_npoints, float* sumX, float* sumY);

int has_converged(int* samples_id_old, int* samples_id);

void print_output(POINT* clusters,int* clusters_npoints, int iterations);