#include <iostream>
#include <cmath>

using namespace std;

class Figure {
public:
    Figure(){
        cout<<"Derault Figure constructor"<< endl;
    };
    virtual double getArea() = 0;
};

class Parallelogram : public Figure {
protected:
    double base;
    double height;
    double side;
public:
    Parallelogram(): base(0.0), height(0.0), side(0.0) {
        cout << "Default Parallelogram constructor" << endl;
    }
    Parallelogram(double base, double height, double side) {
        assert(base>=0.0 && height>=0.0 && side >= 0.0 && side >= height);
        this->base = base;
        this->height = height;
        this->side = side;
        cout<<"Normal Parallelogram constructor"<< endl;
    };
    double getArea() {
        cout <<"Parallelogram square" << endl;
        return base * height;
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(double base, double height): Parallelogram(base, height, height) {
        cout<<"Normal Rectangle constructor"<< endl;
    };
    double getArea() {
        cout <<"Rectangle square" << endl;
        return base * height;
    }
};

class Square : public Parallelogram {
public:
    Square(double base): Parallelogram(base, base, base) {
        cout<<"Normal Square constructor"<< endl;
    };
    double getArea() {
        cout <<"Square square" << endl;
        return base * base;
    }
};

class Circle : public Figure {
protected:
    double radius;
public:
    Circle(double radius) {
        assert(radius >= 0.0);
        this->radius = radius;
        cout <<"Normal Circle constructor" << endl;
    }
    double getArea() {
        cout <<"Circle square" << endl;
        return M_PI*radius*radius;
    }

};


int main() {

    Rectangle rec(4.0, 5.0);

    cout << rec.getArea() << endl;

    Parallelogram par(2.0, 3.0, 3.5);
    cout << par.getArea() << endl;

    Figure *frec = new Rectangle(3.0, 2.3);
    Figure *fpar = new Parallelogram(4.3, 1.6, 12.3);
    Figure *fsqr = new Square(1.414213);
    Figure *fcir = new Circle(1.784128);


    cout<< frec->getArea()<<endl;
    cout<< fpar->getArea()<<endl;
    cout<< fsqr->getArea()<<endl;
    cout<< fcir->getArea()<<endl;

    return EXIT_SUCCESS;
}