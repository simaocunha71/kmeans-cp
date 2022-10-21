#include "../include/k_means.h"

void k_means(){

    POINT* space = create_vector(N_SAMPLES);
    POINT* clusters = create_vector(K_CLUSTERS);
    POINT* clusters_old = create_vector(K_CLUSTERS);
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
    print_output(clusters,clusters_npoints, iterations-1);
    
    free(space);
    free(clusters);
    free(clusters_old);
    free(clusters_npoints);
    
}

int main (int argc, char const *argv[]){
    k_means();
    return 0;
}
