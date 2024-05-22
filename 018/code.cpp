// AIM : Write a program to implement the exception handling with the functionality of testing the throw restrictions

#include <iostream>
#include <stdexcept>
using namespace std;

void mightThrowFunction(int choice) {
    if (choice == 1) {
        throw runtime_error("Runtime error occurred");
    } else if (choice == 2) {
        throw out_of_range("Out of range error occurred");
    } else if (choice == 3) {
        throw invalid_argument("Invalid argument error occurred");
    } else {
        cout << "No exception thrown for choice " << choice << endl;
    }
}

int main() {
    int choice;
    cout << "Enter a choice (1-4): ";
    cin >> choice;

    try {
        mightThrowFunction(choice);
    } catch (const runtime_error &e) {
        cout << "Caught a runtime_error: " << e.what() << endl;
    } catch (const out_of_range &e) {
        cout << "Caught an out_of_range: " << e.what() << endl;
    } catch (const invalid_argument &e) {
        cout << "Caught an invalid_argument: " << e.what() << endl;
    }

    cout << "End of program" << endl;
    return 0;
}
