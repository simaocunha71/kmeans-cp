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
 * @brief Create a POINT vector
 * @param size Vector size
 * @return POINT* Vector allocated
 */
POINT* create_vector(int size);

/**
 * @brief Fill sample's space and clusters with random values according with a certain seed and calculus
 * @param space Sample's space (POINT vector)
 * @param clusters Clusters' vector (POINT vector)
 * @param samples_id Int array with cluster ID that each point is associated to (initialized with -1)
 */
void fill(POINT* space, POINT* clusters, int* samples_id);

/**
 * @brief Update clusters and checks if the clusters are the same
 * @param space Sample's space (POINT vector)
 * @param clusters Clusters' vector (POINT vector)
 * @param samples_id Int array with cluster ID that each point is associated to
 * @param clusters_npoints Number of points associated to each cluster
 * @return int 1 if converged, 0 otherwise
 */
int update_clusters(POINT* space, POINT* clusters, int* samples_id, int* clusters_npoints);

/**
 * @brief Print the output desired by the teachers
 * @param clusters Clusters' vector (POINT vector)
 * @param clusters_npoints Number of points associated to each cluster
 * @param iterations Iterations done by the algorithm
 */
void print_output(POINT* clusters,int* clusters_npoints, int iterations);