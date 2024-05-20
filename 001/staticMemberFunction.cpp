// AIM : Write a program to design a class having static member function named showCount() which has the property of displaying the number of objects created of that class

#include <iostream>
using namespace std;

class Sample
{
    private : 
        static int objectCount;
    public : 
        // define constructor to call the increment count function
        Sample (void) {
            incrementCount();
        }

        // define function as specified
        static void showCount(void) {
            cout << "there are " << objectCount << " objects of class Sample currently initiated" << endl;
        }

        // function to increase count of static variable
        static void incrementCount(void) {
            objectCount++;
        }
};

// initialise the static variable to be 0
int Sample::objectCount = 0;

int main() {
    // create 3 objects of the class
    Sample s1, s2, s3;

    // call the static function to display results
    Sample :: showCount();
    return 0;
}