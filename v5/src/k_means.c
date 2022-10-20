#include "../include/k_means.h"

void k_means(int n_samples, int k_clusters){

    float* space = create_farray(n_samples*2);
    float* clusters = create_farray(k_clusters*2);
    float* clusters_old = create_farray(k_clusters*2);
    int* clusters_npoints = create_iarray(n_samples);
    
    fill(space,clusters);
    int iterations = 0;
    int equals = 0;
    while(!equals){
        iterations++;
        //printf("***Iteration %d***\n",iterations); //DEBUG
        copy_clusters(clusters_old, clusters);
        assign_cluster(space, clusters, clusters_npoints);
        equals = compare_centroids(clusters_old, clusters);
    }
    print_output(clusters,clusters_npoints, iterations);
    
    free(space);
    free(clusters);
    free(clusters_npoints);
    free(clusters_old);
}

int main (int argc, char const *argv[]){
    k_means(N_SAMPLES, K_CLUSTERS);
    return 0;
}
