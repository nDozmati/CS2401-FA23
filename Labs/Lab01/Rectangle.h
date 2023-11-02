// Add documentation for the file and each function

#include <iostream>
#ifndef RECTANGLE_H
#define RECTANGLE_H
// CLASS RECTANGLE.    
class Rectangle{   
  public:

    // CONVERT THESE CONSTRUCTORS INTO A SINGLE CONSTRUCTOR THAT USES 
    // DEFAULT ARGUMENTS
    /*
    Rectangle();
    Rectangle(double l, double w);
    */

    Rectangle(double l = 0, double w = 0); // SINGLE CONSTRUCTOR W/ DEFAULT ARGS (OK).

    // Member functions
    void input(std::istream& ins);            
    void output(std::ostream& outs)const;

    double get_length()const {return length;}
    double get_width()const {return width;}
    double get_area()const {return area;}

    // Friend functions
    /*
    friend Rectangle operator + (const Rectangle& r1, const Rectangle& r2);
 
    friend Rectangle operator - (const Rectangle& r1, const Rectangle& r2);
 
    friend Rectangle operator * (const Rectangle& r1, int num);

    friend Rectangle operator / (const Rectangle& r1, int num);

    friend std::istream& operator >> (std::istream& fin, Rectangle& r);
    
    friend std::ostream& operator << (std::ostream& fout, const Rectangle& r);

    friend bool operator == (const Rectangle& r1, const Rectangle& r2);

    friend bool operator < (const Rectangle& r1, const Rectangle& r2);

    friend bool operator > (const Rectangle& r1, const Rectangle& r2);
    */

    Rectangle operator + (const Rectangle& r)const; // SUM + (r).

    Rectangle operator - (const Rectangle& r)const; // DIFFERENCE - (r).
    
    Rectangle operator * (const int num)const; // SCALAR * (num).
    
    Rectangle operator / (const int num)const; // SCALAR / (num).
    
    bool operator < (const Rectangle& r)const;  // LESS THAN < (r).
    
    bool operator > (const Rectangle& r)const;  // GREATER THAN > (r).
    
    bool operator == (const Rectangle& r)const; // EQUAL TO == (r).
    
    
  private:
      double length;  // should not be able to go < 0
      double width;   // should not be able to go < 0
      double area;
};

    std::istream& operator >> (std::istream& ins, Rectangle &r);   // OVERLOADED INPUT (ins).
    
    std::ostream& operator << (std::ostream& outs, const Rectangle &r); // OVERLOADED OUTPUT (outs).

#endif