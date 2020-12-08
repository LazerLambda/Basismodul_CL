int compareInt(void* left, void* right) {
    // printf("%d < %d\n", *((int*) left), *((int*) right));
    return(*((int*) left) <= *((int*) right));
}

int compareChar(void* left, void* right) {
    return(*((char*) left) < *((char*) right));
}