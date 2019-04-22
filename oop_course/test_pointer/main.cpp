#include <iostream>

//This is pointers and links magic

class Date
{
private:
    int m_day;
    int m_month;
    int m_year;

public:
    Date* datePointer;
    Date** pointerPointer;

    Date(int day, int month, int year)
    {
        setDate(day, month, year);
    }

    void setDate(int day, int month, int year)
    {
        m_day = day;
        m_month = month;
        m_year = year;
    }

    int getDay() const { return m_day; }
    int getMonth() const { return m_month; }
    int getYear() const { return m_year; }

    void printPointerAddress(){
        /*Мы печатаем адрес переменной-указателя на класс*/
        pointerPointer = &datePointer;
        std::cout << pointerPointer << '\n';
    };
};

// Мы передаем объект date по константной ссылке, чтобы избежать создания копии объекта date
void printDate(const Date &date)
{
    std::cout << date.getDay() << "." << date.getMonth() << "." << date.getYear() << '\n';
}

void printDatePointer(Date* date) {
    (*date).setDate(20,3,2019);
    std::cout << (*date).getDay() << "." << (*date).getMonth() << "." << (*date).getYear() << '\n';
    std::cout << date << '\n';
}

struct type {
    int i;

    type(): i(3) {}

    void f(int v) const {
        // this->i = v;                 // compile error: this is a pointer to const
        const_cast<type*>(this)->i = v; // OK as long as the type object isn't const
    }
};

int main()
{
    Date date(12, 11, 2018);
    printDate(date);

    Date* pointerTest;

    pointerTest = &date;

    date.datePointer = pointerTest;

    std::cout << date.datePointer << std::endl;
    std::cout << &date << std::endl;

    printDatePointer(date.datePointer);

    date.printPointerAddress();



    int i{3};                 // i is not declared const
    const int& rci = i;
    const_cast<int&>(rci) = 4; // OK: modifies i
    std::cout << "i = " << i << '\n';

    uint16_t q = 3;

    std::cout << "q = " << q << "; size of q: " << sizeof(q)<<'\n';

    type t2;

    std::cout << "t2.i = " << t2.i << '\n';

    type t; // if this was const type t, then t.f(4) would be undefined behavior
    t.f(4);
    std::cout << "type::i = " << t.i << '\n';

    const int j = 3; // j is declared const
    int* pj = const_cast<int*>(&j);
    // *pj = 4;      // undefined behavior

    void (type::* pmf)(int) const = &type::f; // pointer to member function
    // const_cast<void(type::*)(int)>(pmf);   // compile error: const_cast does
    // not work on function pointers

    char a = 'a';
    std::cout << sizeof(a) << std::endl;
    return 0;
}
