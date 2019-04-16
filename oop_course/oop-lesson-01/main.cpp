#include <iostream>
#include <cmath>
#include <cstdint>

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
    void set_params(double var, double power) {
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

class RGBA {
private:
    uint8_t m_red = 0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;
public:
    RGBA() {}
    RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha): m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}
    void printRGBA() {
        cout << endl << "Class RGBA:" << endl;
        cout << "\tRed:\t" << static_cast<unsigned int>(m_red) << endl;
        cout << "\tGreen:\t" << static_cast<unsigned int>(m_green) << endl;
        cout << "\tBlue:\t" << static_cast<unsigned int>(m_blue) << endl;
        cout << "\tAlpha:\t" << static_cast<unsigned int>(m_alpha) << endl;
    }
};


int main() {

    //Task 1

    Power myPower(0, 0);
    cout << myPower.calculate() << endl;
    myPower.set_params(2, 3);
    cout << myPower.calculate() << endl;

    //Task 2

    RGBA p(12,14,15,220);
    p.printRGBA();

    //Task 3
    


    return EXIT_SUCCESS;
}