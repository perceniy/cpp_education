#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Task 1

class Figure {
public:
    Figure(){
        cout << endl <<"Derault Figure constructor"<< endl;
    }
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
    }
    double getArea() {
        cout <<"Parallelogram square" << endl;
        return base * height;
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(double base, double height): Parallelogram(base, height, height) {
        cout<<"Normal Rectangle constructor"<< endl;
    }
    double getArea() {
        cout <<"Rectangle square" << endl;
        return base * height;
    }
};

class Square : public Parallelogram {
public:
    Square(double base): Parallelogram(base, base, base) {
        cout<<"Normal Square constructor"<< endl;
    }
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


// Task 2

class Car {
protected:
    string Model;
    string Company;
public:
    Car(): Model("Undefined"), Company ("Undefined") {
        cout << endl << "Derault Car constructor: " << Company << " " <<  Model <<endl;
    }
    Car(string model, string company): Model(model), Company (company) {
        cout << endl << "Normal Car constructor: " << this->Company << " " <<  this->Model << endl;
    }
};

class PassengerCar: public Car{
public:
    PassengerCar(): Car("PassengerCar","Car") {
        cout << "Derault PassengerCar constructor" << endl;
    }
    PassengerCar(string model, string company): Car(model, company) {
        cout << "Normal PassengerCar constructor" << endl;
    }
};

class Bus: public Car {
public:
    Bus(): Car("Bus","Car") {
        cout << "Derault Bus constructor" << endl;
    }
    Bus(string model, string company): Car(model, company) {
        cout << "Normal Bus constructor" << endl;
    }
};

class Minivan: public PassengerCar, Bus {
public:
    Minivan(){
        cout << "Derault Minivan constructor" << endl;
    }
    Minivan(string model, string company){

        cout << "Normal Minivan constructor" << endl;
    }
};

//Task 3

int getNOD (int a, int b) {
    if ( a<= 0 || b <= 0 ) return 0;
    int tmp = 0;
    while (b) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

class Fraction {
protected:
    // Знак будем хранить в специальной переменной
    int Sign = 1;
    int Numerator = 0;
    int Denominator = 1;
public:
    Fraction(){}
    Fraction(int numerator, int denominator){
        assert(denominator > 0);
        Numerator = numerator;
        Denominator = denominator;
    }
    //Наличие чисто виртуальной функции делает класс абстрактным
    virtual void reverseSign() = 0;

    int getNumerator() const { return Numerator; };
    int getDenominator() const { return Denominator; };
    int getSign() const {return Sign;};
};

class SimpleFraction: public Fraction {
public:
    SimpleFraction(): Fraction() {}
    SimpleFraction(int numerator, int denominator): Fraction(abs(numerator), denominator) {
        if (numerator < 0) Sign = -1;
    }
    void printValues() const {
        cout << ((Sign < 0) ? "-": "") << Numerator << "/" << Denominator << endl;
    }

    void reverseSign() {
        Sign = -Sign;
    }

    SimpleFraction reverseFraction() {
        int buf = Numerator;
        Numerator = Denominator;
        Denominator = buf;
        return *this;
    };

    friend SimpleFraction operator+ (const SimpleFraction &sf1, const SimpleFraction &sf2);
    friend SimpleFraction operator- (const SimpleFraction &sf1);
    friend SimpleFraction operator* (const SimpleFraction &sf1, const SimpleFraction &sf2);
    friend SimpleFraction operator/ (const SimpleFraction &sf1, const SimpleFraction &sf2);
    friend bool operator== (const SimpleFraction &sf1, const SimpleFraction &sf2);
    friend bool operator>  (const SimpleFraction &sf1, const SimpleFraction &sf2);
    friend bool operator<  (const SimpleFraction &sf1, const SimpleFraction &sf2);
};

class MixedFraction: public Fraction {
protected:
    /* Знак дроби нужно передавать через целую часть, или через числитель, если целая часть - О */
    int Whole = 0;
public:
    MixedFraction(){}
    MixedFraction(int whole, int numerator, int denominator): Fraction(abs(numerator), denominator), Whole(abs(whole)) {
        assert(( numerator >= 0 ) || ( whole == 0 && numerator <0 ));
        if ((whole < 0) || (numerator < 0)) Sign = -1;
        if (Numerator > Denominator) {
            Whole+= Numerator/Denominator;
            Numerator = Numerator % Denominator;
        }
    }
    void reverseSign() {
        Sign = -Sign;
    }
    void printValues() {
        cout << ((Sign < 0) ? "-": "") << Whole << "(" << Numerator << "/" << Denominator << ")" << endl;
    }

    int getWhole() const { return Whole; };

    SimpleFraction getSimpleFraction() const {
        return SimpleFraction(Sign*(Whole*Denominator + Numerator), Denominator);
    };
};



// Перегружаем унарный -

SimpleFraction operator- (const SimpleFraction &sf1) {
    SimpleFraction temp(sf1);
    temp.reverseSign();
    return temp;
}

MixedFraction operator- (const MixedFraction &mf2) {
    MixedFraction temp(mf2);
    temp.reverseSign();
    return temp;
}
// Перегружаем бинарный + для суммирования обычных дробей

SimpleFraction operator+ (const SimpleFraction &sf1, const SimpleFraction &sf2) {
    int newNumerator = 0;
    int newDenominator = 0;
    int NOD = 0;
    newNumerator = (sf1.Sign*sf1.Numerator*sf2.Denominator + sf2.Sign*sf2.Numerator*sf1.Denominator);
    newDenominator = sf1.Denominator*sf2.Denominator;
    NOD = getNOD(abs(newNumerator),newDenominator);
    newNumerator = newNumerator/NOD;
    newDenominator = newDenominator/NOD;
    return SimpleFraction(newNumerator,newDenominator);
};

// Перегружаем бинарный + для суммирования составных дробей

MixedFraction operator+ (const MixedFraction &mf1, const MixedFraction &mf2) {
    SimpleFraction tmp = mf1.getSimpleFraction() + mf2.getSimpleFraction();
    return MixedFraction(0,tmp.getSign()*tmp.getNumerator(), tmp.getDenominator());
};

MixedFraction operator+ (const MixedFraction &mf1, const SimpleFraction &sf2) {
    SimpleFraction tmp = mf1.getSimpleFraction() + sf2;
    return MixedFraction(0,tmp.getSign()*tmp.getNumerator(), tmp.getDenominator());
}

// Перегрузка оператора *

SimpleFraction operator* (const SimpleFraction &sf1, const SimpleFraction&sf2) {
    int newNumerator = 0;
    int newDenominator = 0;
    int NOD = 0;

    newNumerator = sf1.Sign*sf1.Numerator*sf2.Sign*sf2.Numerator;
    newDenominator = sf1.Denominator*sf2.Denominator;
    NOD = getNOD(abs(newNumerator),newDenominator);
    // cout << "NOD " << NOD << " newNumerator " << newNumerator << " newDenominator " << newDenominator << endl;
    newNumerator = newNumerator/NOD;
    newDenominator = newDenominator/NOD;
    return SimpleFraction(newNumerator,newDenominator);;
}

MixedFraction operator* (const MixedFraction &mf1, const MixedFraction &mf2) {
    SimpleFraction tmp = mf1.getSimpleFraction()*mf2.getSimpleFraction();
    return MixedFraction(0,tmp.getSign()*tmp.getNumerator(), tmp.getDenominator());
}

MixedFraction operator* (const MixedFraction &mf1, const SimpleFraction &sf2) {
    SimpleFraction tmp = mf1.getSimpleFraction()*sf2;
    return MixedFraction(0,tmp.getSign()*tmp.getNumerator(), tmp.getDenominator());
}

// Перегрузка оператора /

SimpleFraction operator/ (const SimpleFraction &sf1, const SimpleFraction &sf2) {
    SimpleFraction tmp(sf2);
    return sf1*tmp.reverseFraction();;
}

MixedFraction operator/ (const MixedFraction &sf1, const MixedFraction &sf2) {
    MixedFraction tmp(sf2);
    SimpleFraction result = sf1.getSimpleFraction()*tmp.getSimpleFraction().reverseFraction();
    return MixedFraction(0,result.getSign()*result.getNumerator(), result.getDenominator());
}

//Перегрузка логических операторов

bool operator == (const SimpleFraction &sf1, const SimpleFraction &sf2 ) {

    return sf1.Sign * sf1.Numerator * sf2.Denominator == sf2.Sign * sf2.Numerator * sf1.Denominator;
}

bool operator != (const SimpleFraction &sf1, const SimpleFraction &sf2 ) {
    return !(sf1 == sf2);
}

bool operator> (const SimpleFraction &sf1, const SimpleFraction &sf2 ) {
    return sf1.Sign * sf1.Numerator * sf2.Denominator > sf2.Sign * sf2.Numerator * sf1.Denominator;
}

bool operator< (const SimpleFraction &sf1, const SimpleFraction &sf2 ){
    return sf1.Sign*sf1.Numerator*sf2.Denominator < sf2.Sign*sf2.Numerator*sf1.Denominator;
}

bool operator>= (const SimpleFraction &sf1, const SimpleFraction &sf2 ){
    return !(sf1<sf2);
}

bool operator<= (const SimpleFraction &sf1, const SimpleFraction &sf2 ){
    return !(sf1>sf2);
}


int main() {

    cout << "Task 1"<< endl;

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



    cout << endl << "Task 2"<< endl;
    Car car("Rio","Kia");
    PassengerCar pcar("Focus","Ford");
    Bus bus("Transit","Ford");
    Minivan van("My","Dream"); // Срабатывают оба конструктора


    cout << endl << "Task 3" << endl;

    SimpleFraction s1(-1,3), s2(2,3);
    MixedFraction m1(2,1,2), m2(-1,1,2);
    cout <<"s1 = s1 + s2"<< endl;
    s1 = s1 + s2;
    s1.printValues();
    cout <<"m1 = m1 + m2"<< endl;
    m1 = m1 + m2;
    m1.printValues();
    cout <<"m1 = m1 + s1"<< endl;
    m1 = m1 + s1;
    m1.printValues();
    cout <<"s1 = -s1"<< endl;
    s1 = -s1;
    s1.printValues();
    cout <<"m1 = -m1"<< endl;
    m1 = -m1;
    m1.printValues();
    cout <<"s1 = s1*s1"<< endl;
    s1 = s1*s1;
    s1.printValues();
    cout <<"m1 = m1*m1"<< endl;
    m1 = m1*m1;
    m1.printValues();
    cout <<"m2 = m1*s2"<< endl;
    m2 = m1*s2;
    m2.printValues();

    SimpleFraction s3(2,3), s4(3,4);
    cout <<"s3 = s3/s4"<< endl;
    s3 = s3/s4;
    s3.printValues();

    MixedFraction m3(2,1,4), m4(1,1,2);
    cout <<"m3 = m3/m4"<< endl;
    m3 = m3/m4;
    m3.printValues();

    if (s3 > s1) printf("s3 > s1\n");
    if (s3 < s1) printf("s3 < s1\n");
    if (s3 == s1) printf("s3 = s1\n");
    if (s3 != s1) printf("s3 != s1\n");
    if (s3 >= s1) printf("s3 >= s1\n");
    if (s3 <= s1) printf("s3 <= s1\n");

    return EXIT_SUCCESS;
}