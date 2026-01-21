#include "body.h"

void phys_init_body(phys_body* body, phys_vector2 pos, phys_vector2 vel, phys_vector2 accel, double mass) {
	body->pos = pos;
	body->vel = vel;
	body->accel = accel;
	body->mass = mass;
	body->force = (phys_vector2) {0, 0};
}

void phys_init_system(phys_system* system, phys_body* bodies, size_t count, double softening, double G) {
	system->bodies = bodies;
	system->count = count;
	system->softening = softening;
	system->G = G;
}