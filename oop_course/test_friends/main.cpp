#include <iostream>
#include <string>

using namespace std;

class Me {
private:
    string name;
public:
    Me () {
        name = "Arceniy";
        cout << "Default constructor of Me" << endl;
    }
    friend class CopyOfMe;
};

class CopyOfMe {
private:
    int age;
    Me me;
public:
    CopyOfMe (): age(5), me() {
        cout << "Default constructor of CopyOfMe" << endl;
        // Обращаем внимание, что если не сделать класс CopyOfMe дружественным классу Me,
        // то не не будем иметь доступ к его членам в классе CopyOfMe
        cout << "My name is " << me.name << endl;
    }

};

int main() {

    CopyOfMe copy;

    return EXIT_SUCCESS;
}