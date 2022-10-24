#include <stdio.h>
#include <stdlib.h>
#include "../include/utils.h"

int main (int argc, char const *argv[]){
    
    POINT* space = create_vector(N_SAMPLES);
    POINT* clusters = create_vector(K_CLUSTERS);
    int* clusters_npoints = create_iarray(N_SAMPLES);
    
    fill(space,clusters);
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
        updated = update_clusters(space, clusters, clusters_npoints);
        iterations++;
    } while(!updated);


    print_output(clusters,clusters_npoints, iterations-1);
    
    free(space);
    free(clusters);
    free(clusters_npoints);
    
    return 0;
}
