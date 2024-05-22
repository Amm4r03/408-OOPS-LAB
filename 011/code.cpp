// AIM : write a program in c++ to highlight the difference between overloaded assignment operator and copy constructor

#include <iostream>
#include <cstring>

class MyClass {
private:
    char* data;
public:
    // Constructor
    MyClass(const char* str = nullptr) {
        if (str) {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        } else {
            data = new char[1];
            *data = '\0';
        }
        std::cout << "Constructor called\n";
    }

    // Copy Constructor
    MyClass(const MyClass& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        std::cout << "Copy Constructor called\n";
    }

    // Overloaded Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this == &other) return *this; 

        delete[] data;
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        std::cout << "Assignment Operator called\n";

        return *this;
    }

    // Destructor
    ~MyClass() {
        delete[] data;
        std::cout << "Destructor called\n";
    }

    // Display the data
    void display() const {
        std::cout << "Data: " << data << '\n';
    }
};

int main() {
    MyClass obj1("Hello");
    MyClass obj2 = obj1;

    MyClass obj3;
    obj3 = obj1; 

    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}
