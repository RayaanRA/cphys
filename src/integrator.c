#include "integrator.h"

void integrate_step_system(phys_system* system, enum integrator integrator, double dt) {
	switch(integrator) {
		case LEAPFROG:
			leapfrog_step_system(system, dt);
			break;
		default:
			break;
	}
}

void leapfrog_step_system(phys_system* system, double dt) {
	double dt_half = dt * 0.5;
	// kick
	for (size_t i = 0; i < system->count; i++) {
		phys_body* body = &system->bodies[i];
		body->vel = phys_vector2_add(body->vel, phys_scalar_mult(dt_half, body->accel));
	}

	// drift
	for (size_t i = 0; i < system->count; i++) {
		phys_body* body = &system->bodies[i];
		body->pos = phys_vector2_add(body->pos, phys_scalar_mult(dt, body->vel));
	}

	grav_force_system(system);
	accel_system(system);

	// kick
	for (size_t i = 0; i < system->count; i++) {
		phys_body* body = &system->bodies[i];
		body->vel = phys_vector2_add(body->vel, phys_scalar_mult(dt_half, body->accel));
	}
}
