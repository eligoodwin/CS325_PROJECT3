/*********************************************************************
** Filename: 2OPT.hpp
** Author: Eli Goodwin, Benjamin Tate and Carlos La Hoz Daniels
** Date: 2017/06/4
** Description: This is used to perform OPT2 optimization of a
** preexisting route. A route is fed in and using the principle of the
** triangle equality, if two edges between two cities cross there might
** be a shorter path between them, if that crossed path is eliminated. 
** The algorithm tests if the result of performing a swap creates a 
** shorter route.
** eg:
    A       B--                         A ---- B--
      \   /
        x       Distance1 > ? Distance2
      /   \
    X       Y--                         X ---- Y--
** Input: preexisiting route, number of cities in the route
** Output: structs containing city coorditnate info, txt files with saved city data
*********************************************************************/
#include "2OPT.hpp"
#include "cityData.hpp"
class TWO_OPT{
public:
    //properties
    int cityLength;
    struct city* currentTour;
    
    //methods
    /*********************************************************************
     ** Function: OPT2ALGO
     ** Description: does the optimization of the currentTour
     ** Parameters:
     **     none
     ** Pre-Conditions:
     **     -a valid hamilitonian path must be in the property currentTour
     **     -city length must be greater than 1
     ** Post-Conditions: None
     ** Return: returns a tour that has been swapped optimized
     *********************************************************************/
    struct city** OPT2ALGO();
    
private:
    //properties
    
    
    //methods
    /*********************************************************************
     ** Function: optSwap
     ** Description: performs the swapping of the route so that it can be tested
     ** if the new resulting route will be shorter or not
     ** Parameters:
     **     none
     ** Pre-Conditions: 
     **      a tour must be calculated before TWO_OPT can run
     ** Post-Conditions: None
     ** Return: returns a tour with swapped routes
     *********************************************************************/
    struct city** optSWap();
    
    
    
    
};
