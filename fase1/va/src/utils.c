#include "../include/utils.h"

POINT* create_vector(int size){
    POINT* vec = (POINT*)malloc(size * sizeof(struct point));
    return vec;
}

int* create_iarray(int size){
    int* arr = (int*)malloc(size * sizeof(int));
    return arr;
}


void fill(POINT* space, POINT* clusters){
    srand(10);
    for(int i = 0; i < N_SAMPLES; i++) {
        space[i].x = (float) rand() / RAND_MAX;
        space[i].y = (float) rand() / RAND_MAX;
    }
    for(int i = 0; i < K_CLUSTERS; i++) {
        clusters[i].x = space[i].x;
        clusters[i].y = space[i].y;
    }
}

void update_clusters(POINT* space, POINT* clusters, int* samples_id, int* clusters_npoints){
    float sumX[K_CLUSTERS];
    float sumY[K_CLUSTERS];
    float min_dist;
    float dist;

    // Initialise arrays with zeros
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters_npoints[i] = 0;
        sumX[i] = 0.0;
        sumY[i] = 0.0;
    }


    //Assign points
    for(int n = 0; n < N_SAMPLES; n++) {
        min_dist = euclidian_distance(space[n],clusters[0]);
        samples_id[n] = 0;
        for(int k = 1; k < K_CLUSTERS; k++) {
            dist = euclidian_distance(space[n],clusters[k]);
            if (dist < min_dist) {
                min_dist = dist;
                samples_id[n] = k;
            }
        }
        clusters_npoints[samples_id[n]] ++;
        sumX[samples_id[n]] += space[n].x;
        sumY[samples_id[n]] += space[n].y;
    }


    //Compute new centroids
    for (int i = 0; i < K_CLUSTERS; i++) {
        //printf("cox%d(%.5f) | ", i,clusters[i].x); //DEBUG
        //printf("cnpoints%d(%d) | ", i,clusters_npoints[i]); //DEBUG
        clusters[i].x = sumX[i] / clusters_npoints[i];
        //printf("cnx%d(%.5f) || ", i,clusters[i].x); //DEBUG
        //printf("coy%d(%.5f) | ", i,clusters[i].y); //DEBUG
        clusters[i].y = sumY[i] / clusters_npoints[i];
        //printf("cny%d(%.5f)\n", i,clusters[i].y); //DEBUG
    }
}

float euclidian_distance(POINT p1, POINT p2){
    return sqrt(pow(p2.y - p1.y, 2) + pow(p2.x - p1.x, 2));
}


int has_converged(int* samples_id_old, int* samples_id){
    int converged = 1;
    for(int i = 0; i < N_SAMPLES && converged; i++){
        if(samples_id_old[i] != samples_id[i])
            converged = 0;
    }
    return converged;
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