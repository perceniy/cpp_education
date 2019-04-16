#include <iostream>
#include <math.h>

using namespace std;

// Task 1. Create class Power.

class Power {
private:
    double var;
    double power;
public:
    Power() {
        var = 0;
        power = 1;
    }
    Power(double var, double power) {

        if ((power == 0.0 ) & ( var == 0.0)) {
            cout << "Unexpected input, set power to 1" << endl;
            this->var = 0;
            this->power = 1;
        } else {
        this->var = var;
        this->power = power;
        }
    }
    double set_params(double var, double power) {
        if ((power == 0.0) & (var == 0.0)) {
            cout << "Unexpected input, set power to 1" << endl;
            this->var = 0;
            this->power = 1;
        } else {
            this->var = var;
            this->power = power;
            cout << "Parameters was set successfully" << endl;
        }
    }
    double calculate() {
        return pow(var, power);
    }
};

int main() {
    Power myPower(0, 0);
    cout << myPower.calculate() << endl;
    myPower.set_params(2, 3);
    cout << myPower.calculate() << endl;
    return EXIT_SUCCESS;
}