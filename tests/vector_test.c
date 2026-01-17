#include "cphys.h"
#include <stdio.h>
#include <assert.h>

#define EPS 1e-9

int main(void) {

    phys_vector2 vector_one = (phys_vector2){3.0, 4.0};
    phys_vector2 vector_two = (phys_vector2){2.0, 4.0};

    phys_vector2 add_test = phys_vector2_add(vector_one, vector_two);
    assert(fabs(add_test.x - 5.0) < EPS && fabs(add_test.y - 8.0) < EPS);
    printf("vector addition passed\n");

    phys_vector2 sub_test = phys_vector2_sub(vector_one, vector_two);
    assert(fabs(sub_test.x - 1.0) < EPS && fabs(sub_test.y - 0.0) < EPS);
    printf("vector subtraction passed\n");

    double mag_test = phys_vector2_mag(vector_one);
    assert(fabs(mag_test - 5.0) < EPS);
    printf("vector magnitude passed\n");

    double dist_test = phys_vector2_dist(vector_one, vector_two);
    assert(fabs(dist_test - 1.0) < EPS);
    printf("vector distance passed\n");

    phys_vector2 mult_test = phys_scalar_mult(5.0, vector_one);
    assert(fabs(mult_test.x - 15.0) < EPS && fabs(mult_test.y - 20.0) < EPS);
    printf("vector-scalar multiplication passed\n");

    printf("all tests passed\n");

    return 0;
}
