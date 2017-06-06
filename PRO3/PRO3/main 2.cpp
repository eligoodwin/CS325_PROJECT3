//  main.cpp
//  PRO3
//
//  Created by eli goodwin on 6/1/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "InAndOut.hpp"
#include "helper.hpp"


using namespace std;
int main(int argc, const char * argv[]) {
    char fileIn[20]; //store file name
    
    //handle cmd line argument
    if(argc == 1){
        cout << "No CMD line arugment was provided, using default: \"test.txt\"" << endl;
        strcpy(fileIn, "test.txt");
    }
    else{
        strcpy(fileIn, argv[1]);
    }
    
    int* solution = NULL; //array for solution
    int totalDistance = 0; //total distance of path
    
    class InAndOut stuff; //file input output object
    
    int cityLength = 0; //stores length of input
    int **cityDistances = NULL; //stores calculated distances 
    
    cityLength = stuff.getLength(fileIn); //what is the length/number of cities we are entering?
    //allocate the struct storing city data
    struct city* cityCoordintes = new city[cityLength];
    
    //read the data into the struct
    stuff.readData(cityCoordintes, fileIn);

    //allocate the adjacency matrix
    cityDistances = new int*[cityLength];
    for(int i = 0; i < cityLength; ++i){
        cityDistances[i] = new int[cityLength];
    }
    
    //make the adjacecy matrix
    makeMatrix(cityCoordintes, cityDistances, cityLength);
    //print matrix
    printMatrix(cityDistances, cityLength);
    //allocate solution array
    solution = new int[cityLength];
    
    
    //save results
    stuff.saveResult(solution, totalDistance, cityLength);
    
    //clean everything up
    delete []solution;
    delete []cityCoordintes;
    
    for(int i = 0; i < cityLength; ++i){
        delete []cityDistances[i];
    }
    
    delete []cityDistances;
    return 0;
}
