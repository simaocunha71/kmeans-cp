#include "../include/utils.h"

void k_means_seq (int N_SAMPLES, int K_CLUSTERS){
    POINT* samples_space = create_vector(N_SAMPLES);
    POINT* clusters = create_vector(K_CLUSTERS);
    int* samples_id = create_iarray(N_SAMPLES);
    int* clusters_npoints = create_iarray(K_CLUSTERS);
    fill(samples_space, clusters, samples_id, N_SAMPLES, K_CLUSTERS);
    int iterations = 0;
    int converged;
    
    do{
        converged = update_clusters(samples_space, clusters, samples_id, clusters_npoints, N_SAMPLES, K_CLUSTERS);
        iterations++;
    }while(iterations <= 20 && !converged);

    print_output(clusters, clusters_npoints, iterations-1, N_SAMPLES, K_CLUSTERS);

    free(samples_space);
    free(clusters);
    free(samples_id);
    free(clusters_npoints);
}

void k_means_par (int N_SAMPLES, int K_CLUSTERS, int THREADS){
    POINT* samples_space = create_vector(N_SAMPLES);
    POINT* clusters = create_vector(K_CLUSTERS);
    int* samples_id = create_iarray(N_SAMPLES);
    int* clusters_npoints = create_iarray(K_CLUSTERS);
    fill(samples_space, clusters, samples_id, N_SAMPLES, K_CLUSTERS);
    int iterations = 0;
    int converged;
    
    do{
        converged = update_clusters(samples_space, clusters, samples_id, clusters_npoints, N_SAMPLES, K_CLUSTERS);
        iterations++;
    }while(!converged);

    print_output(clusters, clusters_npoints, iterations-1, N_SAMPLES, K_CLUSTERS);

    free(samples_space);
    free(clusters);
    free(samples_id);
    free(clusters_npoints);
}

int main (int argc, char const *argv[]){

    if(argc == 3){
        //Sequential version with arguments
        int N_SAMPLES = atoi(argv[1]);
        int K_CLUSTERS = atoi(argv[2]);
        k_means_seq(N_SAMPLES, K_CLUSTERS);
    }
    else if(argc == 4){
        //Parallel version with arguments
        int N_SAMPLES = atoi(argv[1]);
        int K_CLUSTERS = atoi(argv[2]);
        int THREADS = atoi(argv[3]);
        k_means_par(N_SAMPLES, K_CLUSTERS, THREADS);
    }
    else
        //Sequential version without arguments
        k_means_seq(1000000, 4);
    return 0;
}
