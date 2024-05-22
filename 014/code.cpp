// AIM : Write a program to maintain the records of person with details (Name and Age) and find the eldest among them, The program must use this pointer to return the result

#include <iostream>
using namespace std;

class Person {
    private :
        int age;
        string name;
    public : 
        Person(string person_name, int person_age) {
            age = person_age;
            name = person_name;
        }

        Person(Person* p1) {
            this->age = p1->age;
            this->name = p1->name;
        }

        void showPersonDetails(void) {
            cout << "Person Details\n";
            cout << "NAME : " << name << endl;
            cout << "AGE : " << age << endl;
        }

        Person* findEldest(Person *obj) {
            if (this->age > obj->age) {
                cout << this->name << " is older than " << obj->name << " by " << this->age - obj->age << " years" << endl;
                return this;
            } else if (this->age < obj->age) {
                cout << obj->name << " is older than " << this->name << " by " << obj->age - this->age << " years" << endl;
                return obj;
            } else {
                cout << "Both " << this->name << " and " << obj->name << " are " << this->age << " years old" << endl;
                return this;
            }
        }
};

int main() {
    Person p1("Person A", 21), p2("Person B", 12), p3("AAA", 32), p4("Person D", 16);
    
    Person* eldest = &p1;

    eldest = eldest->findEldest(&p2);
    eldest = eldest->findEldest(&p3);
    eldest = eldest->findEldest(&p4);

    cout << "\nthe eldest person is : " << endl;
    eldest->showPersonDetails();

    return 0;
}