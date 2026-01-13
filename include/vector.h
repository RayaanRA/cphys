#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <math.h>

typedef struct phys_vector2 {
	double x;
	double y;
} phys_vector2;

phys_vector2 phys_vector2_add(phys_vector2 a, phys_vector2 b);
phys_vector2 phys_vector2_sub(phys_vector2 a, phys_vector2 b);
double phys_vector2_mag(phys_vector2 a);
double phys_vector2_dist(phys_vector2 a, phys_vector2 b);
phys_vector2 phys_scalar_mult(double a, phys_vector2 b);

#endif