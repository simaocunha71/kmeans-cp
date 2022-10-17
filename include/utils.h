#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DIST 10

/**
 * @brief Point struct
 */
typedef struct point {
    float x; //Value of x
    float y; //Value of y
} POINT;


/**
 * @brief Create a vector object
 * @param size Vector size
 * @return POINT* Vector allocated
 */
POINT* create_vector(int size);


/**
 * @brief Fill sample's space with random values and fill clusters' matrix
 * @param space Sample's space
 * @param clusters Clusters' vector
 * @param ssize Size of sample's space
 * @param ssize Size of clusters' vector
 */
void fill(POINT* space, POINT* clusters, int ssize, int csize);

/**
 * @brief Euclidian distance between two points
 * @param p1 Point 1
 * @param p2 Point 2
 * @return float Distance between Point 1 and Point 2
 */
float euclidian_distance(POINT p1, POINT p2);

void assign_cluster(POINT* space, POINT* clusters, int ssize, int csize);


//debug
void print_content(POINT* space, POINT* clusters, int ssize, int csize);