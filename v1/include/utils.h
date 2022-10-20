#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DIST 10
#define N_SAMPLES 10000000
#define K_CLUSTERS 4

/**
 * @brief Point struct
 */
typedef struct point {
    float x; //Value of x
    float y; //Value of y
    int cluster_id; //Cluster assigned
    double min_dist; //Minimum distance
} POINT;


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

/**
 * @brief Assign each point of space data to a certain cluster:
 * It calculates euclidian distance between data point and cluster and assigns point to the closest cluster (minimum distance)
 * @param space Point vector
 * @param clusters Cluster vector
 */
void assign_cluster(POINT* space, POINT* clusters);

/**
 * @brief Calculate centroid of each cluster.
 * Saves 3 arrays: 
 * -> number of points associated to each cluster (index refers to cluster - 0 to cluster0, 1 to cluster1, ...); 
 * -> sum of x values associated to each cluster
 * -> sum of y values associated to each cluster
 * In order to calculate the centroid, we shall iterate over clusters vector and we divide in each cluster the sum with the number of points associated 
 * @param space Point vector
 * @param clusters Cluster vector
 */
void calculate_centroids(POINT* space, POINT* clusters);

/**
 * @brief Checks if the centroids of the clusters are the same between consecutive iterations
 * @param clusters_old Copy of previous clusters' version
 * @param clusters_new New clusters' version'
 * @return int 1 if true, 0 otherwise
 */
int compare_centroids(POINT* clusters_old, POINT* clusters_new);

/**
 * @brief Saves a copy of cluster's vector from "cluster_to_copy" to "cluster"
 * @param cluster New cluster
 * @param cluster_to_copy Old cluster
 */
void copy_clusters(POINT* cluster, POINT* cluster_to_copy);

/**
 * @brief Print the output desired by the teachers
 * @param clusters Clusters' vector
 * @param iterations Iterations done while calculating centroids and assigment data values in a loop
 */
void print_output(POINT* clusters, int iterations);