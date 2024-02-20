/* Name: Angela Burns
 * Class: CSCI 1411-006
 * Description: a menu that allows you to read in movies and their date
 * Status: successfully compiled on CLion  */

//Function Prototypes
#ifndef LAB07_FUNCTIONS_H
#define LAB07_FUNCTIONS_H
#endif //LAB07_FUNCTIONS_H

#ifndef _READ
#define _READ
void read( );
#endif //_READWRITE

#ifndef _WRITE
#define _WRITE
void write( );
#endif //_WRITE

#ifndef _WRITEFILE
#define _WRITEFILE
void writeFile( );
#endif //_WRITEFILE


//Function Implementations
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


//int main()
#include "functions.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const int MAXSIZE = 100;
    int size = 0;

    int menu;

    bool stop = false;
    while (!stop){

        cout << "\nplease choose one\n"
                "1.\tRead in Movies\n"
                "2.\tList titles, years to the screen\n"
                "3.\tList titles, year to a file\n"
                "4.\tExit\n" << endl;
        cin >> menu;

        switch (menu){
            case 1:
                read();
                break;

            case 2:
                write();
                break;

            case 3:
                writeFile();
                break;

            case 4:
                stop = true;
                cout << "Goodbye." << endl;
                break;

            default:
                cout << "ERROR" << endl;
                break;
        }//switch
    }//while-loop

    return 0;
}