/*
AIM : Create a class shape with the following members : 
    Data members : length, breadth, height
    Member functions : vol, comparison
Craete two objects of Shape named s1 and s2. Compare these objects by using 'this' pointer. Kindly assign the values to the data members through the constructor
*/ 

#include <iostream>
using namespace std;

class Shape {
    private : 
        int length;
        int breadth;
        int height;
    public : 
        Shape(int shape_length, int shape_breadth, int shape_height) {
            length = shape_length;
            breadth = shape_breadth;
            height = shape_height;
        }

        int vol() {
            return length * breadth * height;
        }

        void comparison(Shape &other) {
            if (this->vol() > other.vol()) {
                cout << "current shape is larger in volume" << endl;
            } else if (this->vol() < other.vol()) {
                cout << "current shape is smaller in volume" << endl;
            } else {
                cout << "both shapes are of equal volume" << endl;
            }
        }
};

int main() {
    Shape s1(10, 10, 10), s2(2, 12, 16);
    s1.comparison(s2);
    s2.comparison(s1);
    return 0;
}