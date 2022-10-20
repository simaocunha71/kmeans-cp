#include "../include/k_means.h"

void k_means(){
    POINT* samples_space = create_vector(N_SAMPLES);
    POINT* clusters = create_vector(K_CLUSTERS);
    POINT* clusters_old = create_vector(K_CLUSTERS);
    fill(samples_space, clusters);
    int iterations = 0;
    int equals = 0;
    while(!equals){
        iterations++;
        //printf("***Iteration %d***\n",iterations); //DEBUG
        copy_clusters(clusters_old, clusters);
        assign_cluster(samples_space, clusters);
        calculate_centroids(samples_space, clusters);
        equals = compare_centroids(clusters_old, clusters);
    }
    print_output(clusters, iterations);

    free(samples_space);
    free(clusters);
    free(clusters_old);

}

int main (int argc, char const *argv[]){
    k_means();
    return 0;
}
