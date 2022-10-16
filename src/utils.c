#include "../include/utils.h"

float** create_matrix(int size){
    float** mat = (float**)malloc(size * sizeof(float*));
    for (int i = 0; i < size; i++)
        mat[i] = (float*)malloc(size * sizeof(float));
    return mat;
}

void fill(float** space, float** clusters, int ssize, int csize){
    srand(10);
    for(int i = 0; i < ssize; i++) {
        for(int j = 0; j < ssize; j++){
            space[i][j] = (float) rand() / RAND_MAX;
        }
    }
    for(int i = 0; i < csize; i++) {
        for(int j = 0; j < csize; j++){
            clusters[i][j] = space[i][j];
        }
    }
}

//debug
void print_content(float** space, float** clusters, int ssize, int csize){
    printf("#################### SAMPLES ####################\n");
    for(int i = 0; i < ssize; i++) {
        for(int j = 0; j < ssize; j++){
            printf("%.2f ", space[i][j]);
        }
        printf("\n");
    }
    printf("\n#################### CLUSTERS ####################\n");
    for(int i = 0; i < csize; i++) {
        for(int j = 0; j < csize; j++){
            printf("%.2f ", clusters[i][j]);
        }
        printf("\n");
    }
}