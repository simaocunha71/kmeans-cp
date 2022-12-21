#include "../include/utils.h"


float* create_farray(int size){
    float* arr = (float*)malloc(size * sizeof(float));
    return arr;
}

int* create_iarray(int size){
    int* arr = (int*)malloc(size * sizeof(int));
    return arr;
}


void fill(float* space_x,float* space_y, float* clusters_x,float* clusters_y, int* samples_id){
    srand(10);
    for(int i = 0; i < N_SAMPLES; i++) {
        space_x[i] = (float) rand() / RAND_MAX;
        space_y[i] = (float) rand() / RAND_MAX;
        samples_id[i] = -1;
    }
    for(int i = 0; i < K_CLUSTERS; i++) {
        clusters_x[i] = space_x[i];
        clusters_y[i] = space_y[i];
    }
}

int update_clusters(float* space_x,float* space_y, float* clusters_x,float* clusters_y, int* samples_id, int* clusters_npoints, int nProcesses, int atualRank, MPI_Status status){
    float sumX[K_CLUSTERS];
    float sumY[K_CLUSTERS];
    float min_dist;
    float dist;

    float cx, cy, sx, sy;
    int sample_id_new;
    int converged = 1;

    //Auxiliary variables to use in child processes
    float sumX_aux[K_CLUSTERS];
    float sumY_aux[K_CLUSTERS];
    int clusters_npoints_aux[K_CLUSTERS];
    int converged_aux = 1;

    // Initialise arrays with zeros
    for (int i = 0; i < K_CLUSTERS; i++) {
        clusters_npoints[i] = 0;
        sumX[i] = 0.0;
        sumY[i] = 0.0;
    }

    //Size of block destinated to each process
    int work_block = N_SAMPLES/nProcesses; 

    int MAX_ITERATIONS = work_block*(atualRank + 1);

    if(atualRank == nProcesses - 1){
        MAX_ITERATIONS += N_SAMPLES % nProcesses; //Last process does the work to the block that wasn't attributed to anyone
    }
    
    //Assign points 
    for(int n = work_block*atualRank; n < MAX_ITERATIONS; n++) {
        sx = space_x[n];
        sy = space_y[n];
        cx = clusters_x[0];
        cy = clusters_y[0];
        min_dist = (cy - sy) * (cy - sy) + (cx - sx) * (cx - sx);
        sample_id_new = 0;
        for(int k = 1; k < K_CLUSTERS; k++) {
            cx = clusters_x[k];
            cy = clusters_y[k];
            dist = (cy - sy) * (cy - sy) + (cx - sx) * (cx - sx);
            if (dist < min_dist) {
                min_dist = dist;
                sample_id_new = k;
            }
        }
        clusters_npoints[sample_id_new] ++;
        sumX[sample_id_new] += space_x[n];
        sumY[sample_id_new] += space_y[n];

        converged = converged && sample_id_new == samples_id[n];
        samples_id[n] = sample_id_new;
    }

    if(atualRank == 0){
        for(int i = 1; i < nProcesses; i++){
            //Receive arrays and converge variable from child processes
            MPI_Recv(sumX_aux, K_CLUSTERS, MPI_FLOAT, i, 0, MPI_COMM_WORLD, &status);
            MPI_Recv(sumY_aux, K_CLUSTERS, MPI_FLOAT, i, 0, MPI_COMM_WORLD, &status);
            MPI_Recv(clusters_npoints_aux, K_CLUSTERS, MPI_INT, i, 0, MPI_COMM_WORLD, &status);
            MPI_Recv(&converged_aux, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &status);

            //Update variables from master node
            for(int j = 0; j < K_CLUSTERS; j++){
                sumX[j] += sumX_aux[j];
                sumY[j] += sumY_aux[j];
                clusters_npoints[j] += clusters_npoints_aux[j];
            }
            converged = converged && converged_aux;
        }

        //Compute new centroids
        for (int i = 0; i < K_CLUSTERS; i++) {
            clusters_x[i] = sumX[i] / clusters_npoints[i];
            clusters_y[i] = sumY[i] / clusters_npoints[i];
        }
        
        //Broadcast the updated values to the child nodes
        MPI_Bcast(clusters_x, K_CLUSTERS, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(clusters_y, K_CLUSTERS, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Bcast(&converged, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }
    else{
       //Send arrays and converge variable from each node to master node
       MPI_Send(sumX, K_CLUSTERS, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
       MPI_Send(sumY, K_CLUSTERS, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
       MPI_Send(clusters_npoints, K_CLUSTERS, MPI_INT, 0, 0, MPI_COMM_WORLD);
       MPI_Send(&converged, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);

       //Receive updated arrays and converge variable from master node
       MPI_Bcast(clusters_x, K_CLUSTERS, MPI_FLOAT, 0, MPI_COMM_WORLD);
       MPI_Bcast(clusters_y, K_CLUSTERS, MPI_FLOAT, 0, MPI_COMM_WORLD);
       MPI_Bcast(&converged, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }

    return converged;
}


void copy_samplesid(int* samples_id, int* samples_id_to_copy){
    for (int i = 0; i < N_SAMPLES; i++){
        samples_id[i] = samples_id_to_copy[i];
    }
}

void print_output(float* clusters_x,float* clusters_y, int* clusters_npoints, int iterations){
    printf("N = %d, K = %d\n", N_SAMPLES, K_CLUSTERS);
    for(int i = 0; i < K_CLUSTERS; i++){
        printf("Center: (%.3f, %.3f) : Size: %d\n", clusters_x[i], clusters_y[i], clusters_npoints[i]);
    }
    printf("Iterations: %d\n", iterations);
}