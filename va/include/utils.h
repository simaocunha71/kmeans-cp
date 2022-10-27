#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
void fill(POINT* space, POINT* clusters);

/**
 * @brief Calculates euclidian distance between two points.
 * Each point is represented by the struct POINT
 * @param p1 Point 1
 * @param p2 Point 2
 * @return float Distance between Point 1 and Point 2
 */
float euclidian_distance(POINT p1, POINT p2);


void update_clusters(POINT* space, POINT* clusters, int* samples_id, int* clusters_npoints);

int has_converged(int* samples_id_old, int* samples_id);

void copy_samplesid(int* samples_id, int* samples_id_to_copy);


void print_output(POINT* clusters,int* clusters_npoints, int iterations);