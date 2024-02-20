//
// Created by Angela Renee on 2019-10-10.
//

#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//global variables
const int MAXSIZE = 100;
int size=0;
string title[MAXSIZE], nameArray[MAXSIZE], name;
int year[MAXSIZE], numberOfItems = 0, skip[MAXSIZE];

ifstream infile("movies.txt");
ofstream outfile("moviesout.txt");

//reads in file
void read(){
int i =1;
    while(infile >> nameArray[i])
    {
       // infile.ignore();
        i++;
    }
    cout << "done.\n";
    numberOfItems = i;
    cout << "num: " << i << endl;
    cout << "done.\n";
}//

//writes file
void write( ){

    //local variables
    int number, s=0, j=1;

    //is nameArray[i] a string or an int?
    for (int i = 1; i <= numberOfItems+1; i++) {
        istringstream iss(nameArray[i]);
        iss >> number;

        //if nameArray[i] is a string, finds the titles
        if (iss.fail()) {
            string theTitle;
            theTitle = title[s];
            title[j] += " " + nameArray[i];
        }//if

        //else nameArray[i] is an int, then finds the year movie was released
        else {
            //corrosponding
            year[j] = number;

            cout << j << ".\t" << title[j] << ", " << year[j] << endl;

            outfile << j << ".\t" << title[j] << ", " << year[j] << endl;

            //new movie
            s ++; j++;
            skip[s] = i;
            //year[i] = number;
        }//else
    }//for-loop
}//write

void writeFile(){

    //local variables
    string movieLine;
    ifstream moovieFile ("moviesout.txt");

    //prints file lines
    if (moovieFile.is_open()){
        while ( getline (moovieFile,movieLine) ){
            cout << movieLine << '\n';
        }
        moovieFile.close();
    }//if

    else {
        cout << "Unable to open file";
    }//else
}//writeFile
