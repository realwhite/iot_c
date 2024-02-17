/*
E7 Практик 2
Инверсия половинок
Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива. 
Необходимо изменить считанный массив и напечатать его одним циклом. 

Данные на входе: 	10 целых элементов массива через пробел. 
Данные на выходе: 	10 целых элементов массива через пробел. 

Пример №1
Данные на входе: 	4 -5 3 10 -4 -6 8 -10 1 0 
Данные на выходе: 	-4 10 3 -5 4 0 1 -10 8 -6 

Пример №2
Данные на входе: 	1 2 3 4 5 6 7 8 9 10 
Данные на выходе: 	5 4 3 2 1 10 9 8 7 6 
*/

#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10


void swap(int *arr, int from_idx, int to_idx) {
    if (from_idx == to_idx) {
        return;
    }
    int tmp = arr[from_idx];
    arr[from_idx] = arr[to_idx];
    arr[to_idx] = tmp;
}


int main() {

    int arr[ARR_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8,9,10};
    int mid = ARR_SIZE / 2;

    for (int i = 0; i < ARR_SIZE; i++)  {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < ARR_SIZE / 4; i++) {
        swap(arr, i, mid - 1 - i );
    }
    for(int i = 0; i < ARR_SIZE / 4; i++) {
        swap(arr, i + mid, ARR_SIZE - i - 1);
    }

    puts("\n");

    for (int i = 0; i < ARR_SIZE; i++)  {
        printf("%d ", arr[i]);
    }

    puts("\n");

    return 0;
}