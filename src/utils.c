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
        clusters[i].min_dist = -1;
        clusters[i].cluster_id = -1;
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
    return sqrt(pow(p2.y - p1.y, 2) + pow(p1.x - p1.y, 2));
}

void calculate_centroids(POINT* space, POINT* clusters, int ssize, int csize){
    int nPoints[csize];
    float sumX[csize];
    float sumY[csize];

    // Initialise with zeros
    for (int i = 0; i < csize; i++) {
        nPoints[i] = 0;
        sumX[i] = 0.0;
        sumY[i] = 0.0;
    }

    // Iterate over points to append data to centroids
    for (int i = 0; i < ssize; i++) {
        int clusterId = space[i].cluster_id;
        nPoints[clusterId] += 1;
        sumX[clusterId] += space[i].x;
        sumY[clusterId] += space[i].y;

        space[i].min_dist = MAX_DIST;  // reset distance
    }

    // Compute the new centroids
    for (int i = 0; i < csize; i++) {
        clusters[i].x = sumX[i] / nPoints[i];
        clusters[i].y = sumY[i] / nPoints[i];
    }
}

int compare_centroids(POINT* clusters_old, POINT* clusters_new, int csize){
    int equals = 1;
    for(int i = 0; i < csize && equals; i++){
        if(clusters_old[i].x != clusters_new[i].x || clusters_old[i].y != clusters_new[i].y)
            equals = 0;
    }
    return equals;
}

//debug
void print_content(POINT* space, POINT* clusters, int ssize, int csize){
    printf("################## SAMPLES ##################\n");
    for(int i = 0; i < ssize; i++) {
        printf("(%.2f, %.2f) ", space[i].x, space[i].y);
    }
    printf("\n################## Clusters ##################\n");
    for(int i = 0; i < csize; i++) {
        printf("(%.2f, %.2f) ", space[i].x, space[i].y);
    }
    printf("\n");
}