#include "../include/utils.h"

POINT* create_vector(int size){
    POINT* vec = (POINT*)malloc(size * sizeof(POINT));
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

int update_clusters(POINT* space, POINT* clusters, int* clusters_npoints){
    
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
        clusters_npoints[space_cid] ++;
        sumX[space_cid] += space[j].x;
        sumY[space_cid] += space[j].y;
    }

    int equals = 1;

    for (int i = 0; i < K_CLUSTERS; i++) {
        float x_old = clusters[i].x;
        clusters[i].x = sumX[i] / clusters_npoints[i];
        
        float y_old = clusters[i].y;
        clusters[i].y = sumY[i] / clusters_npoints[i];

        equals = (equals && (x_old == clusters[i].x || y_old == clusters[i].y));
    }
    return equals;
}

void print_output(POINT* clusters, int* clusters_npoints, int iterations){
    printf("N = %d, K = %d\n", N_SAMPLES, K_CLUSTERS);
    for(int i = 0; i < K_CLUSTERS; i++){
        printf("Center: (%.3f, %.3f) : Size: %d\n", clusters[i].x, clusters[i].y, clusters_npoints[i]);
    }
    printf("Iterations: %d\n", iterations);
}