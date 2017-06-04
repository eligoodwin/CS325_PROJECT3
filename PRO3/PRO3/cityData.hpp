/*********************************************************************
 ** Filename: cityData.hpp
 ** Author: Eli Goodwin, Benjamin Tate and Carlos La Hoz Daniels
 ** Date: 2017/05/1
 ** Description: This is the struct for storing city data
 ** Input: none
 ** Output: none
 *********************************************************************/
#ifndef cityData_h
#define cityData_h
struct city{
    int cityNumber; //city number
    float xDimension;   //x coord
    float yDimension;   //y coord
    int* distancesList; //adjacency list
    
    //constructor
    city(){
        cityNumber = 0;
        xDimension = 0;
        yDimension = 0;
        distancesList = NULL;
    }
    //destructor
    ~city(){
        delete []distancesList;
    }
};


#endif /* cityData_h */
