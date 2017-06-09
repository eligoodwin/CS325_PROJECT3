#ifndef NEAREST_NEIGHBOR
#define NEAREST_NEIGHBOR

#include "cityData.hpp"
#include <cstddef>
#include <iostream>

/*********************************************************************
 ** Filename: nearestNeighbor.hpp
 ** Author: Eli Goodwin, Benjamin Tate and Carlos La Hoz Daniels
 ** Date: 2017/06/4
 ** Description: This Greedy Algorithm finds a tour for the traveling salesman
 ** problem by always choosing the nearest neighbor to the current city.
 ** Input: table of cities and the distances between them
 ** Output: There are two versions of the function, one outputs the total
 **	distance of the tour and also populates an int arry passed in with the city identifiers
 ** in the order they are visited. The other returns an array of city structs representing
 **	the tour order.
 *********************************************************************/

int nearestNeighbor (int* T, struct city* G, int numCities);

struct city* nearestNeighbor(struct city* cityData, int numCities);

#endif
