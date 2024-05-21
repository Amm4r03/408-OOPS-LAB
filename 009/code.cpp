// AIM : Write a program to overload operators like *, <<, >> using friend function. The following overloaded functions should work for a class 'vector'

#include <iostream>
using namespace std;

class Vector {
    private:
        int i, j, k;
    public : 
        Vector(int mag_x, int mag_y, int mag_z) {
            i = mag_x;
            j = mag_y;
            k = mag_z;
        }

        // overload the * operator to compute scalar multiplication
        friend Vector operator*(Vector &obj, int scalar) {
            return Vector(obj.i * scalar, obj.j * scalar, obj.k * scalar);
        }

        // overload the << operator


        // overload the >> operator
};

int main() {
    Vector v1(2, 2, 5);
    Vector v2 = v1 * 5;
    return 0;
}