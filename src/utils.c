#include "../include/utils.h"

POINT* create_vector(int size){
    POINT* vec = (POINT*)malloc(size * sizeof(struct point));
    return vec;
}

int* create_iarray(int size){
    int* arr = (int*)malloc(size * sizeof(int));
    return arr;
}


void fill(POINT* space, POINT* clusters, int* samples_id){
    srand(10);
    for(int i = 0; i < N_SAMPLES; i++) {
        space[i].x = (float) rand() / RAND_MAX;
        space[i].y = (float) rand() / RAND_MAX;
        samples_id[i] = -1;
    }
    for(int i = 0; i < K_CLUSTERS; i++) {
        clusters[i].x = space[i].x;
        clusters[i].y = space[i].y;
    }
}

int assign_points(POINT* space, POINT* clusters, int* samples_id, int* clusters_npoints, float* sumX, float* sumY, int world_size){
    float min_dist;
    float dist;
    int sample_id_new;
    int converged = 1;
    //Assign points
    for(int n = 0; n < (N_SAMPLES/world_size) + 1; n++) {
        min_dist = (clusters[0].y - space[n].y) * (clusters[0].y - space[n].y) + (clusters[0].x - space[n].x) * (clusters[0].x - space[n].x);
        sample_id_new = 0;
        for(int k = 1; k < K_CLUSTERS; k++) {
            dist = (clusters[k].y - space[n].y) * (clusters[k].y - space[n].y) + (clusters[k].x - space[n].x) * (clusters[k].x - space[n].x);
            sample_id_new = 0;
            if (dist < min_dist) {
                min_dist = dist;
                sample_id_new = k;
            }
        }
        clusters_npoints[sample_id_new] ++;
        sumX[sample_id_new] += space[n].x;
        sumY[sample_id_new] += space[n].y;

        converged = converged && sample_id_new == samples_id[n];
        samples_id[n] = sample_id_new;
    }
    return converged;
}

void compute_new_centroids(POINT* clusters,  int* clusters_npoints, float* sumX, float* sumY){
    // Initialise arrays with zeros
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters_npoints[i] = 0;
        sumX[i] = 0.0;
        sumY[i] = 0.0;
    }
}


void copy_samplesid(int* samples_id, int* samples_id_to_copy){
    for (int i = 0; i < N_SAMPLES; i++){
        samples_id[i] = samples_id_to_copy[i];
    }
}

void print_output(POINT* clusters, int* clusters_npoints, int iterations){
    printf("N = %d, K = %d\n", N_SAMPLES, K_CLUSTERS);
    for(int i = 0; i < K_CLUSTERS; i++){
        printf("Center: (%.3f, %.3f) : Size: %d\n", clusters[i].x, clusters[i].y, clusters_npoints[i]);
    }
    printf("Iterations: %d\n", iterations);
}