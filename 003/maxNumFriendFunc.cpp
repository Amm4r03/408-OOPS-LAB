// AIM : Write a program to find maximum out of two numbers using friend function
// NOTE : here, one number is a member of one class and the other number is member of some other class

#include <iostream>
using namespace std;

// function declaration
class NumberTwo;

// first class
class NumberOne {
    private:
        int number_one;
    public :
        // constructor
        NumberOne() {
            number_one = 12;
        }

        // declared friend function
        friend void maxNumber(NumberOne &obj, NumberTwo &obj2);
};

// second class
class NumberTwo {
    private: 
        int private_num_second_class;
    public :
        // constructor
        NumberTwo() {
            private_num_second_class = 15;
        }

        // declared friend function
        friend void maxNumber(NumberOne &obj, NumberTwo &obj2);
};

// friend function definition
void maxNumber(NumberOne &obj, NumberTwo &obj2) {
    if (obj.number_one > obj2.private_num_second_class) {
        cout << "number from first class is greater" << endl;
        cout << obj.number_one << " > " << obj2.private_num_second_class << endl;
    } else if (obj.number_one < obj2.private_num_second_class) {
        cout << "number from second class is greater" << endl;
        cout << obj.number_one << " < " << obj2.private_num_second_class << endl;
    } else {
        cout << "both numbers are equal" << endl;
    }
}

int main() {
    NumberOne n1;
    NumberTwo n2;
    maxNumber(n1, n2);
    return 0;
}