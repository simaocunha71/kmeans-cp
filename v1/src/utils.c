#include "../include/utils.h"

POINT* create_vector(int size){
    POINT* vec = (POINT*)malloc(size * sizeof(struct point));
    return vec;
}

void fill(POINT* space, POINT* clusters, int ssize, int csize){
    srand(10);
    for(int i = 0; i < ssize; i++) {
        space[i].x = (float) rand() / RAND_MAX;
        space[i].y = (float) rand() / RAND_MAX;
        space[i].min_dist = MAX_DIST;
        space[i].cluster_id = -1;
    }
    for(int i = 0; i < csize; i++) {
        clusters[i].x = space[i].x;
        clusters[i].y = space[i].y;
        clusters[i].cluster_id = -1;
        clusters[i].min_dist = -1;

    }
}

void assign_cluster(POINT* space, POINT* clusters, int ssize, int csize){
    for(int i = 0; i < csize; i++) {
        for(int j = 0; j < ssize; j++) {
            double dist = euclidian_distance(space[j],clusters[i]);
            if (dist < space[j].min_dist) {
                space[j].min_dist = dist;
                space[j].cluster_id = i;
            }
        }
    }
}

float euclidian_distance(POINT p1, POINT p2){
    return sqrt(pow(p2.y - p1.y, 2) + pow(p2.x - p1.x, 2));
}

void calculate_centroids(POINT* space, POINT* clusters, int ssize, int csize){
    int* nPoints = (int *) malloc(csize * sizeof(int));
    float* sumX = (float *) malloc(csize * sizeof(float));
    float* sumY = (float *) malloc(csize * sizeof(float));

    // Initialise arrays with zeros
    for (int i = 0; i < csize; i++) {
        nPoints[i] = 0;
        sumX[i] = 0.0;
        sumY[i] = 0.0;
    }

    // Iterate over points from data space to append data to centroids
    for (int i = 0; i < ssize; i++) {
        int clusterId = space[i].cluster_id;
        nPoints[clusterId] += 1;
        sumX[clusterId] += space[i].x;
        sumY[clusterId] += space[i].y;

        space[i].min_dist = MAX_DIST;  // reset distance
    }

    // Compute the new centroids
    for (int i = 0; i < csize; i++) {
        //printf("cox%d(%.5f) | ", i,clusters[i].x); //DEBUG

        clusters[i].x = sumX[i] / nPoints[i];

        //printf("cnx%d(%.5f) || ", i,clusters[i].x); //DEBUG
        //printf("coy%d(%.5f) | ", i,clusters[i].y); //DEBUG

        clusters[i].y = sumY[i] / nPoints[i];
        clusters[i].cluster_id = nPoints[i];

        //printf("cny%d(%.5f)\n", i,clusters[i].y); //DEBUG
    }

    free(nPoints);
    free(sumX); free(sumY);
}

int compare_centroids(POINT* clusters_old, POINT* clusters_new, int csize){
    int equals = 1;
    for(int i = 0; i < csize && equals; i++){
        if(clusters_old[i].x != clusters_new[i].x || clusters_old[i].y != clusters_new[i].y)
            equals = 0;
    }
    return equals;
}

void copy_clusters(POINT* cluster, POINT* cluster_to_copy, int csize){
    for (int i = 0; i < csize; i++){
        cluster[i].x = cluster_to_copy[i].x;
        cluster[i].y = cluster_to_copy[i].y;
    }
}

void print_output(int n_samples, int k_clusters, POINT* clusters, int iterations){
    printf("N = %d, K = %d\n", n_samples, k_clusters);
    for(int i = 0; i < k_clusters; i++){
        printf("Center: (%.3f, %.3f) : Size: %d\n", clusters[i].x, clusters[i].y, clusters[i].cluster_id);
    }
    printf("Iterations: %d\n", iterations);
}