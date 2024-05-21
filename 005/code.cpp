// AIM : Write a program to design a class 'complex' to represent complex numbers. The complex class should use an external function (use it as a friend function) to add two complex numbers. The function should return an object of type complex representing the sum of two complex numbers

#include <iostream>
using namespace std;

class complex {
    private:
        int real;
        int imaginary;
    public:
        complex() {}
        // takes a complex number in the form of the real part and the complex part as two separate numbers (a + ib)
        complex (int real_part, int imaginary_part) {
            real = real_part;
            imaginary = imaginary_part;
        }

        void showNumber(void) {
            cout << real << " + " << imaginary << "i" << endl;
        }

        friend complex addNumbers(complex &num1, complex &num2);
};

complex addNumbers(complex &n1, complex &n2) {
    int res_real = n1.real + n2.real;
    int res_imag = n1.imaginary + n2.imaginary;
    return complex(res_real, res_imag);
}

int main() {
    complex n1(21, 4), n2(4, 3), result;
    cout << "number 1 : ";
    n1.showNumber();
    cout << "number 2 : ";
    n2.showNumber();
    result = addNumbers(n1, n2);
    cout << "sum : ";
    result.showNumber();
    return 0;
}