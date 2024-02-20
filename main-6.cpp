
#include "functions.h"
#include <iostream>
#include <fstream>
//#include <tclDecls.h>

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