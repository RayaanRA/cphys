#include "force.h"

void grav_force_body(phys_body* body, phys_system* system) {
	body->force = (phys_vector2) {0, 0};
	for (size_t i = 0; i < system->count; i++) {
		if (&(system->bodies[i]) == body) {continue;}

		double dist = phys_vector2_dist(body->pos, (system->bodies[i]).pos);
		if (dist == 0.0f) {continue;}
		phys_vector2 displacement = phys_vector2_sub(body->pos, (system->bodies[i]).pos);

		double inv_dist = 1.0f / dist;
		double scalar_factor = -G * body->mass * (system->bodies[i]).mass * (inv_dist * inv_dist * inv_dist);
		
		phys_vector2 force = phys_scalar_mult(scalar_factor, displacement);
		// TODO: add force softening
		body->force = phys_vector2_add(body->force, force);
	}
}

void grav_force_system(phys_system* system) {
	for (size_t i = 0; i < system->count; i++) {
		grav_force_body(&(system->bodies[i]), system);
	}
}

void accel_body(phys_body* body) {
	body->accel = phys_scalar_mult(1.0 / body->mass, body->force);
}

void accel_system(phys_system* system) {
	for (size_t i = 0; i < system->count; i++) {
		accel_body(&(system->bodies[i]));
	}
}