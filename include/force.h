#ifndef FORCE_H
#define FORCE_H

#include "vector.h"
#include "body.h"

#define G 1

void grav_force_body(phys_body* body, phys_system* system);
void grav_force_system(phys_system* system);
void accel_body(phys_body* body);
void accel_system(phys_system* system);
phys_vector2 system_total_momentum(phys_system* system);
double system_total_energy(phys_system* system);

#endif