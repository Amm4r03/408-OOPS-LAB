// AIM : Write a program to wap private data members of classes named as class_1 and class_2 using friend function

#include <iostream>
using namespace std;

// class declaration
class class_2;

class class_1 {
    private: 
        int some_number;
    public : 
        // constructor
        class_1 () {
            some_number = 21;
        }

        // utility function to display numbers from both classes
        friend void showNumbers(class_1 &o1, class_2 &o2);

        // function to swap numbers declared as friend
        friend void swapNumbers(class_1 &object_class1, class_2 &object_class2);
};

class class_2 {
    private : 
        int some_number;
    public : 
        class_2 () {
            some_number = 101;
        }

        friend void showNumbers(class_1 &o1, class_2 &o2);

        // function to swap numbers declared as friend within second class
        friend void swapNumbers(class_1 &ob1, class_2 &ob2);
};

void swapNumbers(class_1 &object_class1, class_2 &object_class2) {
    int temp = object_class1.some_number;
    object_class1.some_number = object_class2.some_number;
    object_class2.some_number = temp;
}

void showNumbers(class_1 &o1, class_2 &o2) {
    cout << "number in first class " << o1.some_number << endl;
    cout << "number in second class " << o2.some_number << endl; 
}

int main() {
    class_1 a;
    class_2 b;

    // show initial state of both objects n then show state after swapping variables
    showNumbers(a, b);
    swapNumbers(a, b);
    cout << endl;
    showNumbers(a, b);

    return 0;
}