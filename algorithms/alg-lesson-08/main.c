//
// Created by Арсений Сысоев on 2019-03-23.
//

//Lesson08

#include <stdio.h>
#include <stdlib.h>

#define arraySize 40

//Quick sort

void printArray(int* array, int size) {
    for (int i=0; i<size; i++) printf("%2d ", array[i]);
    printf("\n\n");
}

int checkArray(int* array, int size) {
    if (size < 2) return 1;
    for (int i=0; i<size-2; i++) if (array[i] > array[i+1]) return 0;
    return 1;
}
// Реализация получилось рабочей, но громоздкой, посмотрел в методичке как нужно было, но исправлять уже не стал

void quickSort(int* array, int left, int right, int* p) {
    *p = *p+1;
    int size = right - left;
    int base;
    int l_idx, r_idx;
    l_idx = left;
    r_idx = right;
    int buffer;
    int r_swap, l_swap;
    int counter = 0;
    /* Будем перемещать элементы только между собой на первом этапе, помечая их как ready_to_swap
     * Если слева или справа пришли к базовому элементу, то выполняем операцию сдвига
     */

    if (size > 1 ) {
        //выбираем опорный элемент
        base =(left + right)/2;
        while ((l_idx < r_idx) ) {
            l_swap = 0;
            r_swap = 0;
            if (array[l_idx] >= array[base]) l_swap = 1;
            if (array[r_idx] < array[base]) r_swap = 1;

            //Первый случай - пока не достигли base
            if ((l_idx < base) & (r_idx > base)) {
                //Если все готовы свопаться
                if (l_swap & r_swap) {
                    *p = *p+1;
                    buffer = array[l_idx];
                    array[l_idx] = array[r_idx];
                    array[r_idx] = buffer;
                    l_idx++;
                    r_idx--;
                } else {
                    if (l_swap == 0) l_idx++;
                    if (r_swap == 0) r_idx--;
                }
                // Теперь кто-то дошел до base
            } else {
                if ((l_idx == base) & r_swap) {
                    buffer = array[r_idx];
                    for (int idx = r_idx; idx > base; idx--) {
                        *p = *p+1;
                        array[idx] = array[idx - 1];
                    }
                    array[base] = buffer;
                    base++;
                    l_idx++;
                } else if ((l_idx == base) & (r_swap == 0)) {
                    r_idx--;
                } else if ((r_idx == base) & l_swap) {
                    buffer = array[l_idx];
                    for (int idx = l_idx; idx < base; idx++) {
                        *p = *p+1;
                        array[idx] = array[idx + 1];
                    }
                    array[base] = buffer;
                    base--;
                    r_idx--;
                } else if ((r_idx == base) & (l_swap == 0)) {
                    l_idx++;
                }
            }
        }
        quickSort(array,left,base, p);
        quickSort(array,base+1,right, p);
    } else {
        *p = *p+1;
        return;
    }
}

//Сортировка слиянием

void merge(int* array, int l, int r, int* p) {
    int idx, l_idx, r_idx;
    int array_l[arraySize/2+1], array_r[arraySize/2 + 1];
    int border = l + (r - l)/2;
    l_idx = 0;
    r_idx = 0;
    for (int j = l; j <= border; j++) {
        *p = *p+1;
        array_l[l_idx] = array[j];
        l_idx++;
    }
    for (int j = border + 1; j<=r; j++) {
        *p = *p+1;
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
                *p = *p+1;
            } else {
                array[idx] = array_r[r_idx];
                r_idx++;
                *p = *p+1;
            }
        } else if (l_idx <= border - l) {
            array[idx] = array_l[l_idx];
            l_idx++;
            *p = *p+1;
        } else  {
            array[idx] = array_r[r_idx];
            r_idx++;
            *p = *p+1;
        }
        idx++;
    }

}

void mergeSort(int* array, int l, int r, int* p) {
    int buffer;

    if (l == r) {
        *p = *p+1;
        return;
    }
    if (r - l == 1) {
        if (array[r] < array[l]) {
            buffer = array[l];
            array[l] = array[r];
            array[r] = buffer;
            *p = *p+1;
        }
    }
    else
    {
        mergeSort(array, l, l + (r - l) / 2, p);
        mergeSort(array, l + (r - l) / 2 + 1, r, p);
        merge(array, l, r, p);  // Сливаем массивы
    }

}


int main (int argc, const char* argv[]) {

    int p;

    int array[arraySize]  =  {20,19,18,17,16,15,14,8,9,10,11,12,7,6,5,4,3,2,1,13,20,19,18,17,16,15,14,8,9,10,11,12,7,6,5,4,3,2,1,13};
    int array2[arraySize] =  {20,19,18,17,16,15,14,8,9,10,11,12,7,6,5,4,3,2,1,13,20,19,18,17,16,15,14,8,9,10,11,12,7,6,5,4,3,2,1,13};

    p = 0;
    printf("quickSort\n\n");
    quickSort(array, 0, arraySize-1, &p);
    printArray(array, arraySize);
    printf("Iterations: %d\n", p );
    printf("Check: %d\n",checkArray(array,arraySize));

    printf("\nmergeSort\n\n");

    p = 0;
    mergeSort(array2, 0, arraySize - 1, &p);

    printArray(array2, arraySize);
    printf("Iterations: %d\n", p );
    printf("Check: %d\n",checkArray(array2,arraySize));

    return EXIT_SUCCESS;

}