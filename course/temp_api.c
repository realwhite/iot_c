#include <stdio.h>
#include "temp_api.h"

#define TEMP_UNDEF_VALUE -127
#define MONTH_IN_YEAR 12
#define MAX_DAYS_IN_MONTH 31

void get_max_array_value(int8_t *arr, size_t size, int *idx, int *val)
{
    *val = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > *val)
        {
            *val = arr[i];
            *idx = i;
        }
    }
}

void get_min_array_value(int8_t *arr, size_t size, int *idx, int *val)
{
    *val = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < *val)
        {
            *val = arr[i];
            *idx = i;
        }
    }
}

void get_avg_array_value(int8_t *arr, size_t size, float *val)
{
    if (size == 0)
    {
        *val = 0;
        return;
    }

    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    *val = sum / (float)size;
}

void print_year_statistics(struct record *arr_records, size_t size, int year)
{
    int8_t month_min_temp[MONTH_IN_YEAR] = {[0 ... MONTH_IN_YEAR - 1] = TEMP_UNDEF_VALUE}, month_max_temp[MONTH_IN_YEAR] = {[0 ... MONTH_IN_YEAR - 1] = TEMP_UNDEF_VALUE}, month_avg_temp[MONTH_IN_YEAR]={[0 ... MONTH_IN_YEAR - 1] = TEMP_UNDEF_VALUE};
    int32_t month_temp_sum[MONTH_IN_YEAR] = {0};
    uint32_t month_temp_count[MONTH_IN_YEAR] = {0};

    for (size_t i = 0; i < size; i++)
    {
        if (arr_records[i].year != year)
            continue;

        if ((month_min_temp[arr_records[i].month - 1] == TEMP_UNDEF_VALUE) || (arr_records[i].temperature < month_min_temp[arr_records[i].month - 1]))
            month_min_temp[arr_records[i].month - 1] = arr_records[i].temperature;

        if ((month_max_temp[arr_records[i].month - 1] == TEMP_UNDEF_VALUE) || (arr_records[i].temperature > month_max_temp[arr_records[i].month - 1]))
            month_max_temp[arr_records[i].month - 1] = arr_records[i].temperature;

        month_temp_sum[arr_records[i].month - 1] += arr_records[i].temperature;
        month_temp_count[arr_records[i].month - 1] += 1;
    }

    printf("\nDetailed statistic for %d year\n\n", year);
    puts("Month\t\tmin\tmax\tavg");
    for (int i = 0; i < MONTH_IN_YEAR; i++)
    {
        float avg_temp = TEMP_UNDEF_VALUE;

        if (month_temp_count[i] > 0)
            avg_temp = month_temp_sum[i] / (float)month_temp_count[i];

        month_avg_temp[i] = avg_temp;

        printf("%d-%02d-01\t%d\t%d\t%.2f\n", year, i + 1, month_min_temp[i], month_max_temp[i], avg_temp);
    }

    int min_month, max_month, min_temp, max_temp;
    float avg_temp;

    get_max_array_value(month_max_temp, MONTH_IN_YEAR, &max_month, &max_temp);
    printf("\nMax temp in year was in %d month. Value = %d\n", max_month + 1, max_temp);

    get_min_array_value(month_min_temp, MONTH_IN_YEAR, &min_month, &min_temp);
    printf("Min temp in year was in %d month. Value = %d\n", min_month + 1, min_temp);

    get_avg_array_value(month_avg_temp, MONTH_IN_YEAR, &avg_temp);
    printf("Avg temp in year was %.2f\n\n", avg_temp);
}

uint8_t is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void print_month_statistics(struct record *arr_records, size_t size, int year, int month)
{

    const uint8_t days_in_month[MONTH_IN_YEAR] = {31, is_leap_year(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int8_t day_min_temp[MAX_DAYS_IN_MONTH] = {[0 ... MAX_DAYS_IN_MONTH - 1] = TEMP_UNDEF_VALUE}, day_max_temp[MAX_DAYS_IN_MONTH] = {[0 ... MAX_DAYS_IN_MONTH - 1] = TEMP_UNDEF_VALUE}, day_avg_temp[MAX_DAYS_IN_MONTH] = {[0 ... MAX_DAYS_IN_MONTH - 1] = TEMP_UNDEF_VALUE};
    int32_t day_temp_sum[MAX_DAYS_IN_MONTH] = {0};
    uint32_t day_temp_count[MAX_DAYS_IN_MONTH] = {0};
    uint32_t records_found = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr_records[i].year != year || arr_records[i].month != month)
            continue;

        records_found += 1;

        if ((day_min_temp[arr_records[i].day - 1] == TEMP_UNDEF_VALUE) || (arr_records[i].temperature < day_min_temp[arr_records[i].day - 1]))
            day_min_temp[arr_records[i].day - 1] = arr_records[i].temperature;

        if ((day_max_temp[arr_records[i].day - 1] == TEMP_UNDEF_VALUE) || (arr_records[i].temperature > day_max_temp[arr_records[i].day - 1]))
            day_max_temp[arr_records[i].day - 1] = arr_records[i].temperature;

        day_temp_sum[arr_records[i].day - 1] += arr_records[i].temperature;
        day_temp_count[arr_records[i].day - 1] += 1;
    }

    printf("Detailed statistic for %d-%02d-01 month\n\n", year, month);
    printf("Found %d records\n\n", records_found);
    puts("Day\t\tmin\tmax\tavg");

    for (uint8_t i = 0; i < days_in_month[month - 1]; i++)
    {
        float avg_temp = TEMP_UNDEF_VALUE;

        if (day_temp_count[i] > 0)
            avg_temp = day_temp_sum[i] / (float)day_temp_count[i];

        day_avg_temp[i] = avg_temp;

        printf("%d-%02d-%02d\t%d\t%d\t%.2f\n", year, month, i + 1, day_min_temp[i], day_max_temp[i], avg_temp);
    }

    int min_day, max_day, min_temp, max_temp;
    float avg_temp;

    get_max_array_value(day_max_temp, days_in_month[month - 1], &max_day, &max_temp);
    printf("\nMax temp in month %d-%02d-%02d was %d\n", year, month, max_day + 1, max_temp);

    get_min_array_value(day_min_temp, days_in_month[month - 1], &min_day, &min_temp);
    printf("Min temp in month %d-%02d-%02d was %d\n", year, month, max_day + 1, min_temp);

    get_avg_array_value(day_avg_temp, days_in_month[month - 1], &avg_temp);
    printf("Avg temp in month was %.2f\n\n", avg_temp);

}