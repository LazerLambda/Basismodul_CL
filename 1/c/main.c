#include "assert.h"
#include "stdlib.h"

#include "DEA.h"


struct dea* createTest() {
    size_t length = 5;

    int q[5] = {0,1,2,3,4};
    int f[1] = {4};

    int q_from[5] = {0,1,1,2,3};
    int q_to[5] = {1,2,3,4,4};

    char label_[5];

    label_[0] = 'c';
    label_[1] = 'd';
    label_[2] = 'c';
    label_[3] = 'd';
    label_[4] = 'c';

    struct transitions delta = initDeltas(q_from, label_, q_to, length);
    DEA* automaton = initAutomaton("cd", q, f, q[0], delta);
    return(automaton);
}


int main(void) {

    
    DEA* automaton = createTest();

    // Display transitions
    printAutomaton(automaton);

    // Test 
    assert(transition(automaton, 0, 'c') != -1);
    assert(transition(automaton, 3, 'c') != -1);
    assert(transition(automaton, 0, 'd') == -1);

    assert(accepts(automaton, "cdd", 3, 1) == T);
    assert(accepts(automaton, "ddd", 3, 1) == F);
    assert(accepts(automaton, "ccc", 3, 1) == T);
    assert(accepts(automaton, "cccccc", 6, 1) == F);

    // free automaton
    freeAutomaton(automaton);
}