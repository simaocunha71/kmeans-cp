#include "../include/utils.h"

float* create_farray(int size){
    float* arr = (float*)malloc(size * sizeof(float));
    return arr;
}

int* create_iarray(int size){
    int* arr = (int*)malloc(size * sizeof(int));
    return arr;
}


void fill(float* space_x, float* space_y, float* space_mindist, int* space_cid, float* clusters_x, float* clusters_y, int* clusters_npoints, int ssize, int csize){
    srand(10);
    for(int i = 0; i < ssize; i++) {
        space_x[i] = (float) rand() / RAND_MAX;
        space_y[i] = (float) rand() / RAND_MAX;
        space_mindist[i] = MAX_DIST;
        space_cid[i] = -1;
    }
    for(int i = 0; i < csize; i++) {
        clusters_x[i] = space_x[i];
        clusters_y[i] = space_y[i];
        clusters_npoints[i] = 0;
    }
}

void assign_cluster(float* space_x, float* space_y, float* space_mindist, int* space_cid, float* clusters_x, float* clusters_y, int ssize, int csize){
    for(int i = 0; i < csize; i++) {
        for(int j = 0; j < ssize; j++) {
            float dist = euclidian_distance(space_x[j],space_y[j],clusters_x[i],clusters_y[i]);
            if (dist < space_mindist[j]) {
                space_mindist[j] = dist;
                space_cid[j] = i;
            }
        }
    }
}

float euclidian_distance(float p1_x, float p1_y, float p2_x, float p2_y){
    return (p2_y - p1_y) * (p2_y - p1_y) + (p2_x - p1_x) * (p2_x - p1_x);
}

void calculate_centroids(float* space_x, float* space_y, float* space_mindist, int* space_cid, float* clusters_x, float* clusters_y, int* clusters_npoints, int ssize, int csize){
    float* sumX = (float *) malloc(csize * sizeof(float));
    float* sumY = (float *) malloc(csize * sizeof(float));

    // Initialise arrays with zeros
    for (int i = 0; i < csize; i++) {
        clusters_npoints[i] = 0;
        sumX[i] = 0.0;
        sumY[i] = 0.0;
    }

    // Iterate over points from data space to append data to centroids
    for (int i = 0; i < ssize; i++) {
        int clusterId = space_cid[i];
        //printf("%d",clusterId);
        clusters_npoints[clusterId] += 1;
        sumX[clusterId] += space_x[i];
        sumY[clusterId] += space_y[i];

        space_mindist[i] = MAX_DIST;  // reset distance
    }

    // Compute the new centroids
    for (int i = 0; i < csize; i++) {
        //printf("cox%d(%.5f) | ", i,clusters_x[i]); //DEBUG
        //printf("cnpoints%d(%d) | ", i,clusters_npoints[i]); //DEBUG
        clusters_x[i] = sumX[i] / clusters_npoints[i];

        //printf("cnx%d(%.5f) || ", i,clusters_x[i]); //DEBUG
        //printf("coy%d(%.5f) | ", i,clusters_y[i]); //DEBUG

        clusters_y[i] = sumY[i] / clusters_npoints[i];

        //printf("cny%d(%.5f)\n", i,clusters_y[i]); //DEBUG
    }

    free(sumX); free(sumY);
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