#include "2OPT.hpp"

using namespace std;


TWO_OPT::TWO_OPT(int lengthOfList, struct city * existingTour){
    cityLength = lengthOfList;
    currentTour = existingTour;
    newTour = new city[cityLength];
    
    //make a deep current tour into new tour
    for(int i = 0; i < cityLength; ++i){
        newTour[i].cityNumber = currentTour[i].cityNumber;
        newTour[i].xDimension = currentTour[i].xDimension;
        newTour[i].yDimension = currentTour[i].yDimension;
        cout << newTour[i].xDimension << ", " << currentTour[i].xDimension << endl;
        cout << newTour[i].yDimension << ", " << currentTour[i].yDimension << endl;
        
        newTour[i].distancesList = new int[cityLength];
    }
    
    cout << "Printing tour of new tour: " << endl;
    printTour(this->newTour, this->cityLength);

//    makeDistances(this->newTour, this->cityLength);
    
  
//    cout << endl;
//    cout << "Printing list: " << endl;
//    printMatrix(this->newTour, this->cityLength);
//    
};

TWO_OPT::~TWO_OPT(){
//    currentTour = NULL;
//    for(int i = 0; i < cityLength; ++i){
//        delete []newTour[i].distancesList;
//    }
//    
//    delete []newTour;`
//    newTour = NULL;
//    
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
    long newDistance = 0;
    
    for(int i = 1; i < cityLength - 1; ++i){
        for(int j = i + 1; j < cityLength; ++j){
            optSwap(i, j);
            //currentTour = newTour;
            newDistance = routeDistance(this->newTour, cityLength);
            if(newDistance < bestDistance){
                latestDistance = newDistance;
                cout << "latest distance: " << latestDistance << endl;

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
