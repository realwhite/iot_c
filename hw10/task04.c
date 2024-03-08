/*
G9 ДЗ 4
Удалить повторяющиеся символы
В файле .txt строка из меленьких и больших английских букв, знаков препинания и пробелов.
Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл .txt.

Данные на входе: 	Строка из меленьких и больших английских букв, знаков препинания и пробелов.
                    Размер строки не более 1000 сивмолов.
Данные на выходе: 	Строка из меленьких и больших английских букв.

Пример
Данные на входе: 	abc cde def
Данные на выходе: 	abcdef
*/

#include <stdio.h>

int is_duplicate_or_space(char c)
{
    static int arr[100] = {0};

    if (c == ' ')
        return 1;

    if (arr[c] == 0) {
        arr[c] = 1;
        return 0;
    }
        
    return 1;
}

int main()
{   
    char *input_fn = "task04_in.txt";
    char *output_fn = "task04_out.txt";
    char c;
    FILE *in, *out;

    if ((in = fopen(input_fn, "r")) == NULL)
    {
        perror("failed to open input file!");
        return 1;
    }

    if ((out = fopen(output_fn, "w")) == NULL)
    {
        fclose(in);
        perror("failed to open output file!");
        return 1;
    }

    while (((c = getc(in)) != EOF))
    {
        if (!is_duplicate_or_space(c)) {
            putc(c, out);
        }
    }

    fclose(in);
    fclose(out);


    return 0;
}