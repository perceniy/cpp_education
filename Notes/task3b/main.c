#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

int powi(int d, int p) {
    if (p == 0) return 1;
    int result = d;
    for (int i = 1; i<p; i++) {
        result*=d;
    }
    return result;
}

struct nodeChar {
    struct nodeChar* Next;
    struct nodeChar* Prev;
    char ch;
};

typedef struct nodeChar nodeS;
// Объявим строку как двусвязный список с методами добавления и извлечения элементов
struct myStr {
    nodeS* Head;
    nodeS* Last;
    int length;
};

typedef struct myStr myString;

myString initString() {
    myString str;
    str.Head = NULL;
    str.Last = NULL;
    str.length = 0;
    return str;
}

// Добавление элемента в список

int push(myString* Q, char ch) {
    nodeS *tmp;
    tmp = (nodeS*) malloc(sizeof(nodeS));
    if (tmp != NULL) {

        tmp->ch = ch;
        tmp->Prev = NULL;
        tmp->Next = Q->Head;
        Q->length++;
        if (Q->length == 1) {
            Q->Head = tmp;
            Q->Last = tmp;
        } else {
            Q->Head->Prev = tmp;
            Q->Head = tmp;
        }
    } else {
        return 0;
    }
    return 1;
}

// Извлечение ведущего, первого добавленного, элемента

int getFront(myString* Q, char* ch) {
    if (Q->length > 0) {
        *ch = Q->Last->ch;
        nodeS* last;
        last = Q->Last;
        Q->length--;
        if (Q->length > 0) Q->Last = last->Prev;
        free(last);
    } else {
        return 0;
    }
    return 1;
}

// Извлечение крайнего, последнего добавленного элемента

int getBack(myString* Q, char* ch) {
    if (Q->length > 0) {
        *ch = Q->Head->ch;
        nodeS* head;
        head = Q->Head;
        Q->length--;
        if (Q->length > 0) Q->Head = head->Next;
        free(head);
    } else {
        return 0;
    }
    return 1;
}

void convertNumbers(myString* S) {
    char hex[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    unsigned int Digits[256];
    myString result = initString();
    char ch;
    int idx = 0, counter = 0;
    //Массив для декодирования кодов символов чисел в int
    for (int ch = '0', d = 0; ch <'9'; ch++, d++) Digits[ch] = d;
    //Будем считывать символы в обратном порядке, так как это удобно для конвертации
    while (getBack(S, &ch)) {
            if (ch == ' ') {
                if (counter > 0) {
                    push(&result, hex[idx]);
                }
            push(&result,' ');
            counter = 0;
            idx = 0;
            continue;
            }

            if (counter < 3) {
                idx += powi(2,counter)*Digits[ch];
                counter++;
            } else  {
                idx += powi(2,counter)*Digits[ch];
                push(&result, hex[idx]);
                idx = 0;
                counter = 0;
            }
    }
    if (counter > 0 ) push(&result, hex[idx]);
    //снова записываем в обратном порядке, чтобы вернуть исходный порядок символов
    while (getBack(&result,&ch)) push(S, ch);
};

void printString(myString* S) {
    char ch;
    while (getFront(S, &ch)) printf("%c", ch);
    printf("\n");
};

int main() {
    char temp[MAX_LENGTH];
    char chr = ' ';
    char flagEOL = '\n';
    int idx = 0;

    myString source = initString();
    myString workString = initString();

    //Цикл считывания строк
    //Для окончаня ввода нужно ввести ключевое слово EOF

    do {
        scanf("%s%c",temp, &flagEOL);
        if ((temp[0] == 'E') & (temp[1] == 'O') & (temp[2] == 'F')) break;
        idx = 0;
        while (temp[idx] != '\0') {
            if ((temp[idx] == '1') | (temp[idx] == '0')) push(&source, temp[idx]);
            idx++;
        }
        if (flagEOL == '\n') {
            push(&source,'\n');
        } else {
            push(&source, ' ');
        }
    } while (1);

    //Преобразования строк

    while (getFront(&source, &chr)) {
        if (chr == '\n') {
            convertNumbers(&workString);
            printString(&workString);

        } else {
            push(&workString, chr);
        }
    }

    return EXIT_SUCCESS;

    /** Вариант для считывания записей из файла **/
    /*
    FILE* file = fopen("../test.txt", "r");
    char temp[MAX_LENGTH];
    char flagEOL = '\n';
    int idx = 0;

    myString source = initString();

    if (file == NULL) {
        printf("File not found!\n");
        return EXIT_FAILURE;
    } else {
        printf("Reading file...\n");
    }

    while (fscanf(file, "%s%c", temp, &flagEOL) > 0) {
        idx = 0;
        while (temp[idx] != '\0') {
            push(&source, temp[idx++]);
        }
        // Если встретили символ перевода строки - отправляем текущую строку на конвертацию системы счисления
        if (flagEOL == '\n') {
            convertNumbers(&source);
            printString(&source);

        } else {
            push(&source, ' ');
        }

    };

    fclose(file);

    return EXIT_SUCCESS;
    */

};