//
//  helper.cpp
//  PRO3
//
//  Created by eli goodwin on 6/1/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#include "helper.hpp"
using namespace std;
//calc distances
int calcDistance(float x1Coordinate, float x2Cooordinate, float y1Coordinate, float y2Coordinate){
    return (int)round(sqrt(pow((x1Coordinate - x2Cooordinate), 2) + pow((y1Coordinate - y2Coordinate), 2)));
}

//make adjacency "list" for each city
void makeDistances(struct city* cityData, int cityLength){
    cout << "calculating distances ... "<< endl;
    
    for(int i = 0; i < cityLength; ++i){
        for(int j = 0; j < cityLength; ++j){
            cityData[i].distancesList[j] = calcDistance(cityData[i].xDimension, cityData[j].xDimension, cityData[i].yDimension, cityData[j].yDimension);
        }
    }
    
    return;
}

//print matrix if need be
void printMatrix(struct city* cityData, int cityLength){
    cout << "\nDistances for the complete graph: " << endl;
    //print results
    for(int i = 0; i < cityLength; ++i){
        for(int j = 0; j < cityLength; ++j){
            cout << cityData[i].distancesList[j] << " ";
        }
        cout << endl;
    }
    
    return;
}
