#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//Task 1
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

//Task 3

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
    // Определим дочерний класс как дружественный, чтобы иметь доступ к private переменным
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

//Task 3

class Fruit {
private:
    string name;
    string colour;
public:
    Fruit () {
        name = "Undefined";
        colour = "Undefined";
    }
    Fruit (string name, string colour): name(name), colour(colour) {};
    string getName() const {
        return name;
    };
    string getColor() const {
        return colour;
    };
};

class Banana: public Fruit {
public:
    Banana(): Fruit("banana","yellow") {
    };
};

class Apple: public Fruit {
public:
    Apple():Fruit("apple","green") {};
    Apple(string colour):Fruit("apple", colour) {};
    Apple(string name, string colour):Fruit(name,colour) {};
};

class GrannySmith: public Apple {
public:
    GrannySmith():Apple("Granny Smith apple","green") {}
};

int main() {

    //Task 1

    MyRandom generator;
    cout << "Current: "<< generator.current() << "; Next: " << generator.next() << endl;
    cout << "Current: "<< generator.current() << "; Next: " << generator.next() << endl;
    MyRandom copyGen(generator);
    cout << "Current: "<< copyGen.current() << "; Next: " << copyGen.next() << endl;
    cout << endl;

    //Task 2

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
    cout << endl;

    //Task 3

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << endl;
    std::cout << "My " << b.getName() << " is " << b.getColor() << endl;
    std::cout << "My " << c.getName() << " is " << c.getColor() << endl;

    return EXIT_SUCCESS;
}