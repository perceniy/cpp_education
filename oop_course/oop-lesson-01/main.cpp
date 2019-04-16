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

//Task 2. Create class RGBA

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

//Task 3. Create class stack

class Stack {
private:
    int a[10];
    int length = 0;
public:
    Stack() {};
    void reset() {
        length = 0;
        for (int i = 0; i < 10; i++) a[i] = 0;
    }
    bool push(int val) {
        if (length == 10) {
            cout<< "Error: stack overflow" << endl;
            return false;
        } else {
            length++;
            for(int i = length - 1; i >= 1; i--) {
                a[i] = a[i-1];
            }
            a[0] = val;
            return true;
        }
    }
    int pop() {
        if (length>0) {
            int result = a[0];
            for(int i = 0; i < length - 1; i++) {
                a[i] = a[i+1];
            }
            length--;
            return result;
        } else {
            cout << "Error: Stack is empty" << endl;
            return 0;
        }
    }
    void print() {
        for (int i = length - 1; i >= 0; i-- ) {
            cout << a[i] << " ";
        }
        cout << endl;
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

    cout << endl << "Task 3 " << endl << endl;

    Stack s;
    int test;
    s.reset();
    test = s.pop();
    cout <<"Test variable: "<< test << endl;

    for (int j = 0, v = 10; j <= 11; j++, v+=10 ) {
        s.push(v);
    }

    s.print();

    test = s.pop();
    cout <<"Test variable: "<< test << endl;

    s.print();

    return EXIT_SUCCESS;
}