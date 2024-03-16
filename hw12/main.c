#include <stdio.h>
#include <unistd.h>
#include "temp_api.h"
#include "report.h"

void print_help()
{
    puts(
        "Программа для анализа архивных метеоднных\n"
        "Описание CLI опций:\n"
        "\t -h\t вывод этого сообщения\n"
        "\t -f <filename>\t путь до файла данных\n"
        "\t -m <dd>\t номер месяца для анализа. возможные значения 1 - 12\n"
        "\nПримеры:\n"
        "\t app -f some_data.csv получение статистики за год\n"
        "\t app -f some_data.csv -m 1 получение статистики только за январь\n");
}

int main(int argc, char *argv[])
{

    char c;
    char *filename = NULL;
    uint8_t month;

    struct record records[365];
    

    while ((c = getopt(argc, argv, "hf:m:")) != -1)
    {
        switch (c)
        {
        case 'h':
            print_help();
            return 0;

        case 'f':
            filename = optarg;
            break;

        case 'm':
            month = atoi(optarg);
            if (month < 1 || month > 12)
            {
                puts("-m: month must be >= 1 and <= 12");
                return 1;
            }
            break;

        default:
            return 1;
            break;
        }
    }

    if (filename == NULL) {
        puts("-f: filename is required!");
        return 1;
    }
    
    // заполняем массив произвольными данными
    uint8_t _month = 1, _day = 1;
    for (int i = 0; i < 365; i ++) {
        add_record(records, i, 2024, _month, _day, rand() % 24, rand() % 60, rand() % 10);
        
        _day += 1;
    
        if (_day == 31){
            _month += 1;
            _day = 1;
        }
        
    }

    // проверяем работу сортировки
    // после заполнения массива, он уже отсортирован по дате
    // перемешиваем массив, сортируем и смотрим что сортировка произошла
    // print_record(&records[10]);
    // shuffle_records(records, 365);
    // print_record(&records[10]);
    // sort_by_date(records, 365);
    // print_record(&records[10]);

    printf("year avg temp = %d\n",get_year_avg_temp(records, 365, 2024));
    printf("year max temp = %d\n",get_year_max_temp(records, 365, 2024));
    printf("year min temp = %d\n",get_year_min_temp(records, 365, 2024));

    if (month > 0) {
        printf("month avg temp = %d\n",get_month_avg_temp(records, 365, 2024, month));
        printf("month max temp = %d\n",get_month_max_temp(records, 365, 2024, month));
        printf("month min temp = %d\n",get_month_min_temp(records, 365, 2024, month));

    }

    return 0;
}