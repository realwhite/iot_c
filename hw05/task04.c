/*
B6 Урок 5 Практика №2
Две одинаковые цифры рядом
Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, стоящие рядом. 

Данные на входе:	Одно целое число 
Данные на выходе:	Единственное слов: YES или NO 

Пример №1
Данные на входе:	1232 
Данные на выходе:	NO 

Пример №2
Данные на входе:	1224 
Данные на выходе:	YES 
*/

#include <stdio.h>

int main() {
    int a, last_digit=0, current_digit;
    char first_run = 1, is_have_duplicate = 0;

    printf("Введите целое число:\n");
    scanf("%d", &a);



    while (a > 0) {
        current_digit = a % 10;
        a /= 10; 
        
        if (first_run == 1) {
            first_run = 0;
            last_digit = current_digit;
            continue;
        }

        if (last_digit == current_digit) {
            is_have_duplicate = 1;
            break;
        }
        
        last_digit = current_digit;
    } 

    if (is_have_duplicate == 1){
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}