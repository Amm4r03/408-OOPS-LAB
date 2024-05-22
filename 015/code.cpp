// AIM : write a program to illustrate the use of pointers to objects which are related by inheritance

// tbd : point at base class n then point at derived class using same pointer

#include <iostream>
using namespace std;

class Base {
    protected : 
        int age;
        string name;
    public : 
        Base(string username, int userAge) {
            name = username;
            age = userAge;
        }
        
        virtual void showDetails() {
            cout << "Person details : " << endl;
            cout << "NAME : " << name << endl;
            cout << "AGE : " << age << endl;
        }
};

class Student : public Base {
    private : 
        int student_id;
    public : 
        Student(string student_name, int student_age, int id) : Base(student_name, student_age) {
            student_id = id;
        }

        void showDetails() {
            cout << "Student Details : " << endl;
            cout << "NAME : " << name << endl;
            cout << "AGE : " << age << endl;
            cout << "STUDENT ID : " << student_id << endl;
        }
};

int main() {
    Base* basePointer;
    Base b1("Person A", 23);
    Student s1("Student B", 18, 2021223);

    basePointer = &b1;
    cout << "using base class pointer to show details from base class : " << endl;
    basePointer->showDetails();

    basePointer = &s1;
    cout << "using base class pointer to show details from derived class : " << endl;
    basePointer->showDetails();

    return 0;
}