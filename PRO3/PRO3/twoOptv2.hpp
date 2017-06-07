#ifndef _TWOOPTV2_hpp
#define _TWOOPTV2_hpp

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
     A     B--                          A ---- B--
      \   /
        x       Distance1 > ? Distance2
      /   \
     X     Y--                          X ---- Y--
 ** Input: preexisiting route, number of cities in the route
 ** Output: structs containing city coorditnate info, txt files with saved city data
 *********************************************************************/

#include <stdio.h>
#include <climits>
#include <time.h>
#include <chrono>
#include "cityData.hpp"
#include "helper.hpp"


class TWO_OPTv2{
public:
    TWO_OPTv2(int cityListLength, struct city** existingTour, long long* currentTime);
    ~TWO_OPTv2();
    struct city** twoOptAlgo2();
    void twoOptSwap(const int& startt, const int&end);
    long long currentRunTime;
    
private:
    struct city** newTour;
    struct city** currentTour;
    int cityLength;
    const long long maxTime = 170000; //2:50 
    long long cannotExceed;
    
};

#endif /* _TWOOPTV2_hpp */
