#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DIST 10



/**
 * @brief Create a array object
 * @param size Array size
 * @return float* Array allocated
 */
float* create_farray(int size);

/**
 * @brief Create a array object
 * @param size Array size
 * @return int* Array allocated
 */
int* create_iarray(int size);


/**
 * @brief Fill sample's space with random values and fill clusters' matrix
 * @param space Sample's space
 * @param clusters Clusters' vector
 * @param ssize Size of sample's space
 * @param ssize Size of clusters' vector
 */
void fill(float* space_x, float* space_y, float* space_mindist, int* space_cid, float* clusters_x, float* clusters_y, int* clusters_npoints, int ssize, int csize);

/**
 * @brief Euclidian distance between two points
 * @param p1 Point 1
 * @param p2 Point 2
 * @return float Distance between Point 1 and Point 2
 */
float euclidian_distance(float p1_x, float p1_y, float p2_x, float p2_y);

/**
 * @brief Assign all points to a cluster
 * @param space Point vector
 * @param clusters Cluster vector
 * @param ssize Point vector size
 * @param csize Cluster vector size
 */
void assign_cluster(float* space_x, float* space_y, float* space_mindist, int* space_cid, float* clusters_x, float* clusters_y, int ssize, int csize);

/**
 * @brief Calculate centroids
 * @param space Point vector
 * @param clusters Cluster vector
 * @param ssize Point vector size
 * @param csize Cluster vector size
 */
void calculate_centroids(float* space_x, float* space_y, float* space_mindist, int* space_cid, float* clusters_x, float* clusters_y, int* clusters_npoints, int ssize, int csize);

/**
 * @brief Compare centroids: if they have the same values in two consecutives iterations, then returns 1, else 0
 * @param clusters_old Copy of previous clusters' version
 * @param clusters_new New clusters' version'
 * @param csize Size of cluster's vector
 * @return int 1 if true, 0 otherwise
 */
int compare_centroids(float* clusters_old_x, float* clusters_old_y, float* clusters_new_x, float* clusters_new_y, int csize);

/**
 * @brief Saves a copy of cluster's vector from "cluster_to_copy" to "cluster"
 * @param cluster New cluster
 * @param cluster_to_copy Old cluster
 * @param csize Size of cluster's vector
 */
void copy_clusters(float* clusters_x, float* clusters_y, float* clusters_tocopy_x, float* clusters_tocopy_y, int csize);

/**
 * @brief Print the output desired by the teachers
 * @param n_samples Number of samples
 * @param k_clusters Number of clusters
 * @param clusters Clusters' vector
 * @param iterations Number of iterations done by the algorithm
 */
void print_output(int n_samples, int k_clusters, float* clusters_x, float* clusters_y, int* clusters_npoints, int iterations);