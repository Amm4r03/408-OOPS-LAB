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

        void showVector() {
            cout << i << "i + " << j << "j + " << k << "k" << endl;
        }

        // overload the * operator to compute scalar multiplication
        friend Vector operator*(Vector &obj, int scalar) {
            return Vector(obj.i * scalar, obj.j * scalar, obj.k * scalar);
        }

        // overload the << operator
        friend Vector operator<<(Vector &obj, int shift_value) {
            return Vector(obj.i << shift_value, obj.j << shift_value, obj.k << shift_value);
        }

        // overload the >> operator
        friend Vector operator>>(Vector &obj, int shift_value) {
            return Vector(obj.i >> shift_value, obj.j >> shift_value, obj.k >> shift_value);
        }
};

int main() {
    Vector v1(2, 2, 5);
    cout << "vector 1 : ";
    v1.showVector();
    Vector v2 = v1 * 5;
    cout << "vector 2 = v1 * 5" << endl << "vector 2 : ";
    v2.showVector();
    cout << "LEFT SHIFT\nvec1 = vec1 << 2" << endl << "vector 1 : ";
    v1 = v1 << 2;
    v1.showVector();

    cout << "RIGHT SHIFT\nvec2 = vec2 >> 2" << endl << "vector 2 : ";
    v2 = v2 >> 2;
    v2.showVector();
    
    return 0;
}