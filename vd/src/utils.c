#include "../include/utils.h"


float* create_farray(int size){
    float* arr = (float*)malloc(size * sizeof(float));
    return arr;
}

int* create_iarray(int size){
    int* arr = (int*)malloc(size * sizeof(int));
    return arr;
}


void fill(float* space_x,float* space_y, float* clusters_x,float* clusters_y, int* samples_id){
    srand(10);
    for(int i = 0; i < N_SAMPLES; i++) {
        space_x[i] = (float) rand() / RAND_MAX;
        space_y[i] = (float) rand() / RAND_MAX;
        samples_id[i] = -1;
    }
    for(int i = 0; i < K_CLUSTERS; i++) {
        clusters_x[i] = space_x[i];
        clusters_y[i] = space_y[i];
    }
}

int update_clusters(float* space_x,float* space_y, float* clusters_x,float* clusters_y, int* samples_id, int* clusters_npoints){
    float sumX[K_CLUSTERS];
    float sumY[K_CLUSTERS];
    float min_dist;
    float dist;

    float cx, cy, sx, sy;
    int sample_id_new;
    int converged = 1;

    // Initialise arrays with zeros
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters_npoints[i] = 0;
        sumX[i] = 0.0;
        sumY[i] = 0.0;
    }


    //Assign points
    for(int n = 0; n < N_SAMPLES; n++) {
        sx = space_x[n];
        sy = space_y[n];
        cx = clusters_x[0];
        cy = clusters_y[0];
        min_dist = euclidian_distance(sx,sy,cx,cy);
        sample_id_new = 0;
        for(int k = 1; k < K_CLUSTERS; k++) {
            cx = clusters_x[k];
            cy = clusters_y[k];
            dist = euclidian_distance(sx,sy,cx,cy);
            if (dist < min_dist) {
                min_dist = dist;
                sample_id_new = k;
            }
        }
        clusters_npoints[sample_id_new] ++;
        sumX[sample_id_new] += space_x[n];
        sumY[sample_id_new] += space_y[n];

        converged = converged && sample_id_new == samples_id[n];
        samples_id[n] = sample_id_new;
    }


    //Compute new centroids
    for (int i = 0; i < K_CLUSTERS; i++) {
        //printf("cox%d(%.5f) | ", i,clusters_x[i]); //DEBUG
        //printf("cnpoints%d(%d) | ", i,clusters_npoints[i]); //DEBUG
        clusters_x[i] = sumX[i] / clusters_npoints[i];
        //printf("cnx%d(%.5f) || ", i,clusters_x[i]); //DEBUG
        //printf("coy%d(%.5f) | ", i,clusters_y[i]); //DEBUG
        clusters_y[i] = sumY[i] / clusters_npoints[i];
        //printf("cny%d(%.5f)\n", i,clusters_y[i]); //DEBUG
    }

    return converged;
}

float euclidian_distance(float x1, float y1, float x2, float y2){
    return (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
}

void copy_samplesid(int* samples_id, int* samples_id_to_copy){
    for (int i = 0; i < N_SAMPLES; i++){
        samples_id[i] = samples_id_to_copy[i];
    }
}

void print_output(float* clusters_x,float* clusters_y, int* clusters_npoints, int iterations){
    printf("N = %d, K = %d\n", N_SAMPLES, K_CLUSTERS);
    for(int i = 0; i < K_CLUSTERS; i++){
        printf("Center: (%.3f, %.3f) : Size: %d\n", clusters_x[i], clusters_y[i], clusters_npoints[i]);
    }
    printf("Iterations: %d\n", iterations);
}