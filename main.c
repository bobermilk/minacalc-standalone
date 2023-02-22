#include <stdio.h>
#include <stdlib.h>
#include "API.h"

int main(int argc, char* argv[]) {
    if(argc==1){
        printf("%d", calc_version());
    } else {
        calc_file(argv[1], strtof(argv[2], NULL), strtof(argv[3], NULL));
    }
}