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

int8_t get_month_avg_temp(struct record *, size_t, uint16_t year, uint8_t month);
int8_t get_month_min_temp(struct record *, size_t, uint16_t year, uint8_t month);
int8_t get_month_max_temp(struct record *, size_t, uint16_t year, uint8_t month);
int8_t get_year_avg_temp(struct record *, size_t, uint16_t year);
int8_t get_year_min_temp(struct record *, size_t, uint16_t year);
int8_t get_year_max_temp(struct record *, size_t, uint16_t year);
#endif