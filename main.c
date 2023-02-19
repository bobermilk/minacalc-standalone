#include <stdio.h>
#include <stdlib.h>
#include "API.h"

int main(int argc, char* argv[]) {
    calc_file(argv[1], strtof(argv[2], NULL), strtof(argv[3], NULL));
}