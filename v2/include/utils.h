#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DIST 10

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
 * @param space_x Array with x values from space data
 * @param space_y Array with y values from space data
 * @param space_mindist Array with minDistance values from space data
 * @param space_cid Array with clusters'id values from space data
 * @param clusters_x Array with x values from clusters
 * @param clusters_y Array with y values from clusters
 * @param clusters_npoints Array with numberOfPoints values from clusters
 * @param ssize Size of space data
 * @param csize Size of clusters
 */
void fill(float* space_x, float* space_y, float* space_mindist, int* space_cid, float* clusters_x, float* clusters_y, int* clusters_npoints, int ssize, int csize);

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
 * @param space_x Array with x values from space data
 * @param space_y Array with y values from space data
 * @param space_mindist Array with minDistance values from space data
 * @param space_cid Array with clusters'id values from space data
 * @param clusters_x Array with x values from clusters
 * @param clusters_y Array with y values from clusters
 * @param ssize Size of space data
 * @param csize Size of clusters
 */
void assign_cluster(float* space_x, float* space_y, float* space_mindist, int* space_cid, float* clusters_x, float* clusters_y, int ssize, int csize);

/**
 * @brief Calculate centroid of each cluster.
 * Saves 3 arrays: 
 * -> number of points associated to each cluster (index refers to cluster - 0 to cluster0, 1 to cluster1, ...); 
 * -> sum of x values associated to each cluster
 * -> sum of y values associated to each cluster
 * In order to calculate the centroid, we shall iterate over clusters_x and clusters_y arrays and we divide the sum with the number of points associated 
 * @param space_x Array with x values from space data
 * @param space_y Array with y values from space data
 * @param space_mindist Array with minDistance values from space data
 * @param space_cid Array with clusters'id values from space data
 * @param clusters_x Array with x values from clusters
 * @param clusters_y Array with y values from clusters
 * @param clusters_npoints Array with numberOfPoints values from clusters
 * @param ssize Size of space data
 * @param csize Size of clusters
 */
void calculate_centroids(float* space_x, float* space_y, float* space_mindist, int* space_cid, float* clusters_x, float* clusters_y, int* clusters_npoints, int ssize, int csize);

/**
 * @brief Checks if the centroids of the clusters are the same between consecutive iterations
 * @param clusters_old_x Previous clusters' version - array with x values
 * @param clusters_old_y Previous clusters' version - array with y values
 * @param clusters_new_x New clusters' version - array with x values
 * @param clusters_new_y New clusters' version - array with y values
 * @param csize 
 * @return int 1 if true, 0 otherwise
 */
int compare_centroids(float* clusters_old_x, float* clusters_old_y, float* clusters_new_x, float* clusters_new_y, int csize);

/**
 * @brief Copy each clusters' arrays to new ones
 * @param clusters_x Copy of new clusters' version - array with y values
 * @param clusters_y Copy of new clusters' version - array with y values
 * @param clusters_tocopy_x Copy of previous clusters' version - array with x values
 * @param clusters_tocopy_y Copy of previous clusters' version - array with y values
 * @param csize Size of clusters
 */
void copy_clusters(float* clusters_x, float* clusters_y, float* clusters_tocopy_x, float* clusters_tocopy_y, int csize);

/**
 * @brief Print the output desired by the teachers
 * @param n_samples Number of samples
 * @param k_clusters Number of clusters
 * @param clusters_x Array with x values from clusters
 * @param clusters_y Array with y values from clusters
 * @param clusters_npoints Array with numberOfPoints values from clusters
 * @param iterations Iterations done while calculating centroids and assigment data values in a loop
 */
void print_output(int n_samples, int k_clusters, float* clusters_x, float* clusters_y, int* clusters_npoints, int iterations);