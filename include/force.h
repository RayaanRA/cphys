#ifndef FORCE_H
#define FORCE_H

#include "vector.h"
#include "body.h"

#define G 1

void grav_force_body(phys_body* body, phys_system* system);

#endif