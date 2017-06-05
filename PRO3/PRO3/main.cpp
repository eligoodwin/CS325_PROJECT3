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
#include "christofides.hpp"
#include "2OPT.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    char fileIn[20]; //store file name
    
    //handle cmd line argument
    if(argc == 1){
        cout << "No CMD line arugment was provided, using default: \"test.txt\"" << endl;
        strcpy(fileIn, "tsp_example_1.txt");
    }
    else{
        strcpy(fileIn, argv[1]);
    }
    
    //int* tour = NULL; //array for solution
    struct city* tempTour = NULL;
    struct city* finTour = NULL;
    int totalDistance = 0; //total distance of path
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
    printTour(cityCoordinates, cityLength);
    //print matrix
    //printMatrix(cityCoordinates, cityLength);
    
    //allocate solution array
//    int* tour = new int[cityLength];
//    totalDistance = nearestNeighbor(tour, cityCoordinates, cityLength);
    //calc runtime of alog
    auto start = chrono::high_resolution_clock::now();
    //int* T = NULL;
    //totalDistance = nearestNeighbor(tour, cityCoordinates, cityLength);
    
    
    //start algo
    //begin
//    tempTour = nearestNeighbor(cityCoordinates, cityLength);
	cout << "Beginning Christofides" << endl;
	int testTour[cityLength];
	totalDistance = christofides(testTour, cityCoordinates, cityLength);
	cout << "Christofides complete" << endl;
//	for (int i = 0; i < cityLength; i++) {
//		cout << "\n" << testTour[i];
//	}
	cout << "\nDistance = " << totalDistance << endl;
    
    //init twoOPT
//    TWO_OPT twoOptItUp(cityLength, tempTour);
    
    //start algo
//    finTour = twoOptItUp.OPT2ALGO();
    
    //final runtime
    auto elapsed = chrono::high_resolution_clock::now() - start;
    runTime = chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
    
    cout << "\nTotal runtime was: " << runTime << " milliseconds." << endl;
    //save runtime data
    stuff.saveRunTime(runTime);
    //calc final distance
//    totalDistance  = routeDistance(finTour, cityLength);
    //save results
    stuff.saveResult(finTour, totalDistance, cityLength);
    
    //clean everything up
    //delete []solution;
    
    delete []tempTour;
    delete []cityCoordinates;
    
    return 0;
}
