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
    }
    for(int i = 0; i < csize; i++) {
        clusters[i].x = space[i].x;
        clusters[i].y = space[i].y;
    }
}

void assign_cluster(POINT* space, POINT* clusters, int ssize, int csize){
    for(int i = 0; i < csize; i++) {
        int clusterID = -1;
        double minDist = MAX_DIST;
        for(int j = 0; j < ssize; j++) {
            double dist = euclidian_distance(space[j],clusters[i]);
            if (dist < minDist) {
                minDist = dist;
                clusterID = i;
            }
        }
    }
}

float euclidian_distance(POINT p1, POINT p2){
    return sqrt(pow(p2.y - p1.y, 2) + pow(p1.x - p1.y, 2));
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