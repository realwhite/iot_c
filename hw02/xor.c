#include <stdio.h>

int main() {

    printf(
        "--------------------------------------------------------------------------- \n"
        "                  A ^ B == (!A && B) || (A && !B)                           \n"
        "____________________________________________________________________________\n"
        "| A | B | !A | !B | (!A && B) | (A && !B) | (!A && B) || (A && !B) | A ^ B |\n"
        "|--------------------------------------------------------------------------|\n"
        "| 0 | 0 |  1 |  1 |      0    |     0     |           0            |   0   |\n"
        "| 0 | 1 |  1 |  0 |      1    |     0     |           1            |   1   |\n"
        "| 1 | 0 |  0 |  1 |      0    |     1     |           1            |   1   |\n"
        "| 1 | 1 |  0 |  0 |      0    |     0     |           0            |   0   |\n"
        "----------------------------------------------------------------------------\n\n"
    );
    
    return 0;
}