#include <stdio.h>
#include <stdlib.h>

#define N_SAMPLES 10000000
#define K_CLUSTERS 4

/**
 * @brief Create a int array
 * @param size Array size
 * @return float* Array allocated
 */
float* create_farray(int size);

/**
 * @brief Create a int array
 * @param size Array size
 * @return int* Array allocated
 */
int* create_iarray(int size);

/**
 * @brief Fill sample's space and clusters with random values according with a certain seed and calculus
 * @param space Sample's space
 * @param clusters Clusters' vector
 */
void fill(float* space_x, float* space_y, float* clusters_x, float* clusters_y);

/**
 * @brief Assign each point of space data to a certain cluster:
 * It calculates euclidian distance between data point and cluster and assigns point to the closest cluster (minimum distance)
 * Also, it calculates new centroids
 * @param space Point vector
 * @param clusters Cluster vector
 * @param clusters_npoints Array with numberOfPoints values from clusters
 * @return int 1 if clusters not updated, 0 otherwise
 */
int update_clusters(float* space_x, float* space_y, float* clusters_x, float* clusters_y, int* clusters_npoints);

/**
 * @brief Print the output desired by the teachers
 * @param clusters Clusters' vector
 * @param clusters_npoints Array with numberOfPoints values from clusters
 * @param iterations Iterations done while calculating centroids and assigment data values in a loop
 */
void print_output(float* clusters_x, float* clusters_y, int* clusters_npoints, int iterations);