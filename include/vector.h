#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct phys_vector2 {
	float x;
	float y;
} phys_vector2;

phys_vector2 phys_vector2_add(phys_vector2 a, phys_vector2 b);

#endif