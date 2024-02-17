/*
D11 ДЗ 3
Количество 1
Дано натуральное число N. Посчитать количество «1» в двоичной записи числа. 
Данные на входе: 	Натуральное число 
Данные на выходе: 	Целое число - количество единиц в двоичной записи числа. 

Пример №1
Данные на входе: 	5 
Данные на выходе: 	2 

Пример №2
Данные на входе: 	255 
Данные на выходе: 	8 

*/

#include <stdio.h>

int g_counter = 0;

void get_bin(int n) 
{
    
    if (n > 1)
        get_bin(n / 2);

    g_counter += n % 2;
}


int main() {
    int n;
    scanf("%d", &n);

    get_bin(n);

    printf("%d\n", g_counter);
    
    return 0;
}