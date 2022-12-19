#include "../include/utils.h"

int main (int argc, char const *argv[]){
    int iterations = 0;
    
    MPI_Init(NULL, NULL);
    
	// get number of processes
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	// get rank
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    POINT* samples_space = create_vector(N_SAMPLES);
    POINT* clusters = create_vector(K_CLUSTERS);
    int* samples_id = create_iarray(N_SAMPLES);
    int* clusters_npoints = create_iarray(K_CLUSTERS);

    if(world_rank == 0){
        fill(samples_space, clusters, samples_id);
    }
    else { //Worker node

        float sumX[K_CLUSTERS];
        float sumY[K_CLUSTERS];
    
        int converged;
        do{
            converged = assign_points(samples_space, clusters, samples_id, clusters_npoints, sumX, sumY, world_size);
            if(world_rank == 0){
                compute_new_centroids(clusters, clusters_npoints, sumX, sumY);
            }
            iterations++;
        }while(!converged);
    }


    print_output(clusters, clusters_npoints, iterations);

    free(samples_space);
    free(clusters);
    free(samples_id);
    free(clusters_npoints);

    MPI_Finalize ();
    return 0;
}
