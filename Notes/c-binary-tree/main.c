#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Реализуем двоичное дерево поска

typedef char T[1000];

struct TNode {
    int key;
    unsigned char height;
    struct TNode *left;
    struct TNode *right;
    struct TNode *parent;
    T data;
};

typedef struct TNode Node;

// Балансировка дерева

// Функция возвращающая высоту дерева
unsigned char height(Node* p)
{
    return p?p->height:0;
}

// Вычисление balance factor
int bfactor(Node* p)
{
    return height(p->right)-height(p->left);
}
// Восстановление правильной высоты узла
void fixheight(Node* p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = ( hl>hr ? hl:hr ) + 1;
}

Node* rotateRight(Node *p) // правый поворот вокруг p
{
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

Node* rotateLeft(Node *q) // левый поворот вокруг q
{
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

Node* balance(Node* p) // балансировка узла p
{
    fixheight(p);
    if( bfactor(p)==2 )
    {
        if( bfactor(p->right) < 0 )
            p->right = rotateRight(p->right);
        return rotateLeft(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0  )
            p->left = rotateLeft(p->left);
        return rotateRight(p);
    }
    return p; // балансировка не нужна
}


// Создание нового узла
Node* getFreeNode(Node *parent, int key, T value)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->parent = parent;
    tmp->key = key;
    stpcpy(tmp->data, value);
    return tmp;
}

//Вставка с балансировкой

Node* insert(Node* p, int key, T value) // вставка ключа k в дерево или поддерево с корнем p
{
    if( p == NULL ) {
        return getFreeNode(NULL, key, value);
    }
    if (key == p->key) {
        printf("Error: key %d already exists! \n", key);
        return p;
    }
    if( key < p->key )
        p->left  = insert(p->left , key, value);
    else
        p->right = insert(p->right, key, value);
    return balance(p);
}

//Поиск элементов
Node* findElement(int key, Node* root)
{
    if (root) {
        if (root->key == key) {return root;}
        else if ( key > root->key) {return findElement(key, root->right);}
        else if ( key < root->key ) {return findElement(key, root->left);}
        else {printf("Something went wrong.."); exit(EXIT_FAILURE);}
    }
    printf("Element didn't found!\n");
    return NULL;
}

Node* findMin(Node* p) // поиск узла с минимальным ключом в дереве p
{
    return p->left?findMin(p->left):p;
}

Node* findMax(Node* p) // поиск узла с минимальным ключом в дереве p
{
    return p->right?findMax(p->right):p;
}

//Удаление элемента с балансировкой


Node* removeMin(Node* p) // удаление узла с минимальным ключом из дерева p
{
    if( p->left==0 )
        return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}

Node* removeNode (Node* p, int k) // удаление ключа k из дерева p
{
    if( !p ) return 0;
    if( k < p->key )
        p->left = removeNode(p->left,k);
    else if( k > p->key )
        p->right = removeNode(p->right,k);
    else //  k == p->key
    {
        Node* q = p->left;
        Node* r = p->right;
        free(p);
        if( !r ) return q;
        Node* min = findMin(r);
        min->right = removeMin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

// Распечатка двоичного дерева в виде скобочной записи
void printTree(Node *root) {
    if (root)
    {
        printf("%d-%s", root->key, root->data);
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

//Вывод дерева в диапазоне значения ключей

void inOrderTravers(Node* root, int minKey, int maxKey ) {
    if (root) {
        if (minKey < maxKey) {
            inOrderTravers(root->left, minKey, maxKey);
            if (root->key >= minKey && root->key <= maxKey) {printf("%s ", root->data);}
            inOrderTravers(root->right, minKey, maxKey);
        } else {
            inOrderTravers(root->right, minKey, maxKey);
            if (root->key >= maxKey && root->key <= minKey) {printf("%s ", root->data);}
            inOrderTravers(root->left, minKey, maxKey);
        }
    }
}

void printMinMax(Node* root) {
    Node* min = findMin(root);
    Node* max = findMax(root);
    printf("Minimal key is %d, maximal key is %d", min->key, max->key);
}

int main (void) {

    Node *Tree = NULL;

    FILE* file = fopen("./tree_data.txt", "r");

    if (file == NULL) {
        printf("File not found!\n");
        return EXIT_FAILURE;
    } else {
        printf("Reading file...\n");
    }

    T value;
    int key;

    while (fscanf(file, "%d %s", &key, value) > 0) {
        printf("%d %s\n", key, value);
        Tree = insert(Tree, key, value);
    }

    fclose(file);

    printf("\nTree:\n");
    printTree(Tree);
    printf("\n");
    printf("\nPrinting tree in ascending keys order:\n");
    inOrderTravers(Tree, 0, 12);
    printf("\nPrinting tree in descending keys order:\n");
    inOrderTravers(Tree, 12, 0);

    Node *p = NULL;

    printf("\n\nFinding element:");
    p = findElement(0, Tree);
    printf("\nKey: %d, Node: %p, value: %s", p->key, p, p == NULL ? 0:p->data);
    p = findElement(12, Tree);
    printf("\nKey: %d, Node: %p, value: %s", p->key, p, p == NULL ? 0:p->data);


    printf("\n\nRemoving element:\n");
    removeNode(Tree, 12);
    removeNode(Tree, 0);

    inOrderTravers(Tree,0,100);

    printf("\n\nFind min and max keys:\n");
    printMinMax(Tree);


    return EXIT_SUCCESS;
}
