//  main.cpp
//  PRO3
//
//  Created by eli goodwin on 6/1/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <time.h>
#include <chrono>

#include "InAndOut.hpp"
#include "helper.hpp"
#include "cityData.hpp"
#include "nearestNeighbor.hpp"
#include "2OPT.hpp"
#include "twoOptv2.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    char fileIn[20]; //store file name
    
    //handle cmd line argument
    if(argc == 1){
        cout << "No CMD line arugment was provided, using default: \"test.txt\"" << endl;
        strcpy(fileIn, "test-input-4.txt");
    }
    else{
        strcpy(fileIn, argv[1]);
    }
    
    //int* tour = NULL; //array for solution
    struct city** finTour = NULL;
    long totalDistance = 0; //total distance of path
    long long runTime = 0; //stores runtime of the algo
    class InAndOut stuff; //file input output object
    
    int cityLength = 0; //stores length of input
    //int **cityDistances = NULL; //stores calculated distances
    
    cityLength = stuff.getLength(fileIn); //what is the length/number of cities we are entering?
    //allocate the struct storing city data
    struct city* cityCoordinates = new city[cityLength];
    
    //read the data into the struct
    stuff.readData(cityCoordinates, fileIn);

    //allocate the adjacency "list" for each city
    for(int i = 0; i < cityLength; ++i){
        cityCoordinates[i].distancesList = new int[cityLength];
    }
    
    //calc the distances
    makeDistances(cityCoordinates, cityLength);
    
    //make city Tour array
    int* T = new int[cityLength];
    //get distance of greedy tour
    totalDistance = nearestNeighbor(T, cityCoordinates, cityLength);
    cout << "inital distance: " << totalDistance << endl;
    
    //start the clock for the algo
    auto start = chrono::high_resolution_clock::now();
    //create new city tour with distance data
    
    struct city** cityTour = new city*[cityLength];
    //cout << cityLength  << endl;
    
    convertIt(T, cityCoordinates, cityTour, cityLength);
   // printMatrix(cityTour, cityLength);
    
    //init twoOPT
    //TWO_OPT twoOptItUp(cityLength, cityTour);
    TWO_OPTv2 op2Algo(cityLength, cityTour);
    //start algo
    //finTour = twoOptItUp.OPT2ALGO();
    
    finTour = op2Algo.twoOptAlgo2();
    cout << "final tour: " << endl;
    
    //final runtime
    auto elapsed = chrono::high_resolution_clock::now() - start;
    runTime = chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
    
    cout << "Total runtime was: " << runTime << " milliseconds." << endl;
    //save runtime data
    //stuff.saveRunTime(runTime);
    //calc final distance
    totalDistance  = routeDistance(finTour, cityLength);
    //save results
    stuff.saveResult(finTour, totalDistance, cityLength);
    cout << "final distance: " << totalDistance <<endl;
    
    cout << endl;
    finTour = NULL;
    //clean everything up
    for(int i = 0; i < cityLength; ++i){
        delete [] cityCoordinates[i].distancesList;
        cityCoordinates[i].distancesList = NULL;
    }
    
    delete [] cityCoordinates;
    delete [] cityTour;
    cityCoordinates = NULL;
    
    return 0;
}
