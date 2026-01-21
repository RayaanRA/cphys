# cphys
A physics library for 2D Newtonian N-body simulations.  

## Usage

```c
#include "cphys.h"

phys_body bodies[2];
phys_init_body(&bodies[0], (phys_vector2){0,0}, (phys_vector2){1,0}, (phys_vector2){0,0}, 1.0);
phys_init_body(&bodies[1], (phys_vector2){1,0}, (phys_vector2){-1,0}, (phys_vector2){0,0}, 1.0);

phys_system system;
phys_init_system(&system, bodies, 2, 1.0, 0.01); // characteristic length, softening fraction

grav_force_system(&system);
accel_system(&system);

for (int step = 0; step < 100; step++) {
    integrate_step_system(&system, LEAPFROG, 0.01);
}
```

## Dependencies  

- `libm` for `<math.h>`


## Notes

- Direct summation of forces  
- Leapfrog integration requires precomputed acceleration before first step  
- Force softening is relative to a given characteristic length

---
See [an implementation of this library](https://github.com/RayaanRA/n-body-simulator)