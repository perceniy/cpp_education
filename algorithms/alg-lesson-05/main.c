//
// Created by Арсений Сысоев on 2019-03-12.
// Lesson 05
//
// Программа проверяет правильность расстановки скобок и переводит введенное выражение в постфиксную форму записи
// Например выражение {[(A+C*D)+(X*Y+Z)]/[B*D]} было преобразовано в ACD*+XY*Z++BD*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Опишем стек из символов*/

/*
 *      stack
 *         node
 *           value
 *           next   ----> node
 *                          value
 *                          next  ----> node
 *                                        value
 *                                        next  ---> NULL
 * */

struct TNodeChar {
    char value;
    struct TNodeChar* next;
};

typedef struct TNodeChar NodeChar;

struct sChar {
    NodeChar* head;
    int size;
    int maxSize;
};

typedef struct sChar stackChar;

/*Реализуем добавление и изятие из стека как функции, которые возвращают
 * 1 - если операция прошла успешна
 * 0 - если операцию совершить не удалось
 */

int push(stackChar* Stack, char value) {
    if (Stack->size >= Stack->maxSize) {
        printf("\nError pushing: stack is full");
        return 0;
    }
    NodeChar *tmp;
    tmp = (NodeChar*) malloc(sizeof(NodeChar));
    /*Проверка на выделение памяти*/
    if (tmp != NULL) {
        //  printf("Add %c\n", value);
        tmp->value = value;
        tmp->next = Stack->head;
        Stack->head = tmp;
        Stack->size++;
    } else {
        printf("\nError allocating memory!");
        return 0;
    }
    return 1;
}

int pop(stackChar* Stack, char* value) {
    if (Stack->size == 0) {
        printf("\nError getting elements: stack is empty.\n");
        return  0;
    }
    *value = Stack->head->value;
    NodeChar* next = NULL;
    next = Stack->head;
    Stack->head = Stack->head->next;
    Stack->size--;
    free(next);
    return 1;
}

/*Опишем матрицу решений - как будем действовать в зависимости от текущих элементов */

int getDecision(char current, char prev) {

    if (current == '@') return 0;
    /* dMatrix:
     *   ➞➞➞➞➞ current (string)
     * ↓
     * ↓
     * ↓
     * ↓
     * prev (stack)
     */

    const int dMatrix[6][7] = {
             {4,1,1,1,1,1,5}
            ,{2,2,2,1,1,1,2}
            ,{2,2,2,1,1,1,2}
            ,{2,2,2,2,2,1,2}
            ,{2,2,2,2,2,1,2}
            ,{5,1,1,1,1,1,3}
    };

    const char elements[11] = {'$','+','^','*','/','(',')','[',']','{','}'};

    int indexCurrent = -1, indexPrev = -1;

    for (int i = 0; i < 11; i++) if (current == elements[i]) {indexCurrent = i; break;}
    for (int i = 0; i < 11; i++) if (prev == elements[i]) {indexPrev = i; break;}

    /*Добавим обработку, чтобы можно было вводить не только круглые скобки*/
    if (indexCurrent == 7 ^ indexCurrent == 9) indexCurrent = 5;
    if (indexCurrent == 8 ^ indexCurrent == 10) indexCurrent = 6;
    if (indexPrev == 7 ^ indexPrev == 9) indexPrev = 5;
    if (indexPrev == 8 ^ indexPrev == 10) indexPrev = 6;

    return (indexCurrent > -1 & indexPrev > -1) ? dMatrix[indexPrev][indexCurrent] : 6;
}

/*Сделаем функцию, которая будет делать нужный нам тип операции
 * В случае ошибки возвращаем 0*/

int makeStep(stackChar *Stack, stackChar *Expression, char *result, int decision ) {
    char prev;
    char tmp;
    char current;

    if (decision == 0) {
        pop(Expression, &current);
        strcat(result, &current);
    }
    else if (decision == 1) {
        pop(Expression, &current);
        push(Stack, current);

    } else if (decision == 2) {
        pop(Stack, &prev);
        strcat(result, &prev);

    } else if (decision == 3) {
        pop(Stack, &tmp);
        pop(Expression,&tmp);

    } else if (decision == 4){
        return 1;
    } else if (decision == 5){
        return 0;
    } else if (decision == 6){
        return 0;
    }
    return 1;
}

int main(int argc, const char* argv[]) {
    char current, comp, crntCode, prevCode;
    const int maxLen = 1024;
    stackChar bracketStack;
    stackChar exprStack;
    stackChar tempStack;
    char expression[maxLen];
    char res[maxLen];
    char *pnt;

    const char elements[11] = {'$','+','^','*','/','(',')','[',']','{','}'};

    int len = 0;
    int checkResult = 0;
    int decision;

    bracketStack.head = NULL;
    bracketStack.maxSize = maxLen;
    bracketStack.size = 0;

    exprStack.head = NULL;
    exprStack.maxSize = maxLen;
    exprStack.size = 0;

    tempStack.head = NULL;
    tempStack.maxSize = maxLen;
    tempStack.size = 0;

    printf("Input expression to transform: \n");
    gets(expression);
    // {[(A+C*D)+(X*Y+Z)]/[B*D]}

    len = strlen(expression);

    const char brackets[6] = "()[]{}";

    /*Проверим на правильность последовательности скобок*/

    checkResult = 1;
    for (short i = 0; i < len; i++) {
        current = expression[i];
        pnt = strchr(brackets, current);
        if  (pnt != NULL) {
            if (strchr("([{", current)) {
                push(&bracketStack, expression[i]);
            } else {
                if (pop(&bracketStack, &comp)) {
                    /*Для сравнения скобок используем арифметику указателей и строку brackets*/
                    if (strchr(brackets, comp) == pnt -1) {
                        continue;
                    } else {
                        checkResult = 0;
                        break;
                    }
                } else {
                    checkResult = 0;
                    break;
                }
            }
        }
    }

    if (checkResult == 0 ^ bracketStack.size > 0 ) {
        printf("\nExpression contains errors in brackets.\n");
        return EXIT_FAILURE;
    }

    // Добавляем специальные символы, обозначающие начало и конец последовательности.
    push(&tempStack,'$');
    push(&exprStack,'$');
    for (int j = len - 1; j >= 0; j--)push(&exprStack,expression[j]);


    /*Теперь можем реализовать перевод из инфиксной записи в постфиксную*/
    /*Будем действовать по алгоритму, предложенному Dijkstra*/

    while (exprStack.size > 0 ) {

        crntCode = strchr(elements, exprStack.head->value) == NULL ? '@':exprStack.head->value;
        decision = getDecision(crntCode, tempStack.head->value);
        printf ("Current: %c, Stack: %c, Decision: %d, Result: ", exprStack.head->value, tempStack.head->value, decision);

        if (decision < 4){
            makeStep(&tempStack, &exprStack, res, decision);
            puts(res);
        } else {
            puts(res);
            break;
        }
    }

    if (decision == 5) {
        printf("Error in expression! Unable to transform.\n");
        return EXIT_FAILURE;
    }

    printf("\nResult:\n");
    puts(res);

    return EXIT_SUCCESS;
}