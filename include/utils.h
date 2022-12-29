#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>


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

/**
 * @brief Fill sample's space and clusters with random values according with a certain seed and calculus
 * @param space_x Array with x values from samples
 * @param space_y Array with y values from samples
 * @param clusters_x Array with x values from clusters
 * @param clusters_y Array with y values from clusters
 * @param samples_id Int array with cluster ID that each point is associated to (initialized with -1)
 */
void fill(float* space_x,float* space_y, float* clusters_x,float* clusters_y, int* samples_id, int N_SAMPLES, int K_CLUSTERS);

/**
 * @brief Update clusters and checks if the clusters are the same
 * @param space_x Array with x values from samples
 * @param space_y Array with y values from samples
 * @param clusters_x Array with x values from clusters
 * @param clusters_y Array with y values from clusters
 * @param samples_id Int array with cluster ID that each point is associated to (initialized with -1)
 * @param clusters_npoints Number of points associated to each cluster
 * @param nProcesses Number of processes in use
 * @param atualRank ID from process who is doing the work
 * @param status Variable required in MPI_Recv()
 * @return int 1 if converged, 0 otherwise
 */
int update_clusters(float* space_x,float* space_y, float* clusters_x,float* clusters_y, int* samples_id, int* clusters_npoints, int nProcesses, int atualRank, MPI_Status status, int N_SAMPLES, int K_CLUSTERS);

/**
 * @brief Copy values from samples_id_to_copy to samples_id
 * @param samples_id Destiny array
 * @param samples_id_to_copy Origin array
 */
void copy_samplesid(int* samples_id, int* samples_id_to_copy, int N_SAMPLES, int K_CLUSTERS);

/**
 * @brief Print the output desired by the teachers
 * @param clusters_x Array with x values from clusters
 * @param clusters_y Array with y values from clusters
 * @param clusters_npoints Number of points associated to each cluster
 * @param iterations Iterations done by the algorithm
 */
void print_output(float* clusters_x,float* clusters_y, int* clusters_npoints, int iterations, int N_SAMPLES, int K_CLUSTERS);