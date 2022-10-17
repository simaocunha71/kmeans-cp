#include "../include/k_means.h"

void start_clusters(int n_samples, int k_clusters){
    POINT* samples_space = create_vector(n_samples);
    POINT* clusters = create_vector(k_clusters);

    fill(samples_space, clusters,n_samples, k_clusters);

    print_content(samples_space, clusters,n_samples, k_clusters);

}

//A CONSIDERAR: https://reasonabledeviations.com/2019/10/02/k-means-in-cpp/
int main (int argc, char const *argv[]){
    start_clusters(N_SAMPLES, K_CLUSTERS);
    return 0;
}
