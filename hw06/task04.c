/*
C9 Практ 2
Факториал
Составить функцию вычисления N!. Использовать ее при вычислении факториала
int factorial(int n)

Данные на входе: 	Целое положительное число не больше 20 
Данные на выходе: 	Целое положительное число 

Пример №1
Данные на входе: 	5 
Данные на выходе: 	120
*/

#include <stdio.h>

u_int64_t factorial(int n) {
    u_int64_t result = 1;

    for(int i = 1; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

int main() {
    int n;

    printf("Целое положительное число не больше 20:\n");
    scanf("%d", &n);

    printf("%llu\n", factorial(n));

    return 0;
}