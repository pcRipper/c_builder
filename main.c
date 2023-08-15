#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs\General\Headers\String.h"
#include "libs\Labs\Headers\lab1.h"

int main(int argc,char** argv){

    String* res = toHex(2222);
    
    printf("%s\n", string_get(res));

    return 0;
}