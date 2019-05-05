#include <iostream>
#include <vector>
#include <ArrayInt.h>
#include <Queue.h>

using namespace std;

int main(int argc, const char** args) {

    //Задание 1 - расширение функциональности класса ArrayInt

    cout << endl << "============ Task 1 ============" << endl << endl;

    ArrayInt myArray;
    cout << "Method insertBefore" << endl;
    myArray.insertBefore(1,myArray.getLength());
    myArray.insertBefore(2,myArray.getLength());
    myArray.insertBefore(3,myArray.getLength());
    myArray.insertBefore(4,myArray.getLength());
    myArray.insertBefore(5,myArray.getLength());
    myArray.printArray();

    cout << "Delete element" << endl;
    myArray.delete_element(1);
    myArray.printArray();
    cout << "Insert array" << endl;
    int newArray[5] = {9,6,7,8,0};
    myArray.insertArray(2, newArray, 5);
    myArray.printArray();
    cout << "Method pop_back" << endl;
    myArray.pop_back();
    myArray.printArray();

    cout << "Merge Sort" << endl;
    myArray.mergeSort();
    myArray.printArray();

    //Задание 2

    cout << endl << "============ Task 2 ============"<< endl << endl;

    QueueInt myQueue; // создаем пустую очередь

    // добавили в очередь несколько элементов
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    cout << "Количество элементов в очереди: " << myQueue.size();
    cout << "\nВот первый: " << myQueue.front() << "\nВот последний: " << myQueue.back();

    myQueue.pop();     // удаляем один элемент в очереди
    cout << "\nКоличество элементов в очереди: " << myQueue.size();
    cout << "\nВот первый: " << myQueue.front() << "\nВот последний: " << myQueue.back() << endl;

    return EXIT_SUCCESS;
}