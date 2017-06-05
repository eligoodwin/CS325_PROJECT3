#include "nearestNeighbor.hpp"

int nearestNeighbor (int* T, struct city* G, int numCities) {
	//Initialize starting point
	struct city* location = &G[0];
	location->visited = true;

	//Variable to track nearest city
	struct city* nearest = NULL;

	//Initialize the tour list with the starting location
	T[0] = location->cityNumber;
	int distance = 0;

	//Loop through the graph finding each nearest neighbor in succession and add to tour
	for (int i = 1; i < numCities; ++i) {
		for (int j = 0; j < numCities; ++j) {
			if (!(G[j].visited)) {
				if (nearest == NULL) {
					nearest = &G[j];
				}
				else if (location->distancesList[j] < location->distancesList[nearest->cityNumber]) {
					nearest = &G[j];
				}
			}
		}

		T[i] = nearest->cityNumber;
		nearest->visited = true;
		distance += location->distancesList[nearest->cityNumber];
		location = nearest;
		nearest = NULL;
	}

	/*Add the distance between the last city on the tour and the first to
	complete the circuit*/
	distance += location->distancesList[0];
	return distance;
}


struct city* nearestNeighbor(struct city* cityData, int numCities){
    struct city* temp = new city[numCities];
    struct city* location = &cityData[0];
    location->visited = true;
    
    struct city* nearest = NULL;
    temp[0].cityNumber = location->cityNumber;
    
    std::cout << "Making the nearest neighbors: " << std::endl;
    for(int i = 0; i < numCities; ++i){
        for(int j = 0; j < numCities; ++j){
            if(!(cityData[j].visited)){
                if(nearest == NULL){
                    nearest = &cityData[j];
                }
                
                else if(location->distancesList[j] < location->distancesList[nearest->cityNumber]){
                    nearest = &cityData[j];
                }
            }
        }
        
        temp[i].cityNumber = nearest->cityNumber;
        std::cout << nearest->cityNumber << ", " << temp[i].cityNumber << std::endl;
        nearest->visited = true;
        location = nearest;
        nearest = NULL;
    }
    
    return temp;
}
