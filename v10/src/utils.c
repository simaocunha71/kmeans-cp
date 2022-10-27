#include "../include/utils.h"

float* create_farray(int size){
    float* arr = (float*)malloc(size * sizeof(float));
    return arr;
}

int* create_iarray(int size){
    int* arr = (int*)malloc(size * sizeof(int));
    return arr;
}

void fill(float* space_x, float* space_y, float* clusters_x, float* clusters_y){
    srand(10);
    int i;
    for(i = 0; i < N_SAMPLES; i++) {
        space_x[i] = (float) rand() / RAND_MAX;
        space_y[i] = (float) rand() / RAND_MAX;
    }
    for(i = 0; i < K_CLUSTERS; i++) {
        clusters_x[i] = space_x[i];
        clusters_y[i] = space_y[i];
    }
}

int update_clusters(float* space_x, float* space_y, float* clusters_x, float* clusters_y, int* clusters_npoints){
    float sumX [K_CLUSTERS];
    float sumY [K_CLUSTERS];
    float space_dist[4];
    float dist[4];
    int space_cid[4];
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters_npoints[i] = 0;
        sumX[i] = 0.0;
        sumY[i] = 0.0;    
    }
    int j = 0;
    for(; j < N_SAMPLES-3; j+=4){
        space_cid[0] = 0;
        space_cid[1] = 0;
        space_cid[2] = 0;
        space_cid[3] = 0;

        space_dist[0] = (clusters_y[0] - space_y[j]) * (clusters_y[0] - space_y[j]) + (clusters_x[0] - space_x[j]) * (clusters_x[0] - space_x[j]);
        space_dist[1] = (clusters_y[0] - space_y[j+1]) * (clusters_y[0] - space_y[j+1]) + (clusters_x[0] - space_x[j+1]) * (clusters_x[0] - space_x[j+1]);
        space_dist[2] = (clusters_y[0] - space_y[j+2]) * (clusters_y[0] - space_y[j+2]) + (clusters_x[0] - space_x[j+2]) * (clusters_x[0] - space_x[j+2]);
        space_dist[3] = (clusters_y[0] - space_y[j+3]) * (clusters_y[0] - space_y[j+3]) + (clusters_x[0] - space_x[j+3]) * (clusters_x[0] - space_x[j+3]);
        for (int k = 1; k < K_CLUSTERS; k++){
            dist[0] = (clusters_y[k] - space_y[j]) * (clusters_y[k] - space_y[j]) + (clusters_x[k] - space_x[j]) * (clusters_x[k] - space_x[j]);
            dist[1] = (clusters_y[k] - space_y[j+1]) * (clusters_y[k] - space_y[j+1]) + (clusters_x[k] - space_x[j+1]) * (clusters_x[k] - space_x[j+1]);
            dist[2] = (clusters_y[k] - space_y[j+2]) * (clusters_y[k] - space_y[j+2]) + (clusters_x[k] - space_x[j+2]) * (clusters_x[k] - space_x[j+2]);
            dist[3] = (clusters_y[k] - space_y[j+3]) * (clusters_y[k] - space_y[j+3]) + (clusters_x[k] - space_x[j+3]) * (clusters_x[k] - space_x[j+3]);
            if(dist[0] < space_dist[0]){
                space_dist[0] = dist[0];
                space_cid[0] = k;
            }
            if(dist[1] < space_dist[1]){
                space_dist[1] = dist[1];
                space_cid[1] = k;
            }
            if(dist[2] < space_dist[2]){
                space_dist[2] = dist[2];
                space_cid[2] = k;
            }
            if(dist[3] < space_dist[3]){
                space_dist[3] = dist[3];
                space_cid[3] = k;
            }
        }
        
        sumX[space_cid[0]] += space_x[j];
        sumX[space_cid[1]] += space_x[j+1];
        sumX[space_cid[2]] += space_x[j+2];
        sumX[space_cid[3]] += space_x[j+3];

        sumY[space_cid[0]] += space_y[j];
        sumY[space_cid[1]] += space_y[j+1];
        sumY[space_cid[2]] += space_y[j+2];
        sumY[space_cid[3]] += space_y[j+3];

        clusters_npoints[space_cid[0]]++;
        clusters_npoints[space_cid[1]]++;
        clusters_npoints[space_cid[2]]++;
        clusters_npoints[space_cid[3]]++;

        
    }
    for(;j < N_SAMPLES;j++){
        space_cid[0] = 0;
        space_dist[0] = (clusters_y[0] - space_y[j]) * (clusters_y[0] - space_y[j]) + (clusters_x[0] - space_x[j]) * (clusters_x[0] - space_x[j]);
        for (int k = 0; k < K_CLUSTERS; k++){
            dist[0] = (clusters_y[k] - space_y[j]) * (clusters_y[k] - space_y[j]) + (clusters_x[k] - space_x[j]) * (clusters_x[k] - space_x[j]);
            if(dist[0] < space_dist[0]){
                space_dist[0] = dist[0];
                space_cid[0] = k;
            }
        }
        clusters_npoints[space_cid[0]] ++;
        sumX[space_cid[0]] += space_x[j];
        sumY[space_cid[0]] += space_y[j];
    }

    int equals = 1;
    float x_old;
    float y_old;
    for (int k = 0; k < K_CLUSTERS; k++) {
        //printf("cox%d(%.5f) | ", k,clusters_x[k]); //DEBUG
        //printf("cnpoints%d(%d) | ", k,clusters_npoints[k]); //DEBUG
        x_old = clusters_x[k];
        clusters_x[k] = sumX[k] / clusters_npoints[k];
        
        //printf("cnx%d(%.5f) || ", k,clusters_x[k]); //DEBUG
        //printf("coy%d(%.5f) | ", k,clusters_y[k]); //DEBUG
        y_old = clusters_y[k];
        clusters_y[k] = sumY[k] / clusters_npoints[k];

        equals = (equals && (x_old == clusters_x[k] || y_old == clusters_y[k]));

        //printf("cny%d(%.5f)\n", k,clusters_y[k]); //DEBUG
    }
    return equals;
}

void print_output(float* clusters_x,float* clusters_y, int* clusters_npoints, int iterations){
    printf("N = %d, K = %d\n", N_SAMPLES, K_CLUSTERS);
    for(int i = 0; i < K_CLUSTERS; i++){
        printf("Center: (%.3f, %.3f) : Size: %d\n", clusters_x[i], clusters_y[i], clusters_npoints[i]);
    }
    printf("Iterations: %d\n", iterations);
}