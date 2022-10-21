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
    for(int i = 0; i < K_CLUSTERS*2; i++) {
        clusters[i].x = space[i].x;
        clusters[i].y = space[i].y;
    }
}

void update_clusters(POINT* space, POINT* clusters, int* clusters_npoints){
    
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
            float dist = (clusters[i].y - space[j].y) * (clusters[i].y - space[j].y) + (clusters[i].x - space[j].x) * (clusters[i].x - space[j].x);
            if(dist < space_dist){
                space_dist = dist;
                space_cid = i;
            }
        }
        clusters_npoints[space_cid] += 1;
        sumX[space_cid] += space[j].x;
        sumY[space_cid] += space[j].y;
    }

    for (int i = 0; i < K_CLUSTERS; i++) {
        //printf("cox%d(%.5f) | ", i,clusters[i*2]); //DEBUG
        //printf("cnpoints%d(%d) | ", i,clusters_npoints[i]); //DEBUG
        clusters[i].x = sumX[i] / clusters_npoints[i];

        //printf("cnx%d(%.5f) || ", i,clusters[i*2]); //DEBUG
        //printf("coy%d(%.5f) | ", i,clusters[i*2+1]); //DEBUG

        clusters[i].y = sumY[i] / clusters_npoints[i];

        //printf("cny%d(%.5f)\n", i,clusters[i*2+1]); //DEBUG
    }
}

int compare_centroids(POINT* clusters_old, POINT* clusters_new){
    int equals = 1;
    for(int i = 0; i < K_CLUSTERS && equals; i++){
        if(clusters_old[i].x != clusters_new[i].x || clusters_old[i].y != clusters_new[i].y)
            equals = 0;
    }
    return equals;
}

void copy_clusters(POINT* clusters, POINT* clusters_tocopy){
    for (int i = 0; i < K_CLUSTERS; i++){
        clusters[i].x = clusters_tocopy[i].x;
        clusters[i].y = clusters_tocopy[i].y;
    }
}

void print_output(POINT* clusters, int* clusters_npoints, int iterations){
    printf("N = %d, K = %d\n", N_SAMPLES, K_CLUSTERS);
    for(int i = 0; i < K_CLUSTERS; i++){
        printf("Center: (%.3f, %.3f) : Size: %d\n", clusters[i].x, clusters[i].y, clusters_npoints[i]);
    }
    printf("Iterations: %d\n", iterations);
}