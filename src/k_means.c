#include "../include/utils.h"

int main (int argc, char** argv){
	// initialize the MPI environment
	MPI_Init(&argc, &argv);
    MPI_Status status;

	// get number of processes
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	// get rank
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    //Todos os processos tem de alocar espaço e nao apenas o processo main
    float* space_x = create_farray(N_SAMPLES);
    float* space_y = create_farray(N_SAMPLES);

    float* clusters_x = create_farray(K_CLUSTERS);
    float* clusters_y = create_farray(K_CLUSTERS);

    int* samples_id = create_iarray(N_SAMPLES);
    int* clusters_npoints = create_iarray(K_CLUSTERS);

    if(world_rank == 0){
        fill(space_x, space_y, clusters_x, clusters_y, samples_id);
        MPI_Bcast(space_x, N_SAMPLES, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(space_y, N_SAMPLES, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(clusters_x, K_CLUSTERS, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(clusters_y, K_CLUSTERS, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(samples_id, K_CLUSTERS, MPI_INT, 0, MPI_COMM_WORLD);
    }
    else{
        //Processos filho recebem os mesmos dados que os do processo main
        MPI_Bcast(space_x, N_SAMPLES, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(space_y, N_SAMPLES, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(clusters_x, K_CLUSTERS, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(clusters_y, K_CLUSTERS, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(samples_id, K_CLUSTERS, MPI_INT, 0, MPI_COMM_WORLD);
    }

    //Todos os processos entram nas funçoes abaixo
    int iterations = 0;
    int converged;
    do{
        converged = update_clusters(space_x, space_y, clusters_x, clusters_y, samples_id, clusters_npoints, world_size, world_rank, status);
        iterations++;
    }while(!converged);

    if(world_rank == 0) //Processo main vai receber os resultados dos processos filho - e só se imprime 1x
        print_output(clusters_x, clusters_y, clusters_npoints, iterations-1);

    free(space_x);
    free(space_y);
    free(clusters_x);
    free(clusters_y);
    free(samples_id);
    free(clusters_npoints);
	MPI_Finalize();
    return 0;
}
