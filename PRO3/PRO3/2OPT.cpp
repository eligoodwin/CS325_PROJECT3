#include "2OPT.hpp"

using namespace std;


TWO_OPT::TWO_OPT(int lengthOfList, struct city * existingTour){
    cityLength = lengthOfList;
    currentTour = existingTour;
    newTour =  new city[cityLength];
    
    //make a deep current tour into new tour
    for(int i = 0; i < cityLength; ++i){
        newTour[i] = currentTour[i];
    }
    
};

TWO_OPT::~TWO_OPT(){
    currentTour = NULL;
    for(int i = 0; i < cityLength; ++i){
        delete []newTour[i].distancesList;
    }
    
    delete []newTour;
    newTour = NULL;
    
};


void TWO_OPT::optSwap(int start, int end){
    int oldRouteIdx;
    int newRouteIdx = 0;
    
    for(oldRouteIdx = 0; oldRouteIdx < start; ++oldRouteIdx){
        newTour[newRouteIdx] = currentTour[oldRouteIdx];
        ++newRouteIdx;
    }
    
    for(oldRouteIdx = end; oldRouteIdx > start; --oldRouteIdx){
        newTour[newRouteIdx] = currentTour[oldRouteIdx];
        ++newRouteIdx;
    }
    
    for(oldRouteIdx = end + 1; oldRouteIdx < cityLength; ++oldRouteIdx){
        newTour[newRouteIdx] = currentTour[oldRouteIdx];
        ++newRouteIdx;
    }
    
    return;
}

void TWO_OPT::opt2(long& bestDistance, long& latestDistance){
    long newDistance;
    
    for(int i = 1; i < cityLength - 1; ++i){
        for(int j = i + 1; j < cityLength; ++j){
            optSwap(i, j);
            currentTour = newTour;
            newDistance = routeDistance(this->currentTour, cityLength);
            if(newDistance < bestDistance){
                latestDistance = newDistance;
                return;
            }
        }
    }
    
    
    return;
}


struct city* TWO_OPT::OPT2ALGO(){
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
