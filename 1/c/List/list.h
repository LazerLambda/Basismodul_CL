#include "compare.h"
#include "freeElem.h"
#include "stdlib.h"
#include "stdio.h"

#define INT 0
#define CHAR 1
#define CUSTOM 42

#define NOTHING 0
#define RETURN 1

#define PRINT_INT(arg) printf("%s\n", *((int*) arg))

typedef struct maybe {
    int state;
    void* returnValue;
} Maybe;

typedef struct node {
    void* value;
    struct node* next;
    struct node* prev; 
} Node;

typedef struct list {
    struct node* head;
    struct node** sequence;
    size_t size;
    int (*compare)(void* left, void* right);
    void (*freeElem)(void* elem);
    void (*printElem)(void* elem);
} List;

List initList(int type);

void add(void* elem, List* list);

Maybe get(int i, List* list);

int rm(int i, List* list);

void printList(List* list, int type);

void setCompareFunction(int (*compare)(void* left, void* right), List* list);

void setFreeElemFunction(void (*freeElem)(void* elem), List* list);

void freeList(List* list);

