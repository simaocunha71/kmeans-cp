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