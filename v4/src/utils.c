#include "../include/utils.h"
#include "../include/k_means.h"

float* create_farray(int size){
    float* arr = (float*)malloc(size * sizeof(float));
    return arr;
}

int* create_iarray(int size){
    int* arr = (int*)malloc(size * sizeof(int));
    return arr;
}


void fill(float* space_x, float* space_y, float* clusters_x, float* clusters_y, int* clusters_npoints){
    srand(10);
    for(int i = 0; i < N_SAMPLES; i++) {
        space_x[i] = (float) rand() / RAND_MAX;
        space_y[i] = (float) rand() / RAND_MAX;
    }
    for(int i = 0; i < K_CLUSTERS; i++) {
        clusters_x[i] = space_x[i];
        clusters_y[i] = space_y[i];
        clusters_npoints[i] = 0;
    }
}

void assign_cluster(float* space_x, float* space_y, float* clusters_x, float* clusters_y, int* clusters_npoints){
    
    float sumX [K_CLUSTERS];
    float sumY [K_CLUSTERS];

    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters_npoints[i] = 0;
        sumX[i] = 0.0;
        sumY[i] = 0.0;
    }
    
    for(int j = 0; j < N_SAMPLES; j++){
        float space_dist = MAX_DIST;
        int space_cid = 0;
        for (int i = 0; i < K_CLUSTERS; i++){
            float dist = euclidian_distance(space_x[j],space_y[j],clusters_x[i],clusters_y[i]);
            if(dist < space_dist){
                space_dist = dist;
                space_cid = i;
            }
        }
        clusters_npoints[space_cid] += 1;
        sumX[space_cid] += space_x[j];
        sumY[space_cid] += space_y[j];
    }

    for (int i = 0; i < K_CLUSTERS; i++) {
        //printf("cox%d(%.5f) | ", i,clusters_x[i]); //DEBUG
        //printf("cnpoints%d(%d) | ", i,clusters_npoints[i]); //DEBUG
        clusters_x[i] = sumX[i] / clusters_npoints[i];

        //printf("cnx%d(%.5f) || ", i,clusters_x[i]); //DEBUG
        //printf("coy%d(%.5f) | ", i,clusters_y[i]); //DEBUG

        clusters_y[i] = sumY[i] / clusters_npoints[i];

        //printf("cny%d(%.5f)\n", i,clusters_y[i]); //DEBUG
    }
}

float euclidian_distance(float p1_x, float p1_y, float p2_x, float p2_y){
    return (p2_y - p1_y) * (p2_y - p1_y) + (p2_x - p1_x) * (p2_x - p1_x);
}

int compare_centroids(float* clusters_old_x, float* clusters_old_y, float* clusters_new_x, float* clusters_new_y, int csize){
    int equals = 1;
    for(int i = 0; i < csize && equals; i++){
        if(clusters_old_x[i] != clusters_new_x[i] || clusters_old_y[i] != clusters_new_y[i])
            equals = 0;
    }
    return equals;
}

void copy_clusters(float* clusters_x, float* clusters_y, float* clusters_tocopy_x, float* clusters_tocopy_y, int csize){
    for (int i = 0; i < csize; i++){
        clusters_x[i] = clusters_tocopy_x[i];
        clusters_y[i] = clusters_tocopy_y[i];
    }
}

void print_output(int n_samples, int k_clusters, float* clusters_x, float* clusters_y, int* clusters_npoints, int iterations){
    printf("N = %d, K = %d\n", n_samples, k_clusters);
    for(int i = 0; i < k_clusters; i++){
        printf("Center: (%.3f, %.3f) : Size: %d\n", clusters_x[i], clusters_y[i], clusters_npoints[i]);
    }
    printf("Iterations: %d\n", iterations);
}