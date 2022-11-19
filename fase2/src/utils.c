#include "../include/utils.h"

POINT* create_vector(int size){
    POINT* vec = (POINT*)malloc(size * sizeof(struct point));
    return vec;
}

int* create_iarray(int size){
    int* arr = (int*)malloc(size * sizeof(int));
    return arr;
}

void fill(POINT* space, POINT* clusters, int* samples_id, int N_SAMPLES, int K_CLUSTERS){
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

int update_clusters(POINT* space, POINT* clusters, int* samples_id, int* clusters_npoints, int N_SAMPLES, int K_CLUSTERS){
    float sumX[K_CLUSTERS];
    float sumY[K_CLUSTERS];
    float min_dist;
    float dist;

    int sample_id_new;
    int converged = 1;

    // Initialise arrays with zeros
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters_npoints[i] = 0;
        sumX[i] = 0.0;
        sumY[i] = 0.0;
    }


    //Assign points with loop unrolling with 2 instructions per loop - number of samples odd
    int n;
    for(n = 0; n < N_SAMPLES; n++) {
        //Euclidean distance of two consecutive points for first cluster
        min_dist = (clusters[0].y - space[n].y) * (clusters[0].y - space[n].y) + (clusters[0].x - space[n].x) * (clusters[0].x - space[n].x);
        sample_id_new = 0;
        
        for(int k = 1; k < K_CLUSTERS; k++) {
            //Euclidean distance of two consecutive points for other clusters
            dist = (clusters[k].y - space[n].y) * (clusters[k].y - space[n].y) + (clusters[k].x - space[n].x) * (clusters[k].x - space[n].x);
            if (dist < min_dist) {
                //If the new distance of the first point is lower, update value
                min_dist = dist;
                sample_id_new = k;
            }
        }

        //After getting the closest cluster to point #1, we now can fill the arrays with the cluster ID, x point value and y point value
        clusters_npoints[sample_id_new] ++;
        sumX[sample_id_new] += space[n].x;
        sumY[sample_id_new] += space[n].y;

        //Check if the algorith converged - if the points are associated to the same clusters
        converged = converged && sample_id_new == samples_id[n];
        samples_id[n] = sample_id_new;
    }


    //Compute new centroids according with arrays filled before
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters[i].x = sumX[i] / clusters_npoints[i];
        clusters[i].y = sumY[i] / clusters_npoints[i];
    }

    return converged;
}

int update_clusters_parallel(POINT* space, POINT* clusters, int* samples_id, int* clusters_npoints, int N_SAMPLES, int K_CLUSTERS){
    float sumX[K_CLUSTERS]; 
    float sumY[K_CLUSTERS]; 
    float min_dist;
    float dist;
    int converged = 1; //variavel critica

    // Initialise arrays with zeros
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters_npoints[i] = 0; //variavel critica
        sumX[i] = 0.0; //variavel critica
        sumY[i] = 0.0; //variavel critica
    }


    //Assign points with loop unrolling with 2 instructions per loop - number of samples odd
    int n = 0, k;

    #pragma omp parallel
    {
    float sumX_par[K_CLUSTERS];
    float sumY_par[K_CLUSTERS];
    int converged_par = 1;
    int clusters_npoints_par[K_CLUSTERS];
    int sample_id_new;
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters_npoints_par[i] = 0; 
        sumX_par[i] = 0.0; 
        sumY_par[i] = 0.0; 
    }
    #pragma omp for
    for(n = 0; n < N_SAMPLES; n++) {
        //Euclidean distance of two consecutive points for first cluster
        min_dist = (clusters[0].y - space[n].y) * (clusters[0].y - space[n].y) + (clusters[0].x - space[n].x) * (clusters[0].x - space[n].x);
        sample_id_new = 0;
        
        for(k = 1; k < K_CLUSTERS; k++) {
            //Euclidean distance of two consecutive points for other clusters
            dist = (clusters[k].y - space[n].y) * (clusters[k].y - space[n].y) + (clusters[k].x - space[n].x) * (clusters[k].x - space[n].x);
            if (dist < min_dist) {
                //If the new distance of the first point is lower, update value
                min_dist = dist;
                sample_id_new = k;
            }
        }

        //After getting the closest cluster to point #1, we now can fill the arrays with the cluster ID, x point value and y point value
        clusters_npoints_par[sample_id_new] ++;
        sumX_par[sample_id_new] += space[n].x;
        sumY_par[sample_id_new] += space[n].y;

        //Check if the algorith converged - if the points are associated to the same clusters
        converged_par = converged_par && sample_id_new == samples_id[n];
        samples_id[n] = sample_id_new;
    }
    #pragma omp critical
    {
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters_npoints[i] += clusters_npoints_par[i]; 
        sumX[i] += sumX_par[i]; 
        sumY[i] += sumY_par[i]; 
    }
    converged = converged && converged_par;
    }
    }


    //Compute new centroids according with arrays filled before
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters[i].x = sumX[i] / clusters_npoints[i];
        clusters[i].y = sumY[i] / clusters_npoints[i];
    }

    return converged;
}

void print_output(POINT* clusters, int* clusters_npoints, int iterations, int N_SAMPLES, int K_CLUSTERS){
    printf("N = %d, K = %d\n", N_SAMPLES, K_CLUSTERS);
    for(int i = 0; i < K_CLUSTERS; i++){
        printf("Center: (%.3f, %.3f) : Size: %d\n", clusters[i].x, clusters[i].y, clusters_npoints[i]);
    }
    printf("Iterations: %d\n", iterations);
}