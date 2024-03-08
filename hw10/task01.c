/*
G3 Практ 1
Последний номер символа
В файле .txt дана строка из 1000 символов. Показать номера символов, совпадающих с последним символом строки. Результат записать в файл .txt

Данные на входе: 	Строка не более 1000 символов
Данные на выходе: 	Целые числа через пробел - номера символа, который совпадает с последним символом строки.

Пример
Данные на входе: 	aabbcdb
Данные на выходе: 	2 3
*/

#include <stdio.h>
#include <stdlib.h>

// получаем последний символ и его позицию в файле
uint8_t get_last_symbol(FILE *fp, char *c, uint64_t *last_position)
{
    if (fseek(fp, -1, SEEK_END) == 0)
    {
        *c = getc(fp);
        *last_position = ftell(fp) - 1;
    }
    else
    {
        return 1;
    };

    if (fseek(fp, 0, SEEK_SET) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{

    char *input_fn = "task01_in.txt";
    char *output_fn = "task01_out.txt";

    char c, last_symbol;
    uint64_t last_position;
    FILE *in, *out;

    if ((in = fopen(input_fn, "r")) == NULL)
    {
        perror("failed to open input file!");
        return 1;
    }

    if (get_last_symbol(in, &last_symbol, &last_position) != 0)
    {
        perror("failed to seek input file;");
        return 1;
    }

    if ((out = fopen(output_fn, "w")) == NULL)
    {
        perror("failed to open output file!");
        return 1;
    }

    int i = 0;
    while (((c = getc(in)) != EOF))
    {
        if (i == last_position)
            break;

        if (c == last_symbol)
        {
            printf("%d ", i);
            fprintf(out, "%d ", i);
        }

        i += 1;
    }

    fclose(in);
    fclose(out);

    return 0;
}