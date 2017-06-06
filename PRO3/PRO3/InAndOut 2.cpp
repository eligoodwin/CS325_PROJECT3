//
//  InAndOut.cpp
//  PRO3
//
//  Created by eli goodwin on 6/1/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#include "InAndOut.hpp"
using namespace std;
void InAndOut::readData(struct city* cityData, char fileName[]){
    int listLength = 0;
    string numString;
    
    ifstream myFile;
    
    myFile.open(fileName);
    cout << "Opening file: " << fileName << endl;
    
    if(!myFile){
        cout << "Something went wrong" << endl;
    }
    
    //read in the data
    int i = 0;
    while(!myFile.eof()){
    
        float temp[3];
        
        while(getline(myFile, numString)){
            istringstream iss(numString);
            int j = 0;
            float n = 0;
            while(iss >> n){
                temp[j] = n;
                ++j;
            }
            
            cityData[i].cityNumber = temp[0];
            cityData[i].xDimension = temp[1];
            cityData[i].yDimension = temp[2];
            ++i;

        }
        
    }
    myFile.close();
    myFile.clear();
    
    return;
}

int InAndOut::getLength(char* fileName){
    ifstream myFile;
    int listLength = 0;
    string numString;
    myFile.open(fileName);
    
    
    while(!myFile.eof()){
        while(getline(myFile, numString)){
            istringstream iss(numString);
            ++listLength;
        }
    }
    
    myFile.close();
    myFile.clear();
    
    return listLength;
}

void InAndOut::saveMatrix(int** coordinatDeData, int lineCount){
    
    ofstream outFile;
    outFile.open(OUTFILENAME, ios::out);
    
    if(outFile.is_open()){
        for(int i = 0; i < lineCount; ++i){
            for(int j = 0; j < lineCount; ++j){
                outFile << coordinatDeData[i][j] << " ";
            }
            outFile << endl;
        }
    }
    
    cout << "saved file as: " << OUTFILENAME << endl;
    
    return;
}


void InAndOut::saveResult(int* results, int distance, int listLegnth){
    
    ofstream outFile;
    outFile.open(OUTFILENAME, ios::out);
    
    if(outFile.is_open()){
        outFile << distance << endl;
        for(int i = 0; i < listLegnth; ++i){
            outFile << results[i] << endl;
        }
        
    }
    
    outFile.close();
    outFile.clear();

    
    return;
}

