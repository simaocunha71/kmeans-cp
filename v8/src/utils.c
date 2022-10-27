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
    int i;
    for(i = 0; i < N_SAMPLES; i++) {
        space[i].x = (float) rand() / RAND_MAX;
        space[i].y = (float) rand() / RAND_MAX;
    }
    for(i = 0; i < K_CLUSTERS; i++) {
        clusters[i].x = space[i].x;
        clusters[i].y = space[i].y;
    }
}

int update_clusters(POINT* space, POINT* clusters, int* clusters_npoints){
    float sumX [K_CLUSTERS];
    float sumY [K_CLUSTERS];
    float space_dist;
    float dist;
    int space_cid;
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters_npoints[i] = 0;
        sumX[i] = 0.0;
        sumY[i] = 0.0;    
    }
    int j;
    for(j=0;j < N_SAMPLES;j++){
        space_cid = 0;
        space_dist = (clusters[0].y - space[j].y) * (clusters[0].y - space[j].y) + (clusters[0].x - space[j].x) * (clusters[0].x - space[j].x);
        for (int k = 0; k < K_CLUSTERS; k++){
            dist = (clusters[k].y - space[j].y) * (clusters[k].y - space[j].y) + (clusters[k].x - space[j].x) * (clusters[k].x - space[j].x);
            if(dist < space_dist){
                space_dist = dist;
                space_cid = k;
            }
        }
        clusters_npoints[space_cid] ++;
        sumX[space_cid] += space[j].x;
        sumY[space_cid] += space[j].y;
    }

    int equals = 1;

    for (int k = 0; k < K_CLUSTERS; k++) {
        //printf("cox%d(%.5f) | ", k,clusters[k].x); //DEBUG
        //printf("cnpoints%d(%d) | ", k,clusters_npoints[k]); //DEBUG
        float x_old = clusters[k].x;
        clusters[k].x = sumX[k] / clusters_npoints[k];
        
        //printf("cnx%d(%.5f) || ", k,clusters[k].x); //DEBUG
        //printf("coy%d(%.5f) | ", k,clusters[k].y); //DEBUG
        float y_old = clusters[k].y;
        clusters[k].y = sumY[k] / clusters_npoints[k];

        equals = (equals && (x_old == clusters[k].x || y_old == clusters[k].y));

        //printf("cny%d(%.5f)\n", k,clusters[k].y); //DEBUG
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