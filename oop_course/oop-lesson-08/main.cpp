#include <iostream>

using namespace std;

// Task 1

int division(const int &dividend, const int &divider) {
    if  (divider == 0 ) throw "DivisionByZero";
    return dividend / divider;
}

//Task 2

class Ex {
private:
    double x;
public:
    explicit Ex(const double &value): x(value) {}
    void print_data() {
        cout.precision(2);
        cout << "Exception data is: "<< fixed << x << endl;
    }
};

class Bar {
private:
    double y;
public:
    Bar() { y = 0;}
    void set_y (const double &a) {
        if (y + a > 100 ) throw Ex(y);
        y = a;
    }
};

//Task 3

// Directions:
// 0 - up
// 1 - right
// 2 - down
// 3 - left

struct coordinate {
    coordinate(){};
    coordinate(int nx, int ny ): x(nx), y(ny) {};
    int x;
    int y;
};

typedef struct coordinate Coords;

typedef int IllegalCommand;

typedef struct coordinate OffTheField;

class Robot {
private:
    Coords position;
    Coords step[4];
public:
    explicit Robot() {
        position.x = 0;
        position.y = 0;
        step[0].x =  0; step[0].y =  1;
        step[1].x =  1; step[1].y =  0;
        step[2].x =  0; step[2].y = -1;
        step[3].x = -1; step[3].y =  0;
    };
    void doStep(int direction) {
        if (direction < 0 || direction > 3) throw IllegalCommand(direction);
        int new_x = position.x + step[direction].x;
        int new_y = position.y + step[direction].y;
        if (new_x > 9 || new_x < 0 || new_y < -9 || new_y > 0) throw OffTheField(new_x, new_y);
        position.x = new_x;
        position.y = new_y;

    }

    void print_field() {
        cout<< endl;
        for (int cy = 0; cy > -10; --cy){
            for (int cx = 0; cx < 10; ++cx) {
                if (position.x == cx && position.y == cy ) {
                    cout << "R ";
                } else if ( cx == 3 && cy == -4) {
                    cout << "X ";
                } else {
                    cout << ". ";
                }
            }
            cout<< endl;
        }
        cout<< endl;
    }

    int get_x() const { return position.x; }
    int get_y() const { return position.y; }

};

int main() {
    cout << " ========== Task 1 ==========" << endl << endl;
    int a = 100, b = 0;

    try {
        cout << "Incomplete quotient "<< a <<" and " << b << " is: " << division(a, b) << endl;
    }
    catch(const char *) {
        std::cout << "undefined, division by zero!" << std::endl;
    }

    cout << " ========== Task 2 ==========" << endl << endl;

    Bar element;
    int n;

    do {
        try {
            cout << "Enter integer number: ";
            cin >> n;
            if (n==0) break;
            element.set_y(static_cast<double>(n));
            }
        catch (Ex exception) {
            cout << "Exeption was occurred" << endl;
            exception.print_data();
            // в условии указано, что выходим из цикла только если введен 0
            // так что печатаем исключение и продолжаем
            continue;
        }
    } while (true);

    cout << endl << " ========== Task 3 ==========" << endl << endl;

    cout << "Welcome to the Robot simulator" << endl;
    cout << "Put the robot(R) to the cross cell (X)" << endl;
    cout << "List of available commands:" << endl << endl;

    cout << "0 - move up" << endl;
    cout << "1 - move right" << endl;
    cout << "2 - move down" << endl;
    cout << "3 - move left" << endl;

    Robot sktlz;
    sktlz.print_field();
    int cmd;
    do {
        cout << "Please input the command: ";
        cin >> cmd;
        try {
            sktlz.doStep(cmd);
        }
        catch(IllegalCommand command) {
            cout << "Illegal command! Command must be in [0..3]. Received: " << command << "."<< endl;
            continue;
        }
        catch(OffTheField crd) {
            cout << "Off The field Error! Impossible coordinates ["<< crd.x << "; "<< - crd.y << "]." << endl;
            continue;
        }
        sktlz.print_field();
    } while (!(sktlz.get_x()==3 && sktlz.get_y() == -4));

    cout << endl << "Bingo!" << endl;

    return EXIT_SUCCESS;
}