#include <iostream>
#include <string>

using namespace std;
// Task 2
class Date {
protected:
    int m_day;
    int m_month;
    int m_year;
public:
    Date (int year, int month, int day): m_day(day), m_month(month), m_year(year) {};
    int get_day() const {
        return m_day;
    }
    int get_month() const {
        return m_month;
    }
    int get_year() const {
        return m_year;
    }
};

ostream& operator<<(ostream& os, const Date& date) {

    string z_day = "", z_month = "";
    z_day = date.get_day() > 10 ? "" : "0";
    z_month = date.get_month() > 10 ? "" : "0";
    cout << date.get_year() << "." << z_month << date.get_month() << "." << z_day << date.get_day();

    return os;
}

int main() {
    cout << endl << "<----------TASK 2---------->" << endl << endl;

    unique_ptr<Date> today = make_unique<Date>(2019,5,18);

    unique_ptr<Date> date;

    cout << "Today is: " << today->get_year() << "." << today->get_month() << "." << today->get_day() << endl;

    cout << "Today also is: " << *today << endl;

    date = move(today);

    cout << "Pointer today is " << ((today == nullptr) ? "null" : "not null") << endl;
    cout << "Pointer date is " << ((date == nullptr)  ? "null" : "not null") << endl;

    cout << "Now date is: " << *date << endl;

    cout << endl << "<----------TASK 3---------->" << endl << endl;


    return EXIT_SUCCESS;
}