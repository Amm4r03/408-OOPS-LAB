// AIM : write a program illustrating how the constructors are implemented and the order in which they are called when the classes are inherited. Use three classes named alpha, beta, gamma such that alpha, beta are base class and gamma is derived class inheriting alpha and beta

#include <iostream>
using namespace std;

class Alpha {
    private : 
        int some_number;
    public :
        Alpha () {
            cout << "Alpha constructor called" << endl;
        }
};

class Beta {
    private : 
        int dataInBeta;
    public : 
        Beta () {
            cout << "Beta constructor called" << endl;
        }
};

class Gamma : public Beta, public Alpha {
    private :
        int dataInGamma;
    public : 
        Gamma () {
            cout << "Gamma constructor called" << endl;
        }
};

int main() {
    Gamma object;
    return 0;
}