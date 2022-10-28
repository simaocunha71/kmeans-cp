#include "../include/utils.h"

POINT* create_vector(int size){
    POINT* vec = (POINT*)malloc(size * sizeof(struct point));
    return vec;
}

int* create_iarray(int size){
    int* arr = (int*)malloc(size * sizeof(int));
    return arr;
}

void fill(POINT* space, POINT* clusters, int* samples_id){
    srand(10);
    for(int i = 0; i < N_SAMPLES; i++) {
        space[i].x = (float) rand() / RAND_MAX;
        space[i].y = (float) rand() / RAND_MAX;
        samples_id[i] = -1;
    }
    for(int i = 0; i < K_CLUSTERS; i++) {
        clusters[i].x = space[i].x;
        clusters[i].y = space[i].y;
    }
}

int update_clusters(POINT* space, POINT* clusters, int* samples_id, int* clusters_npoints){
    float sumX[K_CLUSTERS];
    float sumY[K_CLUSTERS];
    float min_dist[2];
    float dist[2];

    int sample_id_new[2];
    int converged = 1;

    // Initialise arrays with zeros
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters_npoints[i] = 0;
        sumX[i] = 0.0;
        sumY[i] = 0.0;
    }


    //Assign points
    int n;
    for(n = 0; n < N_SAMPLES-1; n+=2) {
        min_dist[0] = (clusters[0].y - space[n].y) * (clusters[0].y - space[n].y) + (clusters[0].x - space[n].x) * (clusters[0].x - space[n].x);
        min_dist[1] = (clusters[0].y - space[n+1].y) * (clusters[0].y - space[n+1].y) + (clusters[0].x - space[n+1].x) * (clusters[0].x - space[n+1].x);
        sample_id_new[0] = 0;
        sample_id_new[1] = 0;
        for(int k = 1; k < K_CLUSTERS; k++) {
            dist[0] = (clusters[k].y - space[n].y) * (clusters[k].y - space[n].y) + (clusters[k].x - space[n].x) * (clusters[k].x - space[n].x);
            dist[1] = (clusters[k].y - space[n+1].y) * (clusters[k].y - space[n+1].y) + (clusters[k].x - space[n+1].x) * (clusters[k].x - space[n+1].x);
            if (dist[0] < min_dist[0]) {
                min_dist[0] = dist[0];
                sample_id_new[0] = k;
            }
            if (dist[1] < min_dist[1]) {
                min_dist[1] = dist[1];
                sample_id_new[1] = k;
            }
        }
        clusters_npoints[sample_id_new[0]] ++;
        sumX[sample_id_new[0]] += space[n].x;
        sumY[sample_id_new[0]] += space[n].y;
        clusters_npoints[sample_id_new[1]] ++;
        sumX[sample_id_new[1]] += space[n+1].x;
        sumY[sample_id_new[1]] += space[n+1].y;

        converged = converged && sample_id_new[0] == samples_id[n] && sample_id_new[1] == samples_id[n+1];
        samples_id[n] = sample_id_new[0];
        samples_id[n+1] = sample_id_new[1];
    }
    for(; n < N_SAMPLES; n++) {
        min_dist[0] = (clusters[0].y - space[n].y) * (clusters[0].y - space[n].y) + (clusters[0].x - space[n].x) * (clusters[0].x - space[n].x);
        sample_id_new[0] = 0;
        for(int k = 1; k < K_CLUSTERS; k++) {
            dist[0] = (clusters[k].y - space[n].y) * (clusters[k].y - space[n].y) + (clusters[k].x - space[n].x) * (clusters[k].x - space[n].x);
            if (dist[0] < min_dist[0]) {
                min_dist[0] = dist[0];
                sample_id_new[0] = k;
            }
        }
        clusters_npoints[sample_id_new[0]] ++;
        sumX[sample_id_new[0]] += space[n].x;
        sumY[sample_id_new[0]] += space[n].y;

        converged = converged && sample_id_new[0] == samples_id[n];
        samples_id[n] = sample_id_new[0];
    }


    //Compute new centroids
    for (int i = 0; i < K_CLUSTERS; i++) {
        //printf("cox%d(%.5f) | ", i,clusters[i].x); //DEBUG
        //printf("cnpoints%d(%d) | ", i,clusters_npoints[i]); //DEBUG
        clusters[i].x = sumX[i] / clusters_npoints[i];
        //printf("cnx%d(%.5f) || ", i,clusters[i].x); //DEBUG
        //printf("coy%d(%.5f) | ", i,clusters[i].y); //DEBUG
        clusters[i].y = sumY[i] / clusters_npoints[i];
        //printf("cny%d(%.5f)\n", i,clusters[i].y); //DEBUG
    }

    return converged;
}

void print_output(POINT* clusters, int* clusters_npoints, int iterations){
    printf("N = %d, K = %d\n", N_SAMPLES, K_CLUSTERS);
    for(int i = 0; i < K_CLUSTERS; i++){
        printf("Center: (%.3f, %.3f) : Size: %d\n", clusters[i].x, clusters[i].y, clusters_npoints[i]);
    }
    printf("Iterations: %d\n", iterations);
}