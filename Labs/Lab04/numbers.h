/*************************************************************************
	A little class that holds a dynamic array of numbers.
	I have provided a start here, you need to write the function
		implementations. DO NOT remove the byte_count lines that are
		already in a few of the functions.


    John Dolan			Spring 2013		CS2401 Lab Assignment 4
	Patricia Lindner	Fall 2021
*************************************************************************/

/**
 * @author Nicolas Dozmati
 * @date 09/28/2023
 * @brief This file demonstrates how to safely allocate dynamic memory!
*/

#include <iostream>

size_t byte_count = 0;
class Numbers{
    public:
		Numbers();
        ~Numbers(); // destructor
		void add(unsigned long item);
		void resize();
		void remove_last();
		void display(std::ostream& outs);
		unsigned long* reveal_address()const;

    // Overloaded Operators
        Numbers& operator = (const Numbers &n);

    private: 
        unsigned long *data = data; // pointer & array
        std::size_t used; // iterator of data
        std::size_t capacity; // size of data array

};


Numbers::Numbers(){
    capacity = 5;
    used = 0;
    data = new unsigned long[capacity]; // delete?
	byte_count += 5 * sizeof(unsigned long);
}

Numbers::~Numbers(){
    delete[] data; // deallocates all of the memory
    byte_count = byte_count - (capacity * sizeof(unsigned long));
}

void Numbers::add(unsigned long item){
    if (used == capacity){
        // make the array bigger
        resize();
    }

    data[used] = item;
    used++;
}

void Numbers::resize(){
    unsigned long *tmp = new unsigned long[capacity + 5];

    for(unsigned int i = 0; i < used; i++){
        tmp[i] = data[i];
    }

    delete[] data;
    data = tmp;
    capacity += 5;
	byte_count += 5 * sizeof(unsigned long);
}

void Numbers::remove_last(){
    used--;
}

void Numbers::display(std::ostream& outs){
    for(unsigned int i = 0; i < used; i++){
        outs << data[i] << " ";
    }
}

// You can leave this function alone
unsigned long *Numbers::reveal_address()const{
	return data;
}

Numbers& Numbers::operator = (const Numbers &n){
    // Check for self assessment
    if(this != &n){

        // Deallocate old memory
        delete[] data;

        // Allocate new space
        data = new unsigned long[n.capacity];
    
        // Copy values
        capacity = n.capacity;
        for(int i = 0; i < capacity; i++){
        data[i] = n.data[i];
        }

        return *this;
    }
}
