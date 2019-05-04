#include <iostream>
#include <vector>
#include <ArrayInt.h>

using namespace std;

int main(int argc, const char** args) {

    ArrayInt myArray;

    myArray.insertBefore(1,myArray.getLength());
    myArray.insertBefore(2,myArray.getLength());
    myArray.insertBefore(3,myArray.getLength());
    myArray.insertBefore(4,myArray.getLength());
    myArray.insertBefore(5,myArray.getLength());

    myArray.printArray();

    myArray.delete_element(1);

    myArray.printArray();

    int newArray[3] = {5,6,7};

    myArray.insertArray(1, newArray, 3);

    myArray.printArray();

    myArray.pop_back();

    myArray.printArray();

    cout << "Merge Sort" << endl;
    myArray.mergeSort();
    myArray.printArray();

    return EXIT_SUCCESS;
}