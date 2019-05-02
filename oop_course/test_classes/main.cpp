#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
    string m_name;
    int m_id;

public:
    Car(string name, int id) : m_name(name), m_id(id)
    { }

    string getName() { return m_name; }
    int getId() { return m_id;  }
};


// Данный класс содержит автомобили и имеет функцию для "выдачи" автомобиля

class CarLot
{
private:
    static Car s_carLot[4];


public:
    // Удаляем конструктор по умолчанию, чтобы нельзя было создать объект этого класса
    CarLot() = delete;
    static int var;

    static Car* getCar(int id)
    {
        for (int count = 0; count < 4; ++count)
            if (s_carLot[count].getId() == id)
                return &(s_carLot[count]);

        return nullptr;
    }


};

int CarLot::var = 5;

Car CarLot::s_carLot[4] = { Car("Camry", 5), Car("Focus", 14), Car("Vito", 73), Car("Levante", 5) };

class Driver
{
private:
    string m_name;
    int m_carId; // для связывания классов используется эта переменная

public:

      Driver(string name, int carId) : m_name(name), m_carId(carId)
    {  }
    string getName() { return m_name; }
    int getCarId() { return m_carId; }

};

int main()
{
    Driver d("Ivan", 5); // Ivan ведет машину с ID 14

    Car *car = CarLot::getCar(d.getCarId()); // Получаем этот Автомобиль из CarLot

    if (car)
        cout << d.getName() << " is driving a " << car->getName() << '\n';
    else
        cout << d.getName() << " couldn't find his car\n";

    cout << CarLot::var << endl;

    return EXIT_SUCCESS;
}
