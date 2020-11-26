#define T 1
#define F 0

// TODO
// typedef struct node {
//     int q;
//     int isAccepting;
//     struct node* qNext; 
// } Node;

// typedef struct graph {
//     Node* start;    
// } Graph;

typedef struct delta {
    int q_from;
    char label;
    int q_to;
} Delta;

typedef struct transitions {
    int size;
    struct delta* deltas;
} Transition;

typedef struct dea {
    char* sigma;
    int* q;
    int* f;
    int s;
    Transition transitions;
    // TODO
    // Graph* graph;
} DEA;




DEA* initAutomaton();

Transition initDeltas(int* q_froms, char* labels, int* q_tos, int length);

int transition(DEA* dea, int qFrom, char label);

int accepts(DEA* dea, char* word, int wordLength, int accptStLength);

void freeAutomaton(DEA* automaton);

void printAutomaton(DEA* automaton);