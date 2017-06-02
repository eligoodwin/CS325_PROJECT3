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


#endif /* helper_hpp */
