// AIM : Write a program to allocate memory dynamically for an object of a given class using class's constructor

#include <iostream>
using namespace std;

class Sample {
    private :
        int number;
    public :
        Sample (int value = 0) {
            cout << "constructor called with val : " << value << endl;
            number = value;
        }

        void showData(void) {
            cout << "data in object : " << number << endl;
        }

        ~Sample () {
            cout << "destructor called" << endl;
        }
};

int main() {
    // using new keyword to allocate memory of an object of Sample with value 21
    Sample* object = new Sample(21);

    object->showData();

    // delete the object to show the destructor working
    delete object;

    return 0;
}