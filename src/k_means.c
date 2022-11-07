#include "../include/utils.h"

int main (int argc, char const *argv[]){
    int N_SAMPLES = atoi(argv[1]);
    int K_CLUSTERS = atoi(argv[2]);
    int N_THREADS = atoi(argv[3]);
    POINT* samples_space = create_vector(N_SAMPLES);
    POINT* clusters = create_vector(K_CLUSTERS);
    int* samples_id = create_iarray(N_SAMPLES);
    int* clusters_npoints = create_iarray(K_CLUSTERS);
    fill(samples_space, clusters, samples_id);
    int iterations = 0;
    int converged;
    
    do{
        converged = update_clusters(samples_space, clusters, samples_id, clusters_npoints);
        iterations++;
    }while(!converged);

    print_output(clusters, clusters_npoints, iterations-1);

    free(samples_space);
    free(clusters);
    free(samples_id);
    free(clusters_npoints);
    return 0;
}
