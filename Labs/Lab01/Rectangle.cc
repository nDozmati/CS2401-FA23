// The implementation file for the Rectangle class
#include "Rectangle.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Constructors
// Rectangle::Rectangle(double l = 0, double w = 0){
// 	length = l;
// 	width = w;
// 	area = l * w;
// }

Rectangle::Rectangle(double l, double w){
	length = l;
	width = w;
	area = length * width;
}

// Member and friend functions
Rectangle Rectangle::operator + (const Rectangle& r)const{
	Rectangle tmp;
	tmp.length = length + r.length;
	tmp.width = width +r.width;
	tmp.area = tmp.length * tmp.width;
	return tmp;
}

Rectangle Rectangle::operator - (const Rectangle& r)const{
	Rectangle tmp;
	if(length >= r.length){
		tmp.length = length - r.length;
	}
	else{
		tmp.length = 0;
	}

	if(width >= r.width){
		tmp.width = width - r.width;
	}
	else{
		tmp.width = 0;
	}
	tmp.area = tmp.length * tmp.width;
	return tmp;
}

Rectangle Rectangle::operator / (const int num)const{
	Rectangle tmp;
	tmp.length = length / num;
	tmp.width = width / num;
	tmp.area = tmp.length * tmp.width;
	return tmp;
}

Rectangle Rectangle::operator * (const int num)const{
	Rectangle tmp;
	tmp.length = length * num;
	tmp.width = width * num;
	tmp.area = tmp.length * tmp.width;
	return tmp;
}

bool Rectangle::operator == (const Rectangle& r)const{
	return length == r.length && width == r.width;
}

bool Rectangle::operator < (const Rectangle& r)const{
	return area < r.area;
}

bool Rectangle::operator > (const Rectangle& r)const{
	return area > r.area;
}

void Rectangle::input(istream&ins){
	/* Move the implementation code from the >> operator show below here.
	   Remember that since this function will be a member now, there will not be an r1.

	   The >> operator should now call this function.
	   Remove the friend keyword from the operator in the .h file and move the
	   function prototype to after the class declaration.
	*/
	cout << "Enter the length: ";
	cin >> length;
	cout << " Enter the width: ";
	cin >> width;
	area = length * width;    
}

void Rectangle::output(ostream& outs)const{
	/* Repeat what you did for input except using the code for the << operator */
    outs << "Length: " << length << endl;
	outs << " Width: " << width << endl;
	outs << "  Area: " << area << endl;
}


ostream& operator << (ostream& outs, const Rectangle& r){
	r.output(outs);
	return outs;
}

istream& operator >> (istream& ins, Rectangle& r){
	r.input(ins);
	return ins;
}