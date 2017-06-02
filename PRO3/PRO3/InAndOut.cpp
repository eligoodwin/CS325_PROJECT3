//
//  InAndOut.cpp
//  PRO3
//
//  Created by eli goodwin on 6/1/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#include "InAndOut.hpp"
using namespace std;

int InAndOut::loadFile(struct city* cityData, char* fileName){
    ifstream myFile;
    int lineCount = 0;
    
    string numString;
    //load file
    myFile.open(fileName);

    cout << "Number of lines in file: "<<  lineCount << endl;
    //make arrray of city-structs
    city* cityTemp = new city[lineCount];
    
    //read city coord data into struct array
    int i = 0;
    while(!myFile.eof()){
        ++lineCount;
        while(getline(myFile, numString)){
            istringstream  iss(numString);
            int n;
            while(iss >> n){
                cityTemp[i].cityNumber = n;
                cityTemp[i].xDimension = n;
                cityTemp[i].yDimension = n;
            }
                
        }
        ++i;
    }
    
    
    cityData = cityTemp;
    myFile.close();
    myFile.clear();
    
    return lineCount;
}


bool InAndOut::saveFile(int **coordinateData, int lineCount){
    bool saved = true;
    
    //create file output object
    ofstream outFile;
    
    //create file to svae to
    outFile.open(OUTFILENAME, ios::out);
    cout << "saving file as: " << OUTFILENAME << endl;
    
    //write out adjacency matrix
    if(outFile.is_open()){
        for(int i = 0; i < lineCount; ++i){
            for(int j = 0; j < lineCount; ++j){
                outFile << coordinateData[i][j] << " ";
            }
            outFile << endl;
        }
    }
    else{
        cout << "Something went haywire. File was not saved." << endl;
    }
    
    
    outFile.close();
    outFile.clear();
    return saved;
}
