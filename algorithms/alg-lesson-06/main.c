//
// Created by Арсений Сысоев on 2019-03-17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Реализуем простую хэш функцию

int myHash(char *arg) {
    int len = strlen(arg);
    int buf1 = 1000;
    int buf2 = 1;
    for (int i = 0; i < len; i+=2) {
        buf1 = buf1 + arg[i] +  arg[i]*(arg[i]%9);
    }
    for (int i = 1; i < len; i+=2) {
        buf2 = buf2 + arg[i]*(arg[i]%7);
    }
    return buf1 - buf2;
}

//Реализуем двоичное дерево поска

typedef int T;

typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;


// Распечатка двоичного дерева в виде скобочной записи
void printTree(Node *root) {
    if (root)
    {
        printf("%d",root->data);
        if (root->left || root->right)
        {
            printf("(");

            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");

            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

// Создание нового узла
Node* getFreeNode(T value, Node *parent) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

// Вставка узла
void insert(Node **head, int value) {
    Node *tmp = NULL;
    if (*head == NULL)
    {
        *head = getFreeNode(value, NULL);
        return;
    }

    tmp = *head;
    while (tmp)
    {
        if (value > tmp->data)
        {
            if (tmp->right)
            {
                tmp = tmp->right;
                continue;
            }
            else
            {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        }
        else if (value< tmp->data)
        {
            if (tmp->left)
            {
                tmp = tmp->left;
                continue;
            }
            else
            {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        }
        else
        {
            exit(2);                     // Дерево построено неправильно
        }
    }
}

void preOrderTravers(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

//Реализуем in-order обход дерева

void inOrderTravers(Node* root) {
    if (root) {
        inOrderTravers(root->left);
        printf("%d ", root->data);
        inOrderTravers(root->right);
    }
}

//Реализуем post-order обход дерева

void postOrderTravers(Node* root) {
    if (root) {
        postOrderTravers(root->right);
        printf("%d ", root->data);
        postOrderTravers(root->left);
    }

}

//Поиск в двоичном дереве поиска
//Будем возвращать указатель на первое вхождение заданного элемента

Node* findElement(int value, Node* root) {
    if (root) {
        if (root->data == value) {return root;}
        else if ( value > root->data) {return findElement(value, root->right);}
        else if ( value < root->data) {return findElement(value, root->left);}
        else {printf("Something went wrong.."); exit(2);}
    }
    return NULL;
}

int main (void) {

    printf("Result: %d\n", myHash("a"));
    printf("Result: %d\n", myHash("b"));
    printf("Result: %d\n", myHash("c"));
    printf("Result: %d\n", myHash("d"));
    printf("Result: %d\n", myHash("e"));
    printf("\n");
    printf("Result: %d\n", myHash("aaaaa"));
    printf("Result: %d\n", myHash("aaaab"));
    printf("Result: %d\n", myHash("aaaad"));
    printf("Result: %d\n", myHash("aaaae"));
    printf("\n");
    printf("Result: %d\n", myHash("Hello, World!"));

    Node *Tree = NULL;

    FILE* file = fopen("/Users/arseniy/Documents/data_for_tree.txt", "r");

    //File: 10 5 7 6 8 4 9 3 10 2 1

    printf("\nReading file..\n");
    if (file == NULL)
    {
        puts("Can't open file!");
        exit(1);
    }
    int count;
    fscanf(file, "%d", &count);       //Считываем количество записей

    for(int i = 0; i < count; i++) {
        int value;
        fscanf(file, "%d", &value);
        insert(&Tree, value);
    }
    fclose(file);
    printTree(Tree);
    printf("\n PreOrderTravers: ");
    preOrderTravers(Tree);
    printf("\n  inOrderTravers: ");
    inOrderTravers(Tree);
    printf("\nPostOrderTravers: ");
    postOrderTravers(Tree);

    Node *p = NULL;

    printf("\n Finding element:");
    p = findElement(3, Tree);

    printf("\nNode: %p, value: %d", p, p == NULL ? 0:p->data);

    return EXIT_SUCCESS;
}
