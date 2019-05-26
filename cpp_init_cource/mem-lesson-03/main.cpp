
//Составить программу, выводящую на экран текущую среду сборки (Windows/Linux),
//дату и время последней успешной сборки. Использовать константу TIME для вывода времени.


#include <iostream>
#include <stdlib.h>
using namespace std;

#ifdef __APPLE__
#define operating_system_sd 1
#endif

#ifdef _WIN32
#define operating_system_sd 2
#endif

#ifdef __linux__
#define operating_system_sd 3
#endif

#ifndef operating_system_sd
#define operating_system_sd 0
#endif

int main() {

    cout << "Last building date and time: "<< __DATE__ << " " << __TIME__ << endl;
    cout << "C++ version: "<< __cplusplus << endl;

    switch (operating_system_sd) {
        case 1:
            cout << "Building environment is Apple" << endl;
            break;
        case 2:
            cout << "Building environment is Windows" << endl;
            break;
        case 3:
            cout << "Building environment is Linux" << endl;
            break;
        default:
            cout << "Operation system doesn't recognise" << endl;
    }

    return EXIT_SUCCESS;
}
