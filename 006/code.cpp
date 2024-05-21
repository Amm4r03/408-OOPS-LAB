// AIM : Write a program using copy constructor to copy data of an object to another object

#include <iostream>
using namespace std;

class Testing {
    private :
        int data;
    public : 
        // default constructor
        Testing (int value = 0) : data(value) {}

        // copy constructor
        Testing(Testing &obj) {
            data = obj.data;
            cout << "copy constructor called" << endl;
        }

        void showData(void) {
            cout << "data stored in object : " << data << endl;
        }
};

int main() {
    Testing o(21);
    cout << "object 1 : ";
    o.showData();

    // initialise another object initially with a different value
    Testing o2(50);
    cout << "object 2 : ";
    o2.showData();
    
    // call the copy constructor
    o2 = o;
    cout << "object 2 (copied from object 1) : ";
    o2.showData();

    return 0;
}
