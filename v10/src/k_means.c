#include <stdio.h>
#include <stdlib.h>
#include "../include/utils.h"

int main (int argc, char const *argv[]){
    
    float* space_x = create_farray(N_SAMPLES);
    float* space_y = create_farray(N_SAMPLES);
    float* clusters_x = create_farray(K_CLUSTERS);
    float* clusters_y = create_farray(K_CLUSTERS);
    int* clusters_npoints = create_iarray(N_SAMPLES);
    
    fill(space_x,space_y,clusters_x,clusters_y);
    int iterations = 0;

    int updated = 0;
    /*
    int equals = 0;
    while(!equals){
        iterations++;
        //printf("***Iteration %d***\n",iterations); //DEBUG
        equals = update_clusters(space, clusters, clusters_npoints);
    }
    */

    do{
        updated = update_clusters(space_x,space_y,clusters_x,clusters_y, clusters_npoints);
        iterations++;
    } while(!updated);


    print_output(clusters_x,clusters_y,clusters_npoints, iterations-1);
    
    free(space_x);
    free(space_y);
    free(clusters_x);
    free(clusters_y);
    free(clusters_npoints);
    
    return 0;
}
