#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Pair1 {
protected:
    T v1;
    T v2;
public:
    Pair1(T var1, T var2): v1(var1), v2(var2) {}
    T first() const {return v1;}
    T second() const {return v2;}
};

template <typename T1, typename T2>
class Pair {
protected:
    T1 v1;
    T2 v2;
public:

    Pair(T1 var1, T2 var2): v1(var1), v2(var2) {}
    T1 first() const {return v1;}
    T2 second() const {return v2;}
};

template <typename T>
class StringValuePair: public Pair<string, T> {
public:
    StringValuePair(string v1, T v2): Pair <string,T> (v1, v2) {
    };
};

int main()
{
    cout << endl << "============ Task 1 ============" << endl << endl;

    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    cout << endl << "============ Task 2 ============" << endl << endl;

    Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    cout << endl << "============ Task 3 ============" << endl << endl;

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return EXIT_SUCCESS;
}
