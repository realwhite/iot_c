#include "temp_api.h"

#define UNDEF_VALUE -128

int8_t get_month_avg_temp(struct record *records, size_t size, uint8_t year, uint8_t month)
{
    int count = 0, sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (records[i].year == year && records[i].month == month)
        {
            sum += records[i].temperature;
            count += 1;
        }
    }

    if (count > 0)
    {
        return sum / count;
    }

    return UNDEF_VALUE;
}

int8_t get_month_min_temp(struct record *records, size_t size, uint8_t year, uint8_t month)
{
    int8_t min = UNDEF_VALUE;

    for (int i = 0; i < size; i++)
    {
        if (records[i].year == year && records[i].month == month)
        {
            if (min == UNDEF_VALUE)
            {
                min = records[i].temperature;
                continue;
            }

            if (records[i].temperature < min)
            {
                min = records[i].temperature;
            }
        }
    }

    return min;
}

int8_t get_month_max_temp(struct record *records, size_t size, uint8_t year, uint8_t month)
{
    int8_t max = UNDEF_VALUE;

    for (int i = 0; i < size; i++)
    {
        if (records[i].year == year && records[i].month == month)
        {
            if (max == UNDEF_VALUE)
            {
                max = records[i].temperature;
                continue;
            }

            if (records[i].temperature > max)
            {
                max = records[i].temperature;
            }
        }
    }

    return max;
}

int8_t get_year_avg_temp(struct record *records, size_t size, uint8_t year)
{

    int sum = 0, count = 0;
    for (int i = 0; i < size; i++)
    {
        if (records[i].year == year)
        {
            sum += records[i].year;
            count += 1;
        }
    }

    if (count > 0)
    {
        return sum / count;
    }

    return UNDEF_VALUE;
}

int8_t get_year_min_temp(struct record *records, size_t size, uint8_t year)
{
    int min = UNDEF_VALUE;

    for (int i = 0; i < size; i++)
    {
        if (records[i].year == year)
        {
            if (min == UNDEF_VALUE)
            {
                min = records[i].temperature;
                continue;
            }

            if (records[i].temperature < min)
            {
                min = records[i].temperature;
            }
        }
    }

    return min;
}

int8_t get_year_max_temp(struct record *records, size_t size, uint8_t year)
{
    int max = UNDEF_VALUE;

    for (int i = 0; i < size; i++)
    {
        if (records[i].year == year)
        {
            if (max == UNDEF_VALUE)
            {
                max = records[i].temperature;
                continue;
            }

            if (records[i].temperature > max)
            {
                max = records[i].temperature;
            }
        }
    }

    return max;
}