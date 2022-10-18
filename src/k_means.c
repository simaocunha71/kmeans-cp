#include "../include/k_means.h"

void k_means(int n_samples, int k_clusters){
    POINT* samples_space = create_vector(n_samples);
    POINT* clusters = create_vector(k_clusters);
    fill(samples_space, clusters, n_samples, k_clusters);
    assign_cluster(samples_space, clusters, n_samples, k_clusters);

    POINT* clusters_old = clusters;
    
    int iterations = 0;

    while(compare_centroids(clusters_old, clusters, k_clusters) == 0){
        calculate_centroids(samples_space, clusters, n_samples, k_clusters);
        iterations++;
    }



    printf("Iterations = %d\n", iterations);

}

//A CONSIDERAR: https://reasonabledeviations.com/2019/10/02/k-means-in-cpp/
int main (int argc, char const *argv[]){
    k_means(N_SAMPLES, K_CLUSTERS);
    return 0;
}
