#include <stdio.h>

/*
Ввести три числа и найти наибольшее из них

Данные на входе:	Три целых числа через пробел
Данные на выходе: 	Одно наибольшее целое число
    
Пример
Данные на входе:	4 15 9
Данные на выходе:  	15
*/

int main() {

    int a, b, c, max;

    printf("Введите 3 числа:\n");
    scanf("%d %d %d", &a, &b, &c);

    max = a > b ? a : b;
    max = max > c ? max : c;

    printf("%d\n", max);


    return 0;
}