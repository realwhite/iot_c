#ifndef TEMP_API_H
#define TEMP_API_H
#include <stdlib.h>

struct record
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minutes;
    int8_t temperature;
};

void print_month_statistics(struct record* arr_records, size_t size, int year, int month);
void print_year_statistics(struct record* arr_records, size_t size, int year);
#endif