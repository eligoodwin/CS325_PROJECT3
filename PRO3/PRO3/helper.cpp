//
//  helper.cpp
//  PRO3
//
//  Created by eli goodwin on 6/1/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#include "helper.hpp"
using namespace std;

int calcDistance(float x1Coordinate, float x2Cooordinate, float y1Coordinate, float y2Coordinate){
    return (int)round(sqrt(pow((x1Coordinate - x2Cooordinate), 2) + pow((y1Coordinate - y2Coordinate), 2)));
}

void fillMatrix(struct city* cityData, int matrix, int cityLength){
    for(int i = 0; i < cityLength; ++i){
        for(int j = 0; j < cityLength; ++j){
            
        }
    }
    
}
