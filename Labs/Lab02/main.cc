#include "iostream"
#include "fstream"
#include "string"
#include "numlist.h"

using namespace std;

int main(){
    
    string filename;
    cout << "Enter Filename (smaller.dat): ";
    cin >> filename;


    

    fstream myfile;
    myfile.open(filename.c_str());  // opens file and makes sure it passes input as a string

    if(myfile.is_open()){
        cout << "File has been opened!" << endl;
        cout << "Reading data from file: " + filename << endl;
        int line = 0;
        while(myfile >> line){
            cout << line << endl;
        }
        myfile.close();
        cout << "File has been closed!" << endl;
    } else {
        cout << "Unable to open file. Sorry!" << endl;
        return 0;
    }

    
} // main end