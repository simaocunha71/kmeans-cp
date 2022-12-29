#include "../include/utils.h"

int main (int argc, char** argv){
	MPI_Init(&argc, &argv);
    MPI_Status status;

    int N_SAMPLES = atoi(argv[1]);
    int K_CLUSTERS = atoi(argv[2]);

	//Get the number of processes in use
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	//Get rank from a certain process
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    //Not only the process main must allocate space, but also his child processes
    float* space_x = create_farray(N_SAMPLES);
    float* space_y = create_farray(N_SAMPLES);

    float* clusters_x = create_farray(K_CLUSTERS);
    float* clusters_y = create_farray(K_CLUSTERS);

    int* samples_id = create_iarray(N_SAMPLES);
    int* clusters_npoints = create_iarray(K_CLUSTERS);

    if(world_rank == 0){
        //Master node is encharged to fill the original arrays and sends them to his children
        fill(space_x, space_y, clusters_x, clusters_y, samples_id, N_SAMPLES, K_CLUSTERS);
        MPI_Bcast(&N_SAMPLES, 1, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Bcast(&K_CLUSTERS, 1, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Bcast(space_x, N_SAMPLES, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(space_y, N_SAMPLES, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(clusters_x, K_CLUSTERS, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(clusters_y, K_CLUSTERS, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(samples_id, N_SAMPLES, MPI_INT, 0, MPI_COMM_WORLD);
    }
    else{
        //Child processes received arrays from master node
        MPI_Bcast(&N_SAMPLES, 1, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Bcast(&K_CLUSTERS, 1, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Bcast(space_x, N_SAMPLES, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(space_y, N_SAMPLES, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(clusters_x, K_CLUSTERS, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(clusters_y, K_CLUSTERS, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(samples_id, N_SAMPLES, MPI_INT, 0, MPI_COMM_WORLD);
    }

    int iterations = 0;
    int converged;
    do{
        converged = update_clusters(space_x, space_y, clusters_x, clusters_y, samples_id, clusters_npoints, world_size, world_rank, status,  N_SAMPLES, K_CLUSTERS);
        iterations++;
    }while(!converged);

    //Onlu the masted node will show the results obtained from the children
    if(world_rank == 0)
        print_output(clusters_x, clusters_y, clusters_npoints, iterations-1,  N_SAMPLES, K_CLUSTERS);

    free(space_x);
    free(space_y);
    free(clusters_x);
    free(clusters_y);
    free(samples_id);
    free(clusters_npoints);
	MPI_Finalize();
    return 0;
}
