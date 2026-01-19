#include "vector.h"

phys_vector2 phys_vector2_add(phys_vector2 a, phys_vector2 b) {
	return (phys_vector2) {(a.x + b.x), (a.y + b.y)};
}

phys_vector2 phys_vector2_sub(phys_vector2 a, phys_vector2 b) {
	return (phys_vector2) {(a.x - b.x), (a.y - b.y)};
}

double phys_vector2_mag(phys_vector2 a) {
	return sqrt(a.x * a.x + a.y * a.y);
}

double phys_vector2_mag2(phys_vector2 a) {
    return a.x * a.x + a.y * a.y;
}

double phys_vector2_dist(phys_vector2 a, phys_vector2 b) {
	return phys_vector2_mag(phys_vector2_sub(a, b));
}

phys_vector2 phys_scalar_mult(double a, phys_vector2 b) {
	return (phys_vector2) {b.x * a, b.y * a};
}
