#include "../include/utils.h"

int main (int argc, char const *argv[]){
    float* space_x = create_farray(N_SAMPLES);
    float* space_y = create_farray(N_SAMPLES);

    float* clusters_x = create_farray(K_CLUSTERS);
    float* clusters_y = create_farray(K_CLUSTERS);

    int* samples_id = create_iarray(N_SAMPLES);
    int* clusters_npoints = create_iarray(K_CLUSTERS);

    fill(space_x, space_y, clusters_x, clusters_y, samples_id);
    int iterations = 0;
    int converged = 0;
    while(!converged){
        //printf("***Iteration %d***\n",iterations); //DEBUG
        converged = update_clusters(space_x, space_y, clusters_x, clusters_y, samples_id, clusters_npoints);
        iterations++;
    }
    print_output(clusters_x, clusters_y, clusters_npoints, iterations-1);

    free(space_x);
    free(space_y);
    free(clusters_x);
    free(clusters_y);
    free(samples_id);
    free(clusters_npoints);
    return 0;
}
