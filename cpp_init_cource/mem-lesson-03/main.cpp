
//Составить программу, выводящую на экран текущую среду сборки (Windows/Linux),
//дату и время последней успешной сборки. Использовать константу TIME для вывода времени.


#include <iostream>

using namespace std;

#ifdef __APPLE__
#define STOP_CHECKS
#define a 1
#endif __APPLE__


#ifndef STOP_CHECKS
#ifdef _WIN32
#define STOP_CHECKS
#define a 1
#endif  __linux__
#endif STOP_CHECKS

#ifndef STOP_CHECKS
#ifdef _linux_
#define STOP_CHECKS
#define a 1
#endif  __linux__
#endif STOP_CHECKS



int main() {

    cout << __DATE__ << " " << __TIME__ << endl;
    cout << __cplusplus << endl;

    switch (a) {
        case 1:
            cout << "Building environment is Apple" << endl;
            break;
        case 2:
            cout << "Building environment is Windows" << endl;
            break;
        case 3:
            cout << "Building environment is Windows" << endl;
            break;
        default:
            cout << "Operation system wasn't recognise" << endl;
    }


    return EXIT_SUCCESS;
}