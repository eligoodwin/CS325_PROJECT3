/*********************************************************************
 ** Filename: FileInAndOut.hpp
 ** Author: Eli Goodwin, Benjamin Tate and Carlos La Hoz Daniels
 ** Date: 20167/05/1
 ** Description: This is an interface to facilitate file input and output. It will take a text file as and input and will output data as a .txt
 ** Input: strings containing file names
 ** Output: structs containing city coorditnate info, txt files with saved city data
 *********************************************************************/
#ifndef InAndOut_hpp
#define InAndOut_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "cityData.hpp"

//struct to save city data; stores city, x y coordinates, and its adjacency "list"
//struct city{
//    int cityNumber; //city number
//    float xDimension;   //x coord
//    float yDimension;   //y coord
//    int* distancesList; //adjacency list
//    
//    //constructor
//    city(){
//        cityNumber = 0;
//        xDimension = 0;
//        yDimension = 0;
//        distancesList = NULL;
//    }
//    //destructor
//    ~city(){
//        delete []distancesList;
//    }
//};



class InAndOut{
public:
    /*********************************************************************
     ** Function: loadFile
     ** Description: takes a .txt file and parses location data into struct for
     ** distance calcuations
     ** Parameters:
     **     struct cityData: city coordinates are saved here for calculating distances
     **     char *fileName : name of file containing city coordinates
     ** Pre-Conditions: txt file must be formatted correctly:
     **     0 234 5443
     **     1 2321 5544
     **     etc
     ** Post-Conditions: None
     ** Return: returns line count and struct with city coordinates loaded in it
     *********************************************************************/
    void readData(struct city* cityData, char fileName[]);
    
    /*********************************************************************
     ** Function: saveFile
     ** Description: takes a dynamic adjacency matrix and saves it to .txt
     ** Parameters:
     **     coordinateData : an dynamically declared n x n adjacency matrix of
     **     coordinate data.
     ** Post-Conditions: None
     ** Return: if file was successsfully saved to disk
     *********************************************************************/
    void saveMatrix(int **coordinateData, int lineCount);
    
    /*********************************************************************
     ** Function: getLength
     ** Description: gets length of the file
     ** Parameters:
     **     fileName: fileName of the file we are going to get the length of
     ** Post-Conditions: None
     ** Return: if file was successsfully saved to disk
     *********************************************************************/
    int getLength(char* fileName);
    
    /*********************************************************************
     ** Function: saveResult
     ** Description: saves the result of the finding the path
     ** Parameters:
            results: results of path traversal
            distance: total length of the path
     ** Post-Conditions: None
     ** Return: none
     *********************************************************************/
    void saveResult(int* results, int distance, int listLength);
    

private:
    const char OUTFILENAME[20] = "results.txt";
};


#endif /* InAndOut_hpp */
