#include "../Headers/VectorFunctions.h"

//Fill functions
int randomFill(size_t index){
    static const int FROM = 0;
    static const int TO = 100;
    return rand() % (TO - FROM) + FROM;
}

//Output functions
void intOutput(int x,size_t index){
    printf("%d",x);
}

void charOutput(char x,size_t index){
    printf("%c",x);
}

//Input functions
int intInput(size_t index){
    int result;
    scanf("%d",&result);
    return result;
}

//Equal predicates
bool intEqual(int l,int r){
    return l == r;
}