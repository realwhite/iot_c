#include "temp_api.h"

void add_record(struct record arr_records[], int n, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minutes, int8_t temp);
void swap_record(struct record* arr_records, int from, int to);
uint64_t get_record_date_key(struct record* record);
void sort_by_date(struct record* arr_records, size_t size);
void shuffle_records(struct record* arr_records, size_t size);
void print_record(struct record* record);