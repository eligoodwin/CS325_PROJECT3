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
    int* T = NULL;
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
    
    //calc runtime of alog
    auto start = chrono::high_resolution_clock::now();
    
    //Start algo
    if (argc > 2) {
        switch (atoi(argv[2])) {
            case 1:
                T = new int[cityLength];
                totalDistance = nearestNeighbor(T, cityCoordinates, cityLength);
                //save results
                stuff.saveResult(T, totalDistance, cityLength);
                break;
            case 2: {
                tempTour = nearestNeighbor(cityCoordinates, cityLength);
                //Init twoOPT
                TWO_OPT twoOptItUp(cityLength, tempTour);
                //Run 2OPT
                finTour = twoOptItUp.OPT2ALGO();
                totalDistance  = routeDistance(finTour, cityLength);
                //save results
                stuff.saveResult(finTour, totalDistance, cityLength);
                break;
            }
            case 3:
                cout << "Beginning Christofides" << endl;
                T = new int[cityLength];
                totalDistance = christofides(T, cityCoordinates, cityLength);
                cout << "Christofides complete" << endl;
                //save results
                stuff.saveResult(T, totalDistance, cityLength);
                break;
            default:
                T = new int[cityLength];
                totalDistance = nearestNeighbor(T, cityCoordinates, cityLength);
                //save results
                stuff.saveResult(T, totalDistance, cityLength);
                break;
        }
    }
    else {
        T = new int[cityLength];
        totalDistance = nearestNeighbor(T, cityCoordinates, cityLength);
        //save results
        stuff.saveResult(T, totalDistance, cityLength);
    }

    auto elapsed = chrono::high_resolution_clock::now() - start;
    
	cout << "\nDistance = " << totalDistance << endl;
    
    //final runtime
    runTime = chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
    
    cout << "\nTotal runtime was: " << runTime << " milliseconds." << endl;
    //save runtime data
    stuff.saveRunTime(runTime);
    
    //clean everything up
    
    delete[] T;
    delete []tempTour;
    delete []cityCoordinates;
    
    return 0;
}
