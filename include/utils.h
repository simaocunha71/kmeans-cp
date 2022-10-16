#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Create matrix
 * @param size Number of lines and columns
 * @return float** Matrix
 */
float** create_matrix(int size);


/**
 * @brief Fill sample's space with random values and fill clusters' matrix
 * @param space Sample's space
 * @param clusters Clusters' matrix
 * @param ssize Size of sample's space
 * @param ssize Size of clusters' matrix
 */
void fill(float** space, float** clusters, int ssize, int csize);

//debug
void print_content(float** space, float** clusters, int ssize, int csize);