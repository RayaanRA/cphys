#include "vector.h"

phys_vector2 phys_vector2_add(phys_vector2 a, phys_vector2 b) {
	return (phys_vector2) {(a.x + b.x), (a.y + b.y)};
}