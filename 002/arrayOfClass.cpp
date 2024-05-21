// AIM : Write a Program which creates and uses array of objects of a class (for eg. implementing the list of Managers of a Comapny having details such as Name, Age, etc.)

#include <iostream>
#include <string>
using namespace std;

class Manager {
    private : 
        int age;
        string name;
        int experience_in_years;
    public : 
        Manager() {}

        Manager (int a, string n, int exp) {
            age = a;
            name = n;
            experience_in_years = exp;
        }

        void showManager(void) {
            cout << endl <<  "Manager Details" << endl;
            cout << "NAME : " << name << endl;
            cout << "AGE  : " << age << endl;
            cout << "EXP  : " << experience_in_years << endl << endl;
        }
};

int main() {
    int size;
    cout << "enter the number of managers to be loaded : ";
    cin >> size;
    
    // create an array of managers
    Manager managerArray[size];   

    // take user input for managers
    for (int i = 0; i < size; i++) {
        string name; 
        int age;
        int experience;
        cout << "Manager " << i + 1 << endl;
        cout << "enter the name for manager " << i + 1 << " : " ;
        cin >> name;
        cout << "enter the age for " << name << " : " ;
        cin >> age;
        cout << "enter " << name << "'s experience (in years) : " ;
        cin >> experience;
        managerArray[i] = Manager(age, name, experience);
    }

    // display all of the managers
    for (int i = 0; i < size; i++) {
        managerArray[i].showManager();
    } 

    return 0;
}