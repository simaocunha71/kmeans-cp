#include <stdio.h>
#include <stdlib.h>

#define MAX_DIST 10
#define N_SAMPLES 10000000
#define K_CLUSTERS 4

/**
 * @brief Create a float array
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
 * @brief Fill all the arrays with random values according with a certain seed and calculus
 * @param space Array with values from space data
 * @param clusters Array with values from clusters
 */
void fill(float* space, float* clusters);

/**
 * @brief Calculates euclidian distance between two points.
 * Each point is represented by two floats - one refers to x axis value and the other refers to y axis value
 * @param p1_x First point x value
 * @param p1_y First point y value
 * @param p2_x Second point x value
 * @param p2_y Second point y value
 * @return float Euclidian distance between two points
 */
float euclidian_distance(float p1_x, float p1_y, float p2_x, float p2_y);

/**
 * @brief Assign each point of space data to a certain cluster:
 * It calculates euclidian distance between data point and cluster and assigns point to the closest cluster (minimum distance)
 * @param space Array with values from space data
 * @param clusters Array with values from clusters
 * @param clusters_npoints Array with numberOfPoints values from clusters
 */
void assign_cluster(float* space, float* clusters, int* clusters_npoints);

/**
 * @brief Checks if the centroids of the clusters are the same between consecutive iterations
 * @param clusters_old Previous clusters' version
 * @param clusters_new New clusters' version
 * @return int 1 if true, 0 otherwise
 */
int compare_centroids(float* clusters_old, float* clusters_new);

/**
 * @brief Copy each clusters' arrays to new ones
 * @param clusters Copy of new clusters' version
 * @param clusters_tocopy Copy of previous clusters' version
 */
void copy_clusters(float* clusters, float* clusters_tocopy);

/**
 * @brief Print the output desired by the teachers
 * @param clusters Array with values from clusters
 * @param clusters_npoints Array with numberOfPoints values from clusters
 * @param iterations Iterations done while calculating centroids and assigment data values in a loop
 */
void print_output(float* clusters, int* clusters_npoints, int iterations);