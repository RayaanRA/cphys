#include "cphys.h"
#include <stdio.h>
#include <assert.h>

#define EPS 1e-9

int main(void) {
    phys_body bodies[2];

    phys_init_body(&bodies[0], (phys_vector2){0.0, 0.0}, (phys_vector2){0,0}, (phys_vector2){0,0}, 1.0);
    phys_init_body(&bodies[1], (phys_vector2){1.0, 0.0}, (phys_vector2){0,0}, (phys_vector2){0,0}, 1.0);

    phys_system system;
    phys_init_system(&system, bodies, 2);

    grav_force_system(&system);

    // force along x-axis
    assert(fabs(bodies[0].force.y) < EPS);
    assert(fabs(bodies[1].force.y) < EPS);
    assert(fabs(bodies[0].force.x + bodies[1].force.x) < EPS);
    printf("force test passed\n");

    accel_system(&system);

    assert(fabs(bodies[0].accel.x - bodies[0].force.x / bodies[0].mass) < EPS);
    assert(fabs(bodies[1].accel.x - bodies[1].force.x / bodies[1].mass) < EPS);
    printf("acceleration test passed\n");

    return 0;
}
