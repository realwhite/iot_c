#include <math.h>
#include <stdio.h>
#include "temp_api.h"


void add_record(struct record arr_records[], int n, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minutes, int8_t temp) {
    arr_records[n].year = year;
    arr_records[n].month = month;
    arr_records[n].day = day;
    arr_records[n].hour = hour;
    arr_records[n].minutes = minutes;
    arr_records[n].temperature = temp;
}


void swap_record(struct record* arr_records, int from, int to)
{
    struct record temp = arr_records[to];
    arr_records[to] = arr_records[from];
    arr_records[from] = temp;
};


uint64_t get_record_date_key(struct record* record) {

    return record->year << 16 | record->month << 8 | record->day;
}

void sort_by_date_(struct record* arr_records, size_t size) {
    for (int i=0; i < size; i++) {
        for (int j=i; j < size; j++) {
            if (get_record_date_key(&arr_records[i]) > get_record_date_key(&arr_records[j])) {
                swap_record(arr_records, i, j);
            }
        }
    }
}

void shuffle_records(struct record* arr_records, size_t size) {
    for (int i = 0; i < size; i++) {
        swap_record(arr_records, i, rand() % size);
    }
    
}

void print_record(struct record* record ) {
    printf("%04d-%02d-%04d: %d\n", record->year, record->month, record->day, record->temperature);
}