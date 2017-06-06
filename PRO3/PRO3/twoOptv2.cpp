#include "twoOptv2.hpp"
using namespace std;
TWO_OPTv2::TWO_OPTv2(int cityListLength, struct city** existingTour){
	cityLength = cityListLength;
	currentTour = existingTour;
	newTour = new city* [cityLength];
	for(int i = 0; i < cityLength; ++i){
		newTour[i] = currentTour[i];
	}
};

TWO_OPTv2::~TWO_OPTv2(){
	delete [] newTour;
};


void TWO_OPTv2::twoOptSwap(const int& start, const int& end){
	int i;
	int currIdx = 0;
	for(i = 0; i <= start; ++i){
		newTour[i] = currentTour[i];
		++currIdx;
	}

	for(i = end; i > start; --i){
		newTour[currIdx] = currentTour[i];
		++currIdx;
	}

	for(i = end + 1; i < cityLength + 1 ; ++i){
		newTour[i] = currentTour[i];
	}

	return;
}


struct city** TWO_OPTv2::twoOptAlgo2(){
	long newDistance = routeDistance(currentTour, cityLength);
	long currentDistance = LONG_MAX;
	long latestDistance = 0;

	while(newDistance < currentDistance){
		//get distance of current route
		currentDistance = routeDistance(currentTour, cityLength);
		
		for(int i = 0; i < cityLength; ++i){
            for(int j = 0; j < cityLength; ++j){
				//perform the swap to eliminate crossses
				twoOptSwap(i, j);
				//is the new route shourter? let's find out
				newDistance = routeDistance(this->newTour, this->cityLength);
				//if the new distance is shorter than the vest recorded distance, save the new route
				if(newDistance < currentDistance){
//                    for(int k = 0; k < cityLength; ++k){
//                        this->currentTour[k] = this->newTour[k];
//                    }
                    this->currentTour = this->newTour;
                    //cout << "newest tour: " << endl;
                    //printTour(newTour, cityLength);
                latestDistance = newDistance;
				}
			}
		}

		newDistance = latestDistance;
	}

	return currentTour;
}




