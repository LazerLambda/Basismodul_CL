#include "assert.h"
#include "list.h"
#include "stdlib.h"
#include "time.h"

typedef struct randArr {
    void* arr;
    int size;
} TestArr;

TestArr randomIntArr(){

    srand(time(NULL));
    int size = rand() % 100;
    int* arr = (int*) malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
    
    TestArr ret = {.arr = (void*) arr, .size = size};
    printf("Created Array of size %d\n", size);
    return(ret);
}

int main(void){

    int TEST_AMOUNT = 100000;

    for(int i = 0; i < TEST_AMOUNT; i++) {
            List testList = initList(INT);
    TestArr test0 = randomIntArr();
    int* testArr0 = (int*) test0.arr;
    
    for(int i = 0; i < test0.size; i++){
        // printf("%d\n", testArr0[i]);
        add(&testArr0[i], &testList);
    }
    printList(&testList, INT);
    // Check for correct value
    // assert(*((int*) get(3, &testList).returnValue) == testArr0[3]);

    // Test for correct out of bounce behavior
    // assert(get((int) test0.size, &testList).state == NOTHING);

    //assert(rm(0, &testList) == 1);
    //assert(*((int*) get(0, &testList).returnValue) == testArr0[1]);

    // sort(&testList);

    // free List
    freeList(&testList);


    // free test arrays
    free(test0.arr);
    }
}