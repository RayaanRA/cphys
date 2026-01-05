#include "vector.h"

phys_vector2 phys_vector2_add(phys_vector2 a, phys_vector2 b) {
	return (phys_vector2) {(a.x + b.x), (a.y + b.y)};
}

phys_vector2 phys_vector2_sub(phys_vector2 a, phys_vector2 b) {
	return (phys_vector2) {(a.x - b.x), (a.y - b.y)};
}

float phys_vector2_mag(phys_vector2 a) {
	return sqrtf(a.x * a.x + a.y * a.y);
}

float phys_vector2_dist(phys_vector2 a, phys_vector2 b) {
	return phys_vector2_mag(phys_vector2_sub(a, b));
}