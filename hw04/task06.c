#include <stdio.h>

/*
Ввести два числа. Если первое число больше второго, то программа печатает слово Above. 
Если первое число меньше второго, то программа печатает слово Less. 
А если числа равны, программа напечатает сообщение Equal.

Данные на входе:	Два целых числа
Данные на выходе:	Одно единственное слово: Above, Less, Equal

Пример №1    
Данные на входе:	24 24
Данные на выходе:	Equal

Пример №2    
Данные на входе:    100 0
Данные на выходе:   Above

*/

int main() {
    int a, b;

    printf("Введите два числа:\n");
    scanf("%d %d", &a, &b);

    if (a > b) 
        printf("Above\n");
    else if (a < b) 
        printf("Less\n");
    else 
        printf("Equal\n");

    return 0;
}