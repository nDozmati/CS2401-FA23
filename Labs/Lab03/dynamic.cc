# include <iostream>
#include <cstdlib>
using namespace std;

/**
 * @author  Nicolas Dozmati
 * @brief   This program demonstrates pointers, dynamic memory and dynamic arrays.
 * @date    09-21-2123
*/

int main(){
    int *ptr; // pointer
    int x = 2401; // integer
    ptr = &x; // pointing at integer address x

    //cout << ptr << endl; // memory address of x
    //cout << &ptr << endl; // memory address of pointer (will be different)
    //cout << *ptr << endl; // value of pointer pointing at x (2401)
/*
    for (int i = 0; i < 10; i++){
        ++(ptr); // * is gone
        cout << *ptr << " is stored at " << ptr << endl;
    }
*/
    size_t capacity = 5;
    size_t used = 0;
    ptr = new int[capacity];
    int *tmpptr;

    
    
    for(size_t i = 0; i < 25; i++){
        ptr[used] = rand(); // rand function needs #include<cstdlib>
        //cout << ptr[used] << endl;
        used++;

        if(used == capacity){

            // resize function
            tmpptr = new int[capacity + 5];
            for(unsigned int i = 0; i < used; i++){
                tmpptr[i] = ptr[i];
            }
            delete [] ptr;
            ptr = tmpptr;
            capacity += 5;
            cout << "Resized!\n" << endl;

            //cout << "Sorry out of room!\n";
            //break;
        }

    }

    int n = 2;
    tmpptr[n] = 0; // changes nth index value to 0

    for(unsigned int j = 0; j < used; j++){
        cout << ptr[j] << endl;
    }
    
    return 0;
}