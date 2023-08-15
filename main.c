#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs\General\Headers\String.h"
#include "libs\Labs\Headers\lab1.h"


int main(int argc,char** argv){

    printf("%s",string_get(string_init(toHex(212))));
    
    return 0;
}