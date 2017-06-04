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
#include "cityData.hpp"

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
 ** Parameters: 
 **     cityData: struct containing relevant city data
 **     cityLength: length of city data set list
 ** Pre-Conditions: cityData must be nonempty
 ** Post-Conditions: none
 ** Return: none
 *********************************************************************/
void printMatrix(struct city* cityData, int cityLength);


/*********************************************************************
 ** Function: routeDistance
 ** Description: calcs the distance of a route given a route
 ** Parameters: 
 **     cityRoute: contains a route between cities
 **     cityLength: legnth of the struct city array
 ** Pre-Conditions: none
 ** Post-Conditions: None
 ** Return: distance of tour
 *********************************************************************/
int routeDistance(struct city* cityRoute, int cityLength);



/*********************************************************************
 ** Function: printTour
 ** Description: prints the tour to screen
 ** Parameters:
 **     cityRoute: contains a route between cities
 **     cityLength: legnth of the struct city array
 ** Pre-Conditions: none
 ** Post-Conditions: None
 ** Return: none
 *********************************************************************/
void printTour(struct city* cityRoute, int cityLength);
#endif /* helper_hpp */
