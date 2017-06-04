//
//  helper.hpp
//  PRO3
//
//  Created by eli goodwin on 6/1/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#ifndef helper_hpp
#define helper_hpp

#include <stdio.h>
#include <math.h>
#include <iostream>
#include "InAndOut.hpp"

/*********************************************************************
 ** Function: calcDistance
 ** Description: x y coordinate date of two points is taken and the 
 ** straightline distance between them is calculatd
 ** Parameters:
 **     x1Coordinate, x2Coordinate, y1Coordinate, y2Coordinate: coordinates of points
 ** Pre-Conditions: must be postiive
 ** Post-Conditions: None
 ** Return: distance rounded to the nearest integer
 *********************************************************************/
int calcDistance(float x1Coordinate, float x2Cooordinate, float y1Coordinate, float y2Coordinate);


/*********************************************************************
 ** Function: calcDistance
 ** Description: x y coordinate date of two points is taken and the
 ** straightline distance between them is calculatd
 ** Parameters:
 **     x1Coordinate, x2Coordinate, y1Coordinate, y2Coordinate: coordinates of points
 ** Pre-Conditions: must be postiive
 ** Post-Conditions: None
 ** Return: distance rounded to the nearest integer
 *********************************************************************/
void makeDistances(struct city* cityList, int cityLegnth);


/*********************************************************************
 ** Function: printMatrix
 ** Description: prints contents of matrix to screen
 ** Parameters: cityMatrix: nxn matrix of values
 ** Pre-Conditions: none
 ** Post-Conditions: None
 ** Return: none
 *********************************************************************/
void printMatrix(struct city* cityData, int cityLength);

#endif /* helper_hpp */
