#include "../Headers/Functions.h"

void cleanSTDIN(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}