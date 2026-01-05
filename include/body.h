#ifndef BODY_H
#define BODY_H

#include "vector.h"

typedef struct phys_body {
	phys_vector2 pos;
	phys_vector2 vel;
	phys_vector2 accel;
	float mass;
	float force;

} phys_body;

typedef struct phys_system {
	phys_body* bodies;
	size_t count;
} phys_system;

void phys_init_body(phys_body* body, phys_vector2 pos, phys_vector2 vel, phys_vector2 accel, float mass);
void phys_init_system(phys_system* system, phys_body* bodies, size_t count);

#endif