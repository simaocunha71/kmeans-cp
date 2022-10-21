#include "../include/k_means.h"

void k_means(){

    float* space_x = create_farray(N_SAMPLES);
    float* space_y = create_farray(N_SAMPLES);
    float* clusters_x = create_farray(K_CLUSTERS);
    float* clusters_y = create_farray(K_CLUSTERS);
    float* clusters_old_x = create_farray(K_CLUSTERS);
    float* clusters_old_y = create_farray(K_CLUSTERS);
    int* clusters_npoints = create_iarray(N_SAMPLES);
    
    fill(space_x,space_y, clusters_x, clusters_y,clusters_npoints);
    int iterations = 0;
    int equals = 0;
    while(!equals){
        iterations++;
        //printf("***Iteration %d***\n",iterations); //DEBUG
        copy_clusters(clusters_old_x,clusters_old_y, clusters_x,clusters_y);
        update_clusters(space_x,space_y, clusters_x,clusters_y, clusters_npoints);
        equals = compare_centroids(clusters_old_x,clusters_old_y, clusters_x,clusters_y);
    }
    print_output(clusters_x,clusters_y,clusters_npoints, iterations-1);
    
    free(space_x);
    free(space_y);
    free(clusters_x);
    free(clusters_y);
    free(clusters_npoints);
    free(clusters_old_x);
    free(clusters_old_y);
}

int main (int argc, char const *argv[]){
    k_means();
    return 0;
}
