/*
F19 ДЗ 6 
Больше среднего
Написать функцию и программу, демонстрирующую работу данной функции.
Определить количество положительных элементов квадратной матрицы, превышающих по величине среднее арифметическое всех элементов главной диагонали. 
Реализовать функцию среднее арифметическое главной диагонали. 

Данные на входе: 	5 строк по 5 целых чисел через пробел 
Данные на выходе: 	Одно целое число 

Пример
Данные на входе: 	1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5 
Данные на выходе: 	10 

*/

#include <stdio.h>


float matrix_diag_avg(int m, int n, int arr[]) {
    int sum = 0;
    for (int im = 0; im < m; im++) {
        for (int in = 0; in < n; in ++) {
            if (im == in){
                int idx = im * m + in;
                sum += arr[idx];
            }
        }
    }

    return (float)sum / m;
}

void input_matrix(int count, int matrix[]) {
    for (int i = 0; i < count; i ++) {
        scanf("%d", &matrix[i]);
    }
}

int main() {
    int matrix [5 * 5] = {0};

    input_matrix(5 * 5, matrix);

    int avg, count = 0;
    avg = matrix_diag_avg(5, 5, matrix);

    for (int i = 0; i < sizeof(matrix)/ sizeof(int); i++) {
        if (matrix[i] > avg)
            count += 1;
    }

    printf("%d\n", count);

    return 0;
}