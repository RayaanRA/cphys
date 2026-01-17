#include "cphys.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv) {

	phys_vector2 vector_one = (phys_vector2) {3.0, 4.0};
	phys_vector2 vector_two = (phys_vector2) {2.0, 4.0};
	phys_vector2 add_test = phys_vector2_add(vector_one, vector_two);
	assert(add_test.x == 5.0 && add_test.y == 8.0);
	printf("vector addition passed\n");

	phys_vector2 sub_test = phys_vector2_sub(vector_one, vector_two);
	assert(sub_test.x == 1.0 && sub_test.y == 0.0);
	printf("vector subtraction passed\n");

	double mag_test = phys_vector2_mag(vector_one);
	assert(mag_test == 5.0);
	printf("vector magnitude passed\n");

	double dist_test = phys_vector2_dist(vector_one, vector_two);
	assert(dist_test == 1.0);
	printf("vector distance passed\n");

	phys_vector2 mult_test = phys_scalar_mult(5.0, vector_one);
	assert(mult_test.x == 15.0 && mult_test.y == 20.0);
	printf("vector-scalar multiplication passed\n");

	printf("all tests passed\n");

	return 0;
}