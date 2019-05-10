#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
// подключим системные библиотеки для определения ширины окна терминала
#include <sys/ioctl.h>
#include <unistd.h>

using namespace std;

// Task 1

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

    friend SimpleFraction operator* (const SimpleFraction &sf1, const SimpleFraction &sf2);

    //Перегрузка операторов рабты с потоками

    friend ostream& operator << (ostream& out, const SimpleFraction &sf);
    friend istream& operator >> (istream& in, SimpleFraction &sf);

};

ostream& operator << (ostream& out, const SimpleFraction &sf){
    out << ((sf.Sign < 0) ? "-": "") << sf.Numerator << "/" << sf.Denominator;
    return out;
}

istream& operator >> (istream& in, SimpleFraction &sf){
    static unsigned int Digits[256];
    for (int ch = '0', d = 0; ch <'9'; ++ch, ++d) Digits[ch] = d;
    string Num;
    string Denom;
    char chr;
    int counter = 0;
    int numeratorFlag = 1;
    sf.Numerator = 0;
    sf.Denominator = 0;
    sf.Sign = 1;

    while (in.get(chr)) {

        if (counter==0 && chr == '-') {
            sf.Sign = -1;
        } else if (chr == '/') {
            assert(numeratorFlag > 0);
            --numeratorFlag;
            ++counter;
        } else if (chr == '\n') {
            break;
        }   else if (numeratorFlag) {
                sf.Numerator = sf.Numerator*10 + Digits[chr];
                ++counter;
        } else {
            sf.Denominator = sf.Denominator*10 + Digits[chr];
               ++counter;
        }
    }
    return in;
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

//Task 2

void inputString(){
    queue<string> Q;
    string str1 = "";
    string str2 = "";

    while (getline(cin,str1)) {
        if (str1 == "") break;
        Q.push(str1);
    }

    struct winsize size;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);

    while (!Q.empty()) {
        str1 = Q.front();
        Q.pop();
        if (!Q.empty()) {
            str2 = Q.front();
            Q.pop();
        } else {
            str2 = "";
        }

    cout.setf(std::ios::right, std::ios::adjustfield);
    cout << str1 << setfill(' ') << setw(size.ws_col - str1.length()) << str2 << endl;
    }
}

//Task 3

void inputInt() {
    int length = 0;
    int isCorrect = 1;
    string str1;
    while (getline(cin,str1)) {
        if (str1 == "") break;
        length = str1.length();
        isCorrect = 1;
        for (int i = 0; i < length; ++i) {
            if (str1[i] < '0' || str1[i] > '9') {
                isCorrect = 0;
                break;
            }
        }
        if (isCorrect) {
            cout << "Ok, good!" << endl;
            return;
        } else {
            cout << "Wrong number, try once more" << endl;
        }
    }
}

//Task 4

ostream& endll(ostream& os) {
    os.put('\n');
    os.put('\n');
    os.flush();
    return os;
}

int main() {

    cout << endl << "============ Task 1 ============" << endl << endl;

    SimpleFraction f1;
    cout << "Enter fraction 1: ";
    cin >> f1;

    SimpleFraction f2;

    cout << "Enter fraction 2: ";
    cin >> f2;

    cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

    cout << endl << "============ Task 2 ============" << endl << endl;

    inputString();

    cout << endl << "============ Task 3 ============" << endl << endl;

    inputInt();

    cout << endl << "============ Task 4 ============" << endl << endl;

    cout << "Fitst line" << endll;
    cout << "Second Line" << endl;


    return EXIT_SUCCESS;
}