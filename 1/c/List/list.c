#include "list.h"

List initList(int type){

    List list = {
        .head = NULL,
        .size = 0,
        .compare = NULL
        };
    
    switch (type)
    {
    case INT:
        list.compare = compareInt;
        list.freeElem = freeElemInt;
        break;
    case CHAR:
        list.compare = compareChar;
        list.freeElem = freeElemChar;
        break;
    default:
        printf("Wrong type specified!");
        exit(-1);
        break;
    }

    return(list);
}

void add(void* elem, List* list) {

    Node* new = malloc(sizeof(Node));
    new->value = elem;
    new->next = NULL;
    new->prev = NULL;

    if(list->head == NULL){
        list->head = new;
        // list->sequence = (struct node*) malloc(sizeof(struct node*));
        // list->sequence[0] = &new;
        list->size++;
        return;
    } else {
        Node* curr = list->head;

        while(curr->next != NULL){
            // if elem is smaller of equal       
            if(list->compare(elem, curr->value)){
                // if we are dealing with head element
                if(curr->prev == NULL){
                    new->next = curr;
                    curr->prev = new;
                    list->head = new;  
                } else {
                    curr->prev->next = new;
                    new->next = curr;
                    new->prev = curr->prev;
                    curr->prev = new;
                }
                // list->sequence = (Node*) realloc(sizeof(Node*), (list->size + 1) * sizeof(struct node*));
                // list->sequence[list->size] = &new;
                list->size++;
                return;
            }
            curr = curr->next;
        }
        // Handling last element
        if(list->compare(elem, curr->value)){
            // special case of list size of 2
            // head case
            if(curr->prev != NULL){
                curr->prev->next = new;
            } else {
                list->head = new;
            }
            new->prev = curr->prev;
            new->next = curr;
            curr->next = NULL;
            curr->prev = new;
            
        } else {
            new->prev = curr;
            curr->next = new;
        }
        // list->sequence = (Node*) realloc(sizeof(Node*), (list->size + 1) * sizeof(struct node*));
        // list->sequence[list->size] = &new;
        list->size++;
        return;
    }
}

void printList(List* list, int type){
    printf("List has %d elments:\n", (int) list->size);
    Node* curr = list->head;

    while(curr != NULL) {
        switch (type)
        {
        case INT:
            printf("%d\n", *((int*) curr->value));
            break;
        
        default:
            break;
        }
        curr = curr->next;
    }
}



void freeList(List* list){
    Node* curr = list->head;

    
    while(curr != NULL){
        Node* toRm = curr;
        // printf("Hier %d\n", *((int*) curr->value));
        curr = curr->next;
        list->freeElem(toRm->value);
        // free(list->sequence);
    }
}



