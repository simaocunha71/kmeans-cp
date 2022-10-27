#include "../include/utils.h"

float* create_farray(int size){
    float* arr = (float*)malloc(size * sizeof(float));
    return arr;
}

int* create_iarray(int size){
    int* arr = (int*)malloc(size * sizeof(int));
    return arr;
}

void fill(float* space_x,float* space_y, float* clusters_x,float* clusters_y,int* space_id){
    srand(10);
    int i;
    for(i = 0; i < N_SAMPLES; i++) {
        space_x[i] = (float) rand() / RAND_MAX;
        space_y[i] = (float) rand() / RAND_MAX;
        space_id[i] = -1;
    }
    for(i = 0; i < K_CLUSTERS; i++) {
        clusters_x[i] = space_x[i];
        clusters_y[i] = space_y[i];
    }
}

int update_clusters(float* space_x,float* space_y, float* clusters_x,float* clusters_y, int* clusters_npoints, int* space_id){
    float sumX [K_CLUSTERS];
    float sumY [K_CLUSTERS];
    float space_dist;
    float dist;
    int space_id_new;
    int converged = 1;
    float cx, cy, sx, sy;
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters_npoints[i] = 0;
        sumX[i] = 0.0;
        sumY[i] = 0.0;    
    }
    for(int j=0;j < N_SAMPLES;j++){
        space_id_new = 0;
        sx = space_x[j];
        sy = space_y[j];
        cx = clusters_x[0];
        cy = clusters_y[0];
        space_dist = (cy - sy) * (cy - sy) + (cx - sx) * (cx - sx);
        for (int k = 1; k < K_CLUSTERS; k++){
            cx = clusters_x[k];
            cy = clusters_y[k];
            dist = (cy - sy) * (cy - sy) + (cx - sx) * (cx - sx);
            if(dist < space_dist){
                space_dist = dist;
                space_id_new = k;
            }
        }
        clusters_npoints[space_id_new] ++;
        sumX[space_id_new] += space_x[j];
        sumY[space_id_new] += space_y[j];

        converged = converged && space_id_new == space_id[j];
        space_id[j] = space_id_new;
    }

    for (int k = 0; k < K_CLUSTERS; k++) {
        //printf("cox%d(%.5f) | ", k,clusters_x[k]); //DEBUG
        //printf("cnpoints%d(%d) | ", k,clusters_npoints[k]); //DEBUG
        clusters_x[k] = sumX[k] / clusters_npoints[k];
        
        //printf("cnx%d(%.5f) || ", k,clusters_x[k]); //DEBUG
        //printf("coy%d(%.5f) | ", k,clusters_y[k]); //DEBUG
        clusters_y[k] = sumY[k] / clusters_npoints[k];

        //printf("cny%d(%.5f)\n", k,clusters_y[k]); //DEBUG
    }
    return converged;
}

void print_output(float* clusters_x,float* clusters_y, int* clusters_npoints, int iterations){
    printf("N = %d, K = %d\n", N_SAMPLES, K_CLUSTERS);
    for(int i = 0; i < K_CLUSTERS; i++){
        printf("Center: (%.3f, %.3f) : Size: %d\n", clusters_x[i], clusters_y[i], clusters_npoints[i]);
    }
    printf("Iterations: %d\n", iterations);
}