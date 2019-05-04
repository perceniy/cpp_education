//
// Created by Арсений Сысоев on 2019-05-04.
//

#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert> // для assert()

class ArrayInt
{
private:
    int m_length;
    int *m_data;

    void merge(int* array, int l, int r) {
        int idx, l_idx, r_idx;
        int array_l[(r-l)/2 + 1], array_r[(r-l)/2 + 1];
        int border = l + (r - l)/2;
        l_idx = 0;
        r_idx = 0;
        for (int j = l; j <= border; j++) {
            array_l[l_idx] = array[j];
            l_idx++;
        }
        for (int j = border + 1; j<=r; j++) {
            array_r[r_idx] = array[j];
            r_idx++;
        }
        idx = l;
        l_idx = 0;
        r_idx = 0;
        while (idx <= r) {
            if ((l_idx <= border - l) & (r_idx < r - border ) ) {
                if (array_l[l_idx]<array_r[r_idx]) {
                    array[idx] = array_l[l_idx];
                    l_idx++;
                } else {
                    array[idx] = array_r[r_idx];
                    r_idx++;
                }
            } else if (l_idx <= border - l) {
                array[idx] = array_l[l_idx];
                l_idx++;
            } else  {
                array[idx] = array_r[r_idx];
                r_idx++;
            }
            idx++;
        }

    }

    void mergeSortRecursive(int* array, int l, int r) {
        int buffer;

        if (l == r) {
            return;
        }
        if (r - l == 1) {
            if (array[r] < array[l]) {
                buffer = array[l];
                array[l] = array[r];
                array[r] = buffer;
            }
        }
        else
        {
            mergeSortRecursive(array, l, l + (r - l) / 2);
            mergeSortRecursive(array, l + (r - l) / 2 + 1, r);
            merge(array, l, r);  // Сливаем массивы
        }

    }

public:
    ArrayInt(): m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length):
            m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        // Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
        m_data = nullptr;
        m_length = 0;
    }

    int getLength() { return m_length; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // Функция resize изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
    void resize(int newLength)
    {
        // Если массив уже нужной длины — return
        if (newLength == m_length)
            return;

        // Если нужно сделать массив пустым — делаем это и затем return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // Теперь знаем, что newLength >0
        // Выделяем новый массив
        int *data = new int[newLength];

        // Затем нужно разобраться с количеством копируемых элементов в новый массив
        // Нужно скопировать столько элементов, сколько их есть в меньшем из массивов
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            // Поочередно копируем элементы
            for (int index=0; index < elementsToCopy ; ++index)
                data[index] = m_data[index];
        }

        // Удаляем старый массив, так как он нам уже не нужен
        delete[] m_data;

        // И используем вместо старого массива новый! Обратите внимание, m_data указывает
        // на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
        // данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        // Проверка корректности передаваемого индекса
        assert(index >= 0 && index <= m_length);

        // Создаем новый массив на один элемент больше старого массива
        int *data = new int[m_length+1];

        // Копируем все элементы до index-а
        for (int before=0; before < index; ++before)
            data[before] = m_data[before];

        // Вставляем новый элемент в новый массив
        data [index] = value;

        // Копируем все значения после вставляемого элемента
        for (int after=index; after < m_length; ++after)
            data[after+1] = m_data[after];

        // Удаляем старый массив и используем вместо него новый
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void delete_element(int index) {
        assert(index>=0 && index < m_length && m_length > 0);

        int *data  = new int[m_length - 1];

        // Перемещаем элементы до индекса
        for (int i = 0; i < index; ++i) data[i] = m_data[i];

        for (int i = index; i < m_length - 1; ++i) data[i] = m_data[i+1];

        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void insertArray(int index, int array[], int a_length) {
        // Функция вставляет в исходный массив элементы из нового массива, начиная с позиции index;
        assert(index >= 0 && index < m_length);

        int* data = new int[a_length + m_length];

        for (int i = 0; i < index; ++i) data[i] = m_data[i];
        for (int i = 0; i < a_length; ++i) data[index + i] = array[i];
        for (int i = index; i < m_length; ++i) data[index + a_length + i] = m_data[i];

        delete[] m_data;
        m_data = data;
        m_length += a_length;
    }

    int pop_back () {
        assert(m_length > 0);
        int buf = m_data[m_length-1];
        delete_element(m_length-1);
        return buf;
    }

    void printArray() {
        for (int i = 0; i<m_length; ++i) {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }

    void mergeSort() { mergeSortRecursive(m_data, 0, m_length-1); }

};

#endif
