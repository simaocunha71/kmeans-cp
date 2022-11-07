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


    //Assign points with loop unrolling with 2 instructions per loop - number of samples odd
    int n;
    for(n = 0; n < N_SAMPLES-1; n+=2) {
        //Euclidean distance of two consecutive points for first cluster
        min_dist[0] = (clusters[0].y - space[n].y) * (clusters[0].y - space[n].y) + (clusters[0].x - space[n].x) * (clusters[0].x - space[n].x);
        min_dist[1] = (clusters[0].y - space[n+1].y) * (clusters[0].y - space[n+1].y) + (clusters[0].x - space[n+1].x) * (clusters[0].x - space[n+1].x);
        sample_id_new[0] = 0;
        sample_id_new[1] = 0;
        
        for(int k = 1; k < K_CLUSTERS; k++) {
            //Euclidean distance of two consecutive points for other clusters
            dist[0] = (clusters[k].y - space[n].y) * (clusters[k].y - space[n].y) + (clusters[k].x - space[n].x) * (clusters[k].x - space[n].x);
            dist[1] = (clusters[k].y - space[n+1].y) * (clusters[k].y - space[n+1].y) + (clusters[k].x - space[n+1].x) * (clusters[k].x - space[n+1].x);
            if (dist[0] < min_dist[0]) {
                //If the new distance of the first point is lower, update value
                min_dist[0] = dist[0];
                sample_id_new[0] = k;
            }
            if (dist[1] < min_dist[1]) {
                //If the new distance of the second point is lower, update value
                min_dist[1] = dist[1];
                sample_id_new[1] = k;
            }
        }

        //After getting the closest cluster to point #1, we now can fill the arrays with the cluster ID, x point value and y point value
        clusters_npoints[sample_id_new[0]] ++;
        sumX[sample_id_new[0]] += space[n].x;
        sumY[sample_id_new[0]] += space[n].y;

        //After getting the closest cluster to point #2, we now can fill the arrays with the cluster ID, x point value and y point value
        clusters_npoints[sample_id_new[1]] ++;
        sumX[sample_id_new[1]] += space[n+1].x;
        sumY[sample_id_new[1]] += space[n+1].y;

        //Check if the algorith converged - if the points are associated to the same clusters
        converged = converged && sample_id_new[0] == samples_id[n] && sample_id_new[1] == samples_id[n+1];
        samples_id[n] = sample_id_new[0];
        samples_id[n+1] = sample_id_new[1];
    }

    //In case of number of samples even, it does the last iteration
    if (n < N_SAMPLES) {
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


    //Compute new centroids according with arrays filled before
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters[i].x = sumX[i] / clusters_npoints[i];
        clusters[i].y = sumY[i] / clusters_npoints[i];
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