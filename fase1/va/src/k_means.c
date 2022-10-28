#include "../include/utils.h"

int main (int argc, char const *argv[]){
    POINT* samples_space = create_vector(N_SAMPLES);
    POINT* clusters = create_vector(K_CLUSTERS);
    int* samples_id = create_iarray(N_SAMPLES);
    int* samples_id_old = create_iarray(N_SAMPLES);
    int* clusters_npoints = create_iarray(K_CLUSTERS);
    fill(samples_space, clusters);
    int iterations = 0;
    int converged = 0;
    while(!converged){
        //printf("***Iteration %d***\n",iterations); //DEBUG
        copy_samplesid(samples_id_old, samples_id);
        update_clusters(samples_space, clusters, samples_id, clusters_npoints);
        converged = has_converged(samples_id_old, samples_id);
        iterations++;
    }
    print_output(clusters, clusters_npoints, iterations-1);

    free(samples_space);
    free(clusters);
    free(samples_id);
    free(samples_id_old);
    free(clusters_npoints);
    return 0;
}
