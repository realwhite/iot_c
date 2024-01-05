#include <stdio.h>

/*
Напечатать сумму максимума и минимума.

Данные на входе:	 Пять целых чисел через пробел
Данные на выходе:    Одно целое число - сумма максимума и минимума

Пример    
Данные на входе:      4    15    9    56    4
Данные на выходе:     60
*/

int main() {

    int a, b, c, d, e, min, max;

    printf("Введите пять целых чисел:\n");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    min = a < b ? a : b;
    min = min < c ? min : c;
    min = min < d ? min : d;
    min = min < e ? min : e;

    max = a > b ? a : b;
    max = max > c ? max : c;
    max = max > d ? max : d;
    max = max > e ? max : e; 

    printf("%d %d\n", min, max);
    printf("%d\n", min + max);

    return 0;
}