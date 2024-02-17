/*
C17 ДЗ
Сумма цифр равна произведению

Составить логическую функцию, которая определяет, верно ли, что в данном числе сумма цифр равна произведению.

int is_happy_number(int n)

Данные на входе: 	Целое не отрицательное число 
Данные на выходе: 	YES или NO 

Пример №1
Данные на входе: 	123 
Данные на выходе: 	YES 

Пример №2
Данные на входе: 	528 
Данные на выходе: 	NO
*/

#include <stdio.h>

int is_happy_number(int n) {
    int sum = 0, mul = 1;

    while(n > 0) {
        int digit = n % 10;
        n /= 10;
        
        sum += digit;
        mul *= digit;
    }

    return sum == mul;
}

int main() {
    int n;

    puts("Введите число:");
    scanf("%d",  &n);

    is_happy_number(n) ? printf("YES\n") : printf("NO\n");

    return 0;
}