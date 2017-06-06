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
    
//    for(int i = 0; i < numCities; ++i){
//        std::cout << T[i] << ", ";
//    }
    
    std::cout << std::endl;
	/*Add the distance between the last city on the tour and the first to
	complete the circuit*/
	distance += location->distancesList[0];
	return distance;
}


struct city** nearestNeighbor(struct city* cityData, int numCities){
    struct city** temp = NULL;
    struct city* location = &cityData[0];
    location->visited = true;
    
    struct city* nearest = NULL;
    //temp[0].cityNumber = location->cityNumber;
    temp[0] = location;
    
    std::cout << "Making the nearest neighbors: " << std::endl;
    for(int i = 1; i < numCities; ++i){
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
        
        temp[i] = nearest;
        nearest->visited = true;
        location = nearest;
        nearest = NULL;
    }
    
    return temp;
}


struct city** greedier(struct city* cityData, struct city** greedyResult, int cityLength){
    
    
    
    
    
    return greedyResult;
}
