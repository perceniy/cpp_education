//
// Created by Арсений Сысоев on 2019-03-22.
//

//Lesson07
//Реализация алгоритма дейкстры

/* Test file
    0 1 2 0 0 0 5 0 9 0
    1 0 0 1 0 0 0 0 0 0
    2 0 0 2 5 6 8 0 0 0
    0 1 2 0 8 0 0 1 0 0
    0 0 5 8 0 5 0 0 0 0
    0 0 6 0 5 0 6 0 0 0
    5 0 8 0 0 6 0 0 3 0
    0 0 0 1 0 0 0 0 2 3
    9 0 0 0 0 0 3 2 0 4
    0 0 0 0 0 0 0 3 4 0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define matrixSize 10

// Вершина графа для обхода, которые будем хранить в массиве
// Будем хранить номер вершины, статус и текущее минимальное значение пути до этой вершины

struct nodeAs {
    int Status; // 0 - точка не обработана; 1 - проверка начата;
    int minTraverse;
};

typedef struct nodeAs nodeA;

//Реализуем очередь в виде двусвязанного списка

struct nodeQs {
    struct nodeQs* Next;
    struct nodeQs* Prev;
    int vertexNum; //Тут будем хранить индекс вершины в массиве
};

typedef struct nodeQs nodeQ;

struct Queues {
    nodeQ* Head;
    nodeQ* Last;
    int lengthQueue;

};

typedef struct Queues Queue;

int push(Queue* Q, int vertexNum) {
    nodeQ *tmp;
    tmp = (nodeQ*) malloc(sizeof(nodeQ));
    if (tmp != NULL) {

        tmp->vertexNum = vertexNum;
        tmp->Prev = NULL;
        tmp->Next = Q->Head;
        Q->lengthQueue++;
        if (Q->lengthQueue == 1) {
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

int pop(Queue* Q, int* vertexNum) {
    if (Q->lengthQueue > 0) {
        *vertexNum = Q->Last->vertexNum;
        nodeQ* last;
        last = Q->Last;
        Q->lengthQueue--;
        if (Q->lengthQueue > 0) Q->Last = last->Prev;
        free(last);
    } else {
        return 0;
    }
    return 1;
}

//Обход графа с простановкой расстояний

void graphTraversal(int adjMatrix[matrixSize][matrixSize], nodeA* vertexArray, Queue* Q, int startNode) {
    push(Q, startNode);
    vertexArray[startNode].Status = 1;
    vertexArray[startNode].minTraverse = 0;
    int crntVertex;
    int newTraverse;

    while (pop(Q,&crntVertex)) {
        for (int j = 0; j<matrixSize; j++) {
            newTraverse = adjMatrix[crntVertex][j] + vertexArray[crntVertex].minTraverse;
            if (j!=crntVertex & newTraverse < vertexArray[j].minTraverse ) {
                vertexArray[j].minTraverse = newTraverse;
                push(Q,j);
                vertexArray[j].Status = 1;
            } else {
                continue;
            }
        }
    }
}

void getItinerary(int adjMatrix[matrixSize][matrixSize], nodeA* vertexArray, int startNode, int endNode) {
    int curVertex = endNode;
    int newTraverse;
    printf("\n%2d", curVertex);
    while (curVertex != startNode) {
        for (int j=0; j<matrixSize; j++) {
            newTraverse =  vertexArray[curVertex].minTraverse - adjMatrix[curVertex][j];
            if (newTraverse == vertexArray[j].minTraverse ) {
                printf(" <---(%d)--- %d", adjMatrix[curVertex][j], j);
                curVertex = j;
            }
        }
    }
}


int main(void) {

    FILE* file = fopen("/Users/arseniy/Documents/data.txt", "r");

    int temp = 0;

    int adjMatrix[matrixSize][matrixSize];

    Queue Q1;

    Q1.lengthQueue = 0;
    Q1.Last = NULL;
    Q1.Head = NULL;


    //считываем матрицу из файла

    if (file == NULL) {
        printf("File not found!\n");
        return EXIT_FAILURE;
    } else {
        printf("Reading file...\n");
    }
    printf("\nAdjacency matrix is:\n\n");
    for (int i = 0; i<matrixSize; i++) {
        for(int j = 0; j < matrixSize; j++ ) {
            fscanf(file, "%d", &temp);
            if (temp == 0) {
                adjMatrix[i][j] = 99;
                printf("* ");
            } else {
                adjMatrix[i][j] = temp;
                printf("%d ", adjMatrix[i][j]);
            }
        }
        printf("\n");
    };

    //Инициализируем массив, в котором будем хранить информацию о вершинах графа
    nodeA vertexArray[matrixSize];

    for (int i=0; i<matrixSize; i++) {
        vertexArray[i].Status = 0;
        vertexArray[i].minTraverse = 99;
    }

    printf("\n");

    graphTraversal(adjMatrix, vertexArray, &Q1, 4);

    printf("\nResult :\n");



    for (int i=0; i<matrixSize; i++) {
        printf("%2d ",vertexArray[i].minTraverse);
    }

    printf("\n\nItinerary:\n");


    getItinerary(adjMatrix,vertexArray, 4, 8);


    return EXIT_SUCCESS;
}