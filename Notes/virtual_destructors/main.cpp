#include <iostream>
#include <string>

using namespace std;

class parent {
protected:
    string my_name;
public:
    parent(){
        my_name = "Undefined";
        cout << "Default parent:"<< my_name << endl;
    };

    virtual ~parent() {
        cout << "Parent destructor: " <<  my_name <<endl;
    };

    virtual int get_c() {};
    virtual int* get_p() {};

    //Конструкторы string, string * и string & были интерпретированны, как равнозначные, поэтму пришлось их дополнить
    //добавочными переменными, которые нигде не участвуют в дальнейшем.
    //Лучше всего передавать по константной ссылке, так как в этом случае мы избегаем дополнительного копирования
    parent(string name , int a): my_name(name) {
        name = "Alex";
        cout << "Pass value by coping data" << endl;
    }

    parent(string *name, double b){
        my_name = *name;
        *name = "Alex";
        cout << "Pass value trough the pointer" << endl;
    }

    // Обращаем внимание, что тут была осуществлена передача через ссылку,
    // а в самом коде указываем просто имя переменной...
    parent(string &name, int a, int b): my_name(name) {
        name = "Martin";
        cout << "Pass value trough the constant variable" << endl;

    }

    string get_name() const {
        return my_name;
    }
};

class child : public parent {
protected:
    int c = 5;
public:
    child() {};
    virtual ~child() {
        cout << "Child destructor: "<<  my_name << endl;
    }

    child(const string &name) {
        my_name = name;
    };
    int get_c() {
        return c;
    }
    int* get_p() {
        return &c;
    }
};

class grandChild: public child {
public:
    grandChild() = default;
    virtual ~grandChild() {
        cout << "Grant child desctructor: "<< my_name << endl;
    }
};

int main() {

    // Пример того, как можно передавать значения в класс, но лучше не делать так, ибо это открывает возможность
    // изменять переменные находящиеся во внешней по отношению к классу области видимости.
    // Лучше всего передавать через константную ссылку.
    string name = "Arceniy";
    string * p_name = &name;

    parent member1(p_name, 1.5);

    cout<<"Member1: "<< *p_name << endl;

    parent member2(name, 1, 1);

    cout<<"Member2: "<< name << endl;

    parent *member3 = new child("Ivan");

    cout << "Member3: " << member3->get_name()<<endl;

    // Если убрать delete - получится херня полная, и ни один деструктор для данного экземпляра вообще не вызовится

    int* pp = member3->get_p();

    delete member3;

    // Очень странно, но при удалении member 3 значение осталось в памяти.
    cout << "Member3" << " p:" << pp <<"; *p: "<< *pp <<endl;

    grandChild member4;

    parent &member4link = member4;

    return EXIT_SUCCESS;
}