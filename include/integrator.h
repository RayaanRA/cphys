#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "vector.h"
#include "body.h"
#include "force.h"

enum integrator {
	LEAPFROG
};

void integrate_step_system(phys_system* system, enum integrator integrator, double dt);
void leapfrog_step_system(phys_system* system, double dt);
#endif