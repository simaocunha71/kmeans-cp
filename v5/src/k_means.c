#include "../include/k_means.h"

void k_means(){

    float* space = create_farray(N_SAMPLES*2);
    float* clusters = create_farray(K_CLUSTERS*2);
    float* clusters_old = create_farray(K_CLUSTERS*2);
    int* clusters_npoints = create_iarray(N_SAMPLES);
    
    fill(space,clusters);
    int iterations = 0;
    int equals = 0;
    while(!equals){
        iterations++;
        //printf("***Iteration %d***\n",iterations); //DEBUG
        copy_clusters(clusters_old, clusters);
        update_clusters(space, clusters, clusters_npoints);
        equals = compare_centroids(clusters_old, clusters);
    }
    print_output(clusters,clusters_npoints, iterations);
    
    free(space);
    free(clusters);
    free(clusters_npoints);
    free(clusters_old);
}

int main (int argc, char const *argv[]){
    k_means();
    return 0;
}
