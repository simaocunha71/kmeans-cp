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

        space_dist[0] = (clusters[0].y - space[j].y) * (clusters[0].y - space[j].y) + (clusters[0].x - space[j].x) * (clusters[0].x - space[j].x);
        space_dist[1] = (clusters[0].y - space[j+1].y) * (clusters[0].y - space[j+1].y) + (clusters[0].x - space[j+1].x) * (clusters[0].x - space[j+1].x);
        space_dist[2] = (clusters[0].y - space[j+2].y) * (clusters[0].y - space[j+2].y) + (clusters[0].x - space[j+2].x) * (clusters[0].x - space[j+2].x);
        space_dist[3] = (clusters[0].y - space[j+3].y) * (clusters[0].y - space[j+3].y) + (clusters[0].x - space[j+3].x) * (clusters[0].x - space[j+3].x);
        for (int k = 1; k < K_CLUSTERS; k++){
            dist[0] = (clusters[k].y - space[j].y) * (clusters[k].y - space[j].y) + (clusters[k].x - space[j].x) * (clusters[k].x - space[j].x);
            dist[1] = (clusters[k].y - space[j+1].y) * (clusters[k].y - space[j+1].y) + (clusters[k].x - space[j+1].x) * (clusters[k].x - space[j+1].x);
            dist[2] = (clusters[k].y - space[j+2].y) * (clusters[k].y - space[j+2].y) + (clusters[k].x - space[j+2].x) * (clusters[k].x - space[j+2].x);
            dist[3] = (clusters[k].y - space[j+3].y) * (clusters[k].y - space[j+3].y) + (clusters[k].x - space[j+3].x) * (clusters[k].x - space[j+3].x);
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
        
        sumX[space_cid[0]] += space[j].x;
        sumX[space_cid[1]] += space[j+1].x;
        sumX[space_cid[2]] += space[j+2].x;
        sumX[space_cid[3]] += space[j+3].x;

        sumY[space_cid[0]] += space[j].y;
        sumY[space_cid[1]] += space[j+1].y;
        sumY[space_cid[2]] += space[j+2].y;
        sumY[space_cid[3]] += space[j+3].y;

        clusters_npoints[space_cid[0]]++;
        clusters_npoints[space_cid[1]]++;
        clusters_npoints[space_cid[2]]++;
        clusters_npoints[space_cid[3]]++;

        
    }
    for(;j < N_SAMPLES;j++){
        space_cid[0] = 0;
        space_dist[0] = (clusters[0].y - space[j].y) * (clusters[0].y - space[j].y) + (clusters[0].x - space[j].x) * (clusters[0].x - space[j].x);
        for (int k = 0; k < K_CLUSTERS; k++){
            dist[0] = (clusters[k].y - space[j].y) * (clusters[k].y - space[j].y) + (clusters[k].x - space[j].x) * (clusters[k].x - space[j].x);
            if(dist[0] < space_dist[0]){
                space_dist[0] = dist[0];
                space_cid[0] = k;
            }
        }
        clusters_npoints[space_cid[0]] ++;
        sumX[space_cid[0]] += space[j].x;
        sumY[space_cid[0]] += space[j].y;
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