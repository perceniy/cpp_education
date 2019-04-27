#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

typedef struct Item
{
    char info;
    struct Item* next;
} Item;

Item* createList(const char* str) {
    Item head = { '*', NULL };
    Item* last = &head;
    while (*str != '\0') {
        last->next = (Item*)malloc(sizeof(Item));
        last = last->next;
        last->info = *str++;
        last->next = NULL;
    }
    return head.next;
}

void putList(char* msg, Item* ptr) {
    printf("%s:\"", msg);
    for (; ptr != NULL; ptr = ptr->next)
        printf("%c", ptr->info);
    printf("\"\n");
}

Item* deleteList(Item* ptr) {
    Item* tmp = NULL;
    while (ptr != NULL) {
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
    return ptr;
}

int main()
{
    char buf[80];
    Item* st;
    int n;
    do {
        n = scanf("%80[^\n]", buf);;
    } while (n > 0);

}