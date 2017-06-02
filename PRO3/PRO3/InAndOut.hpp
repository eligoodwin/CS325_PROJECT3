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
#include "CityInfo.h"
#include <string>
#include <sstream>

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
    int loadFile(struct city* cityData, char fileName[]);
    
    /*********************************************************************
     ** Function: saveFile
     ** Description: takes a dynamic adjacency matrix and saves it to .txt
     ** Parameters:
     **     coordinateData : an dynamically declared n x n adjacency matrix of
     **     coordinate data.
     ** Post-Conditions: None
     ** Return: if file was successsfully saved to disk
     *********************************************************************/
    bool saveFile(int **coordinateData, int lineCount);
    
private:
    const char OUTFILENAME[20] = "outfile.txt";
};


#endif /* InAndOut_hpp */
