#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(){
    cout << "\n\nPROGRAM IS RUNNING!\n\n" << endl;

    cout << "Welcome to my Rectangle Program!\n" << endl;
    // double n1, n2, n3, n4;
    Rectangle r1;
    Rectangle r2;
    int scalar;

    cout << "Please Enter the information for each rectangle below" << endl;
    cin >> r1;
    cin >> r2;

    // cout << "Input Length of 1st Rectangle: ";
    // cin >> n1; 

    // cout << "Input Width of 1st Rectangle:  ";
    // cin >> n2;

    // cout << "Input Length of 2nd Rectangle: ";
    // cin >> n3; 

    // cout << "Input Width of 2nd Rectangle:  ";
    // cin >> n4;


    // cout << "Area of 1st Rectangle is: " << r1.get_area() << endl;
    // cout << "Area of 2nd Rectangle is: " << r2.get_area() << endl;

    cout << "Enter Scalar Value (int): ";
    cin >> scalar;
    cout << scalar << " will be used for * and / operators." << endl;

    Rectangle result;
    bool torf;

    cout << "Here I have combined the two rectangles with the + operator: " << endl;
    result = r1 + r2;
    cout << result << endl;

    cout << "Here I have combined the two rectangles with the - operator: " << endl;
    result = r1 - r2;
    cout << result << endl;

    cout << "Here I have combined the first rectangle with the scalar using the * operator: " << endl;
    result = r1 * scalar;
    cout << result << endl;

    cout << "Here I have combined the second rectangle with the scalar using the / operator: " << endl;
    result = r2 / scalar;
    cout << result << endl;

    cout << "Here I have tested if the first rectangle is < than the second rectangle using the < operator: " << endl;
    torf = r1 < r2;
    cout << torf << endl;

    cout << "Here I have tested if the first rectangle is > than the second rectangle using the > operator: " << endl;
    torf = r1 > r2;
    cout << torf << endl;

    cout << "Here I have tested if the first rectangle is == to the second rectangle using the == operator: " << endl;
    torf = r1 == r2;
    cout << torf << endl;


    cout << "\n\nPROGRAM HAS ENDED!\n\n" << endl;

    return 1;
}