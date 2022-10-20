#include "../include/k_means.h"

void k_means(int n_samples, int k_clusters){

    float* space_x = create_farray(n_samples);
    float* space_y = create_farray(n_samples);
    float* clusters_x = create_farray(k_clusters);
    float* clusters_y = create_farray(k_clusters);
    float* clusters_old_x = create_farray(k_clusters);
    float* clusters_old_y = create_farray(k_clusters);
    int* clusters_npoints = create_iarray(n_samples);
    
    fill(space_x,space_y, clusters_x, clusters_y,clusters_npoints);
    int iterations = 0;
    int equals = 0;
    while(!equals){
        iterations++;
        //printf("***Iteration %d***\n",iterations); //DEBUG
        copy_clusters(clusters_old_x,clusters_old_y, clusters_x,clusters_y,k_clusters);
        assign_cluster(space_x,space_y, clusters_x,clusters_y, clusters_npoints);
        equals = compare_centroids(clusters_old_x,clusters_old_y, clusters_x,clusters_y, k_clusters);
    }
    print_output(n_samples, k_clusters, clusters_x,clusters_y,clusters_npoints, iterations);
    
    free(space_x);
    free(space_y);
    free(clusters_x);
    free(clusters_y);
    free(clusters_npoints);
    free(clusters_old_x);
    free(clusters_old_y);
}

int main (int argc, char const *argv[]){
    k_means(N_SAMPLES, K_CLUSTERS);
    return 0;
}
