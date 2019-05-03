/*
 *  Homework-03
 *
 *  Created on: Mar 3, 2019
 *  Author: arseniy
 */


/*
 *  Задача 1.
 *  Попробовать оптимизировать пузырьковую сортировку.
 *  Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
 *  Написать функции сортировки, которые возвращают количество операций.
 */

#include <stdio.h>
#include <math.h>

void bubbleSort(int* array, int size, int* p) {
    int temp;
    int counter;
    for (int i = 0; i < (size - 1); i++) {
        counter = 0;
        for (int j = 0; j < size - 1 - i; j++ ) {
            *p = *p + 1;
            if (array[j]> array[j+1]) {

                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void bubbleSortAdv(int* array, int size, int* p) {
    int temp;
    int counter;
    for (int i = 0; i < (size - 1); i++) {
        counter = 0;
        for (int j = 0; j < size - 1 - i; j++ ) {
            *p = *p + 1;
            if (array[j]> array[j+1]) {

                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                counter++;
            }
        }
        if (counter == 0) break;
    }
}

/*
 * 2. Реализовать шейкерную сортировку
 */

void ShakeSort(int* array, int size, int* p) {
    int temp;
    int counter;
    for (int i = 0; i < (size - 1); i++) {
        counter = 0;
        /* Проход в прямую сторону */
        for (int j = i; j < size - 1 - i; j++ ) {
            *p = *p + 1;
            if (array[j] > array[j+1]) {

                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                counter++;
            }
        }
        if (counter == 0) break;

        /* Проход в обратную сторону */
        for (int j = size - 1 - i ; j > i; j-- ) {
            *p = *p + 1;
            if (array[j] < array[j-1]) {

                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
                counter++;
            }

        }
        if (counter == 0) break;
    }

}

/*
 * 3. Реализовать бинарный алгоритм поиска в виде функции,
 * которой передается отсортированный массив.
 * Функция возвращает индекс найденного элемента или -1, если элемент не найден.
 */



int binSearch(int num, int* array, int l, int r, int* p) {

    *p = *p + 1;
    //printf("\nInteration: %d; l: %d; r: %d", *p, l, r );

    if (num < array[l] | num > array[r]) return -1;

    int border = (r+l)/2;

    if (r - l < 3) {
        if (array[l] == num) return l;
        if (array[r] == num) return r;
        if (array[border] == num) return border;
    }
    else if (num >= array[border]) {
        l = border;
        return binSearch(num, array, l, r, p);
    } else {
        r = border - 1;
        return binSearch(num, array, l, r, p );
    }

    return -1;
}


int main(int argc, const char* argv[]) {



    const int s = 25;
    int p = 0;
    int array[s] = {0,1,2,3,4,5,6,10,7,24,9,11,13,12,14,15,16,17,18,19,20,21,22,8,23};
    int c_array[s],b_array[s];

    printf("\nInitial array:\n");
    for (int j = 0; j < s; j++) {
        printf("%d ",array[j]);
        b_array[j] = array[j];
        c_array[j] = array[j];
    }

    printf("\n\nTask 1.\n");


    printf("\nSimple bubble sort:\n");
    p = 0;
    bubbleSort(array,s,&p);
    for (int j = 0; j < s; j++) printf("%d ",array[j]);
    printf("\nIterations: %d\n", p);

    printf("\nAdvanced bubble sort:\n");
    p = 0;
    bubbleSortAdv(b_array,s,&p);
    for (int j = 0; j < s; j++) printf("%d ",b_array[j]);
    printf("\nIterations: %d\n", p);

    printf("\nTask 2.\n\nShake sort:\n");

    p = 0;
    ShakeSort(c_array,s,&p);
    for (int j = 0; j < s; j++) printf("%d ",c_array[j]);
    printf("\nIterations: %d\n", p);

    printf("\nTask 3.\n\nBinary search:\n");

    int l = 0;
    int r = s-1;
    int n = 4;

    p = 0;
    printf("Position of %d: %d", n, binSearch(n, c_array, l, r, &p));

    return 0;
}