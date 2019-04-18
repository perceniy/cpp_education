#include <iostream>

class Date
{
private:
    int m_day;
    int m_month;
    int m_year;

public:
    Date* date_next;

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
};

// Мы передаем объект date по константной ссылке, чтобы избежать создания копии объекта date
void printDate(const Date &date)
{
    std::cout << date.getDay() << "." << date.getMonth() << "." << date.getYear() << '\n';
}

void testFunc(int* a) {
    std::cout << a << std::endl;
    std::cout << *a << std::endl;

}

int main()
{
    Date date(12, 11, 2018);
    printDate(date);

    Date* dateTest;

    dateTest = &date;

    date.date_next = dateTest;

    std::cout << date.date_next << std::endl;
    std::cout << &date << std::endl;


    int b = 6;

    testFunc(&b);

    return 0;
}
