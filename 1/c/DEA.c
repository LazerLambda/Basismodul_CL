#include "stdlib.h"
#include "stdio.h"

#include "DEA.h"



/**
 * transition function
 * returns -1 if there is no such transition found
 * returns the integer value of the child state if 
 * the transition is found
 */
int transition(DEA* dea, int qFrom, char label) {
    Transition* ts = &dea->transitions;
    int retVal = -1;

    for(int i = 0; i < ts->size; i++) {
        if(ts->deltas[i].label == label && ts->deltas[i].q_from == qFrom){
            retVal = ts->deltas[i].q_to;
            break;
        }
    }
    return(retVal);
}

/**
 * accepts function
 * returns 1 for acceptance and 0 for non-acceptance
 */
int accepts(DEA* dea, char* word, int wordLength, int accptStLength) {
    int currentState = dea->s;

    // walk through the automaton
    for (int i = 0; i < wordLength; i++) {
        int ts = transition(dea, currentState, word[i]);
        if (ts != -1) {
            currentState = ts;
        } else {
            return(F);
        }
    }

    // Check for accepting state
    for (int i = 0; i < accptStLength; i++){
        if (dea->f[i] == currentState) {
            return(T);
        }
    }
    return(F);
}

DEA* initAutomaton(char* sigma,int* q, int* f, int s, Transition delta) {
    struct dea* automaton = malloc(sizeof(DEA));
    automaton->sigma = sigma;
    automaton->q = q;
    automaton->f = f;
    automaton->s = s;
    automaton->transitions = delta;

    return(automaton);
}

Transition initDeltas(int* q_froms, char* labels, int* q_tos, int length) {

    // creating transitions
    Delta* delta = malloc(length * sizeof(Delta));
    for(int i = 0; i < length; i++) {
        delta[i].q_from = q_froms[i];
        delta[i].label = labels[i];
        delta[i].q_to = q_tos[i];
    }
    Transition transition = {.size = length, .deltas = delta}; 
    return(transition);
}

void freeAutomaton(DEA* automaton) {
    free(automaton->transitions.deltas);
    free(automaton);
}

void printAutomaton(DEA* automaton) {
    Delta* delta = automaton->transitions.deltas;
    int size = automaton->transitions.size;

    for(int i = 0; i < size; i++) {
        printf("(%d, %s, %d)\n", 
            delta[i].q_from,
            &delta[i].label,
            delta[i].q_to);
    }
}




