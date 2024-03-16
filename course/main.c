#include <stdio.h>
#include <unistd.h>
#include "temp_api.h"

#define RECORDS_COUNT 600000

#define RED "\x1b[31m" 
#define RESET "\x1b[0m" 

void print_help()
{
    puts(
        "Программа для анализа архивных метеоднных\n"
        "Описание CLI опций:\n"
        "\t -h\t вывод этого сообщения\n"
        "\t -f <filename>\t путь до файла данных\n"
        "\t -y <yyyy> год для анализа\n"
        "\t -m <dd>\t номер месяца для анализа. возможные значения 1 - 12\n"
        "\nПримеры:\n"
        "\t app -f some_data.csv -y 2021 получение статистики за год\n"
        "\t app -f some_data.csv -y 2021 -m 1 получение статистики только за январь\n");
}

int main(int argc, char *argv[])
{

    char c;
    char *filename = NULL;
    uint8_t month;
    int year;
    FILE *input_file;

    struct record *records = malloc(RECORDS_COUNT * sizeof(struct record));

    // разбираем аргументы
    while ((c = getopt(argc, argv, "hf:y:m:")) != -1)
    {
        switch (c)
        {
        case 'h':
            print_help();
            return 0;

        case 'f':
            filename = optarg;
            break;

        case 'y':
            year = atoi(optarg);
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

    if (argc == 1) {
        print_help();
        return 0;
    }

    // валидируем обязательные аргументы
    if (year == 0)
    {
        puts("-y: year is required!");
        return 1;
    }

    if (filename == NULL)
    {
        puts("-f: filename is required!");
        return 1;
    }

    //  открываем файл и валидируем что он открылся
    if ((input_file = fopen(filename, "r")) == NULL)
    {
        perror("failed to open input file");
        return 1;
    }

    // начинаем составление отчета
    int i = 0, absolute_line_count = 0;

    char line[100];
    char *s;

    printf("Open %s file...\n", filename);

    while (!feof(input_file))
    {
        absolute_line_count += 1;

        int parsed_count = fscanf(input_file, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd", &records[i].year, &records[i].month, &records[i].day, &records[i].hour, &records[i].minutes, &records[i].temperature);

        if (parsed_count < 6)
        {
            fscanf(input_file, "%[^\n]", line);
            printf(RED "Parsing error: line = %d content: %s parsed_count=%d\n" RESET, absolute_line_count, line, parsed_count);
        }
        else
        {
            i += 1;
        }
    }

    if (month > 0)
    {
        print_month_statistics(records, i, year, month);
    }
    else
    {
        print_year_statistics(records, i, year);
    }

    return 0;
}