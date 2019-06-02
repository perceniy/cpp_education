#include <iostream>

using namespace std;

class Parent {
public:
    virtual void fv() {
        cout << "virtual f parent" << endl;
    }
    void f () {
        cout << "f parent" << endl;
    }
};

class Child: public Parent {
public:
    virtual void fv() {
        cout << "virtual f child" << endl;
    }
    void f () {
        cout << "f child" << endl;
    }
};

int main() {

    Child* c1 = new Child();
    Parent* p1 = c1;

    c1->f();
    c1->fv();

    p1->f();
    p1->fv();

    return EXIT_SUCCESS;
}