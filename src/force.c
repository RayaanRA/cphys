#include "force.h"

void grav_force_body(phys_body* body, phys_system* system) {
    body->force = (phys_vector2){0, 0};
    double softening_squared = system->softening * system->softening;

    for (size_t i = 0; i < system->count; i++) {
        phys_body* other_body = &system->bodies[i];
        if (other_body == body) continue;

        phys_vector2 displacement_vector = phys_vector2_sub(body->pos, other_body->pos);
        double distance_squared = phys_vector2_mag2(displacement_vector);
        double inverse_distance_cubed = 1.0 / pow(distance_squared + softening_squared, 1.5);

        double force_scalar = -G * body->mass * other_body->mass * inverse_distance_cubed;
        phys_vector2 force_vector = phys_scalar_mult(force_scalar, displacement_vector);
        body->force = phys_vector2_add(body->force, force_vector);
    }
}

void grav_force_system(phys_system* system) {
    for (size_t i = 0; i < system->count; i++) {
        grav_force_body(&system->bodies[i], system);
    }
}

void accel_body(phys_body* body) {
    body->accel = phys_scalar_mult(1.0 / body->mass, body->force);
}

void accel_system(phys_system* system) {
    for (size_t i = 0; i < system->count; i++) {
        accel_body(&system->bodies[i]);
    }
}

phys_vector2 system_total_momentum(phys_system* system) {
    phys_vector2 total_momentum = {0, 0};
    for (size_t i = 0; i < system->count; i++) {
        phys_body* body = &system->bodies[i];
        phys_vector2 body_momentum = phys_scalar_mult(body->mass, body->vel);
        total_momentum = phys_vector2_add(total_momentum, body_momentum);
    }
    return total_momentum;
}

double system_total_energy(phys_system* system) {
    double total_kinetic_energy = 0.0;
    double total_potential_energy = 0.0;
    double softening_squared = system->softening * system->softening;

    // kinetic energy
    for (size_t i = 0; i < system->count; i++) {
        phys_body* body = &system->bodies[i];
        double kinetic_energy_body = 0.5 * body->mass * phys_vector2_mag2(body->vel);
        total_kinetic_energy += kinetic_energy_body;
    }

    // potential energy
    for (size_t i = 0; i < system->count; i++) {
        for (size_t j = i + 1; j < system->count; j++) {
            phys_body* body_i = &system->bodies[i];
            phys_body* body_j = &system->bodies[j];

            phys_vector2 displacement_vector = phys_vector2_sub(body_i->pos, body_j->pos);
            double distance_squared = phys_vector2_mag2(displacement_vector);
            double softened_distance = sqrt(distance_squared + softening_squared);

            double potential_energy_pair = -G * body_i->mass * body_j->mass / softened_distance;
            total_potential_energy += potential_energy_pair;
        }
    }

    return total_kinetic_energy + total_potential_energy;
}
