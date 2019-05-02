#include <iostream>
#include "_geek.h"

using namespace _geek;
using namespace std;

void printSticks (int count){
    for (int i = 0; i<count; ++i) cout << "| ";
    cout << endl;
}


int main() {
/*
    cout << "Task 1" << endl << endl;

    cout << product(4, 5) << endl;


    cout << endl << "Task 2" << endl << endl;

    int number = 0;
    int result = 0;


    cout << "Enter the integer number:" << endl;
    cin >> number;

    if (number > 5) {
        cout << "Please enter number less than 5" << endl;
        cin >> number;
    }

    if ((number > 5) & (number < 10)) {
        result = number - 5;
    } else {
        result = 5 - number;
    }

    cout << "Result is: " << result << endl;

    if (result == 0) {
        cout << "Result is zero!" << endl;
    } else if (result < 0) {
        cout << "Result less than zero." << endl;
    } else {
        cout << "Result more than zero." << endl;
    }

    cout << endl << "Task 3" << endl << endl;

    enum const_set {
        sc_Const0 = 0,
        sc_Const1 = 1,
        sc_Const2 = 2,
        sc_Const3 = 3,
        sc_Const4 = 4,
        sc_Const5 = 5
    };

    int flag = 0;

    cout << "Enter the integer number:" << endl;
    cin >> number;


    switch (number) {
        case sc_Const0:
        case sc_Const1:
        case sc_Const2:
            flag = 1;
            break;
        case sc_Const3:
        case sc_Const4:
        case sc_Const5:
            flag = 2;
    }

    if (flag == 1) {
        cout << "A number is in the first half of a set" << endl;
    } else if (flag == 2) {
        cout << "A number is in the second half of a set" << endl;
    } else {
        cout << "A number is out of a set" << endl;
    }

    cout << endl << "Task 4" << endl << endl;

    unsigned int value = 0;

    cout << "Enter the integer number above zero:" << endl;
    cin >> value;

    if (value > 3) {
        do {
            cout << value << endl;
            value -= 1;
        } while (value > 0);
    }

*/

    cout << endl << "Task 5" << endl << endl;
    int turn, sticks = 0;


    cout << "Enter the number of sticks between 10 and 30:" << endl;
    cin >> sticks;

    while ((sticks < 10) | (sticks > 30)) {
        cout << "Please enter correct number of sticks" << endl;
        cin >> sticks;
    }

    printSticks(sticks);

    while (sticks > 1) {
        cout << "Your turn (from 1 to 3):" << endl;
        cin >> turn;
        turn = turn > 3 ? 3 : turn;
        turn = turn < 1 ? 1 : turn;
        sticks = sticks - turn;
        printSticks(sticks);
        if (sticks == 1) {
            cout << "You won!" << endl;
            break;
        }
        cout << "My turn:" << endl;
        if (sticks%4 == 3 ) {
            turn = 2;
        } else if (sticks%4 == 2) {
            turn = 1;
        } else if (sticks%4 == 1) {
            turn = 1;
        } else if (sticks%4 == 0) {
            turn = 3;
        }
        sticks = sticks - turn;
        printSticks(sticks);
        if (sticks == 1) {
            cout << "I won!" << endl;
            cout << "I am a cheater!" << endl;
            break;
        }

        if (sticks < 1) {
            cout << "Something went wrong..." << endl;
        }
    }
    return 0;
}