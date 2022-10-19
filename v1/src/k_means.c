#include "../include/k_means.h"

void k_means(int n_samples, int k_clusters){
    POINT* samples_space = create_vector(n_samples);
    POINT* clusters = create_vector(k_clusters);
    POINT* clusters_old = create_vector(k_clusters);
    fill(samples_space, clusters, n_samples, k_clusters);
    int iterations = 0;
    int equals = 0;
    while(!equals){
        iterations++;
        //printf("***Iteration %d***\n",iterations); //DEBUG
        copy_clusters(clusters_old, clusters,k_clusters);
        assign_cluster(samples_space, clusters, n_samples, k_clusters);
        calculate_centroids(samples_space, clusters, n_samples, k_clusters);
        equals = compare_centroids(clusters_old, clusters, k_clusters);
    }
    print_output(n_samples, k_clusters, clusters, iterations);

    free(samples_space);
    free(clusters);
    free(clusters_old);

}

int main (int argc, char const *argv[]){
    k_means(N_SAMPLES, K_CLUSTERS);
    return 0;
}
