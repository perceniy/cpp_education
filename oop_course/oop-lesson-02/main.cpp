#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class MyRandom {
private:
    mutable int number;
    mutable bool cashFlag;
public:
    // Конструктор по умолчанию
    MyRandom () {
        number = 0;
        cashFlag = false;
    }
    // Конструктор копирования
    MyRandom (const MyRandom & myRandom) {
        this->number = myRandom.number;
        this->cashFlag = myRandom.cashFlag;
        cout << "Success coping" << endl;
    }
    int current () const {
        if (!cashFlag) {
            cout << "The number was not generated yet!" << endl;
        };
        return number;
    }
    int next () const {
        number = rand();
        cashFlag = true;
        return number;
    }

};

class Person {
private:
    string name;
    int age;
    string gender;
    float weight;
public:
    Person();
    Person(string namei, int agei, string genderi, float weight): name(namei), age(agei), gender(genderi), weight(weight) {
        cout<<"The normal initilization of class person"<< endl;
    }

    void set_weight(float weight) {
        this->weight = weight;
    }
    void set_age(int age) {
        this->age = age;
    }
    void set_name(string name) {
        this->name = name;
    }
    void printPerson() const {
        cout <<"Name: " << name <<"; Age: " << age <<"; Gender: " << gender << "; Weight: " << weight << endl;
    }

    friend class Student;

};

Person::Person() {
    name = "Undefined";
    age = 0;
    gender = "None";
    weight = 0.0f;
    cout<<"The default initilization of class person"<< endl;
}

class Student: public Person {
private:
    int graduationYear;
public:
    Student () {
        graduationYear = 2000;
    }
    Student(string namei, int agei, string genderi, float weight, int graduationYeari):
        Person(namei, agei, genderi, weight), graduationYear(graduationYeari) {}

    void set_gyear(int graduationYear) {
        this->graduationYear = graduationYear;
    }
    void inc_gyear(int gap) {
        this->graduationYear += gap;
    };
    void printStudent() const {
        cout <<"Name: " << name <<"; Age: " << age <<"; Gender: " << gender << "; Weight: " << weight << "; Year: "<< graduationYear<<endl;
    }
};


int main() {

    MyRandom generator;
    cout << "Current: "<< generator.current() << "; Next: " << generator.next() << endl;
    cout << "Current: "<< generator.current() << "; Next: " << generator.next() << endl;
    MyRandom copyGen(generator);
    cout << "Current: "<< copyGen.current() << "; Next: " << copyGen.next() << endl;
    cout << endl;

    Person defaultPerson;
    defaultPerson.printPerson();
    defaultPerson.set_age(32);
    defaultPerson.set_name("Arceniy");
    defaultPerson.set_weight(60.3f);
    defaultPerson.printPerson();
    cout << endl;

    cout << "Create a new default student" << endl;
    Student defaultStudent;
    defaultStudent.set_weight(25.0f);
    defaultStudent.printPerson();

    Student newStudent("Ivan", 27, "Male", 65.5f , 2019);
    newStudent.printStudent();

    newStudent.set_gyear(2010);
    newStudent.inc_gyear(2);
    newStudent.printStudent();

    return EXIT_SUCCESS;
}