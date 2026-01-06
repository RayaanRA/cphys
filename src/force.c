#include "force.h"

void grav_force_body(phys_body* body, phys_system* system) {
	for (int i = 0; i < system->count; i++) {
		if (&(system->bodies[i]) == body) {continue;}
		float dist = phys_vector2_dist(body->pos, (system->bodies[i]).pos);
	}
}