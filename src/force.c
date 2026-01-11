#include "force.h"

void grav_force_body(phys_body* body, phys_system* system) {
	for (int i = 0; i < system->count; i++) {
		if (&(system->bodies[i]) == body) {continue;}

		float dist = phys_vector2_dist(body->pos, (system->bodies[i]).pos);
		if (dist == 0.0f) {continue;}
		phys_vector2 displacement = phys_vector2_sub(body->pos, (system->bodies[i]).pos);

		float inv_dist = 1.0f / dist;
		float scalar_factor = -G * body->mass * (system->bodies[i]).mass * (inv_dist * inv_dist * inv_dist);
		
		phys_vector2 force = phys_scalar_mult(scalar_factor, displacement);
		body->force = phys_vector2_add(body->force, force);
	}
}

void grav_force_system(phys_system* system) {
	for (int i = 0; i < system->count; i++) {
		grav_force_body(&(system->bodies[i]), system);
	}
}
