#ifndef NEAREST_NEIGHBOR
#define NEAREST_NEIGHBOR

#include "cityData.hpp"
#include <cstddef>
#include <iostream>

int nearestNeighbor (int* T, struct city* G, int numCities);

struct city* nearestNeighbor(struct city* cityData, int numCities);

#endif
