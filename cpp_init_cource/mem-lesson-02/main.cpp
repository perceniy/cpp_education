// Составить и проверить в действии функцию, составляющую 32-разрядное беззнаковое целое значение
// uint32_t из четырех байт данных. Обращаться со значением нужно при этом как с простым массивом
// из 4 элементов типа unsigned char. При этом:
// Использовать указатели;
// Применить операции приведения типов данных;
// Заполненное 32-разрядное значение должно быть возвращено из функции.

#include <iostream>

using namespace std;

uint32_t get_int(const unsigned char* bytes) {
    uint32_t number = 0;
    uint32_t buffer = 0;
    // Используем операцию сдвига на 8 бит, чтобы освободить место справа для нового байта
    for (int i = 0; i < 4; ++i) {
        number = number<<8;
        buffer = static_cast<uint32_t>(bytes[i]);
        // buffer будет заполнен нулями, кроме первых 8 бит, поэтому побитовое "или" добавит их в number
        number = number | buffer;
    }

    return number;
}

using namespace std;

int main() {
    unsigned char bytes[4] = {255,2,4,9};
    uint32_t num =  get_int(bytes);

    cout << "Num is: "<< num << endl;

    cout << "Line of bits:"<< endl;
    for (int i = 31; i > -1; --i) {
        cout << ((num>>i) & 1 ) << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}