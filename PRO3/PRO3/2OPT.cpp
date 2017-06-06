#include "2OPT.hpp"

using namespace std;


TWO_OPT::TWO_OPT(int lengthOfList, struct city** existingTour){
    cityLength = lengthOfList;
    currentTour = existingTour;
    newTour = new city*[lengthOfList];
    for(int i = 0; i < cityLength; ++i){
        newTour[i] = currentTour[i];
    }
};

TWO_OPT::~TWO_OPT(){
    delete [] newTour;
    
};


void TWO_OPT::optSwap(int start, int end){
    int i;
    int newRouteIdx = 0;
    
    for(i = 0; i < start; ++i){
        newTour[newRouteIdx] = currentTour[i];
        ++newRouteIdx;
    }
    
    for(i = end; i >=start; --i){
        newTour[newRouteIdx] = currentTour[i];
        ++newRouteIdx;
    }
    
    for(i = end + 1; i < cityLength + 1; ++i){
        newTour[newRouteIdx] = currentTour[i];
        ++newRouteIdx;
    }
    
    return;
}

void TWO_OPT::opt2(long& bestDistance, long& latestDistance){
    long newDistance = 0;
    
    for(int i = 1; i < cityLength - 1; ++i){
        for(int j = i + 1; j < cityLength; ++j){
            optSwap(i, j);
            //currentTour = newTour;

            newDistance = routeDistance(newTour, cityLength);
            if(newDistance < bestDistance){
                latestDistance = newDistance;
                //cout << "latest distance: " << latestDistance << endl;
                return;
            }
        }
    }
    
    latestDistance = bestDistance;
    return;
}


struct city** TWO_OPT::OPT2ALGO(){
    long newDistance = routeDistance(this->currentTour, this->cityLength); //get the current route distance of the passed in route/tour
    long bestDistance = LONG_MAX; //set to infinity for comparison
    long latestDistance = 0;
    
    while(newDistance < bestDistance){
        bestDistance = newDistance;
        //modify the new tour removing the crossing paths
        opt2(bestDistance, latestDistance);
        newDistance = latestDistance;
    
    }
    
    return newTour;
}
