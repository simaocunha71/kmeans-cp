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
    float min_dist[4];
    float dist[4];
    int space_id_new[4];
    int converged = 1;
    float sx[4], sy[4];
    float cx, cy;
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters_npoints[i] = 0;
        sumX[i] = 0.0;
        sumY[i] = 0.0;    
    }
    int j;
    for(j=0;j < N_SAMPLES-3;j+=4){
        space_id_new[0] = 0; space_id_new[1] = 0; space_id_new[2] = 0; space_id_new[3] = 0;
        sx[0] = space_x[j]; sx[1] = space_x[j+1]; sx[2] = space_x[j+2]; sx[3] = space_x[j+3];
        sy[0] = space_y[j]; sy[1] = space_y[j+1]; sy[2] = space_y[j+2]; sy[3] = space_y[j+3];
        cx = clusters_x[0];
        cy = clusters_y[0];
        min_dist[0] = (cy - sy[0]) * (cy - sy[0]) + (cx - sx[0]) * (cx - sx[0]);
        min_dist[1] = (cy - sy[1]) * (cy - sy[1]) + (cx - sx[1]) * (cx - sx[1]);
        min_dist[2] = (cy - sy[2]) * (cy - sy[2]) + (cx - sx[2]) * (cx - sx[2]);
        min_dist[3] = (cy - sy[3]) * (cy - sy[3]) + (cx - sx[3]) * (cx - sx[3]);
        for (int k = 1; k < K_CLUSTERS; k++){
            cx = clusters_x[k];
            cy = clusters_y[k];
            dist[0] = (cy - sy[0]) * (cy - sy[0]) + (cx - sx[0]) * (cx - sx[0]);
            dist[1] = (cy - sy[1]) * (cy - sy[1]) + (cx - sx[1]) * (cx - sx[1]);
            dist[2] = (cy - sy[2]) * (cy - sy[2]) + (cx - sx[2]) * (cx - sx[2]);
            dist[3] = (cy - sy[3]) * (cy - sy[3]) + (cx - sx[3]) * (cx - sx[3]);
            if(dist[0] < min_dist[0]){
                min_dist[0] = dist[0];
                space_id_new[0] = k;
            }
            if(dist[1] < min_dist[1]){
                min_dist[1] = dist[1];
                space_id_new[1] = k;
            }
            if(dist[2] < min_dist[2]){
                min_dist[2] = dist[2];
                space_id_new[2] = k;
            }
            if(dist[3] < min_dist[3]){
                min_dist[3] = dist[3];
                space_id_new[3] = k;
            }
        }
        clusters_npoints[space_id_new[0]] ++;
        sumX[space_id_new[0]] += space_x[j];
        sumY[space_id_new[0]] += space_y[j];
        clusters_npoints[space_id_new[1]] ++;
        sumX[space_id_new[1]] += space_x[j+1];
        sumY[space_id_new[1]] += space_y[j+1];
        clusters_npoints[space_id_new[2]] ++;
        sumX[space_id_new[2]] += space_x[j+2];
        sumY[space_id_new[2]] += space_y[j+2];
        clusters_npoints[space_id_new[3]] ++;
        sumX[space_id_new[3]] += space_x[j+3];
        sumY[space_id_new[3]] += space_y[j+3];

        converged = converged && (space_id_new[0] == space_id[j] && space_id_new[1] == space_id[j+1] && space_id_new[2] == space_id[j+2] && space_id_new[3] == space_id[j+3]);
        space_id[j] = space_id_new[0];
        space_id[j+1] = space_id_new[1];
        space_id[j+2] = space_id_new[2];
        space_id[j+3] = space_id_new[3];
    }
    for(;j < N_SAMPLES;j++){
        space_id_new[0] = 0;
        sx[0] = space_x[j];
        sy[0] = space_y[j];
        cx = clusters_x[0];
        cy = clusters_y[0];
        min_dist[0] = (cy - sy[0]) * (cy - sy[0]) + (cx - sx[0]) * (cx - sx[0]);
        for (int k = 1; k < K_CLUSTERS; k++){
            cx = clusters_x[k];
            cy = clusters_y[k];
            dist[0] = (cy - sy[0]) * (cy - sy[0]) + (cx - sx[0]) * (cx - sx[0]);
            if(dist[0] < min_dist[0]){
                min_dist[0] = dist[0];
                space_id_new[0] = k;
            }
        }
        clusters_npoints[space_id_new[0]] ++;
        sumX[space_id_new[0]] += space_x[j];
        sumY[space_id_new[0]] += space_y[j];

        converged = converged && space_id_new[0] == space_id[j];
        space_id[j] = space_id_new[0];
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