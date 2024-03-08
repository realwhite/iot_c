/*
G7 Практ 2
Количество букв
В файле .txt считать символьную строку, не более 10 000 символов.
Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке.
Учитывать только английские буквы. Результат записать в файл .txt.

Данные на входе: 	Строка состоящая из английских букв, цифр, пробелов и знаков препинания.
Данные на выходе: 	Два целых числа. Количество строчных букв и количество заглавных букв.

Пример №1
Данные на входе: 	aabbAB
Данные на выходе: 	4 2

Пример №2
Данные на входе: 	HELLO WORLD
Данные на выходе: 	0 10
*/

#include <stdio.h>

int is_lowercase(char c)
{
    return c >= 'a' && c <= 'z';
};

int is_uppercase(char c)
{
    return c >= 'A' && c <= 'Z';
}

int main()
{

    int uppercase_count = 0, lowercase_count = 0;
    char *input_fn = "task03_in.txt";
    char *output_fn = "task03_out.txt";
    char c;

    FILE *in, *out;

    if ((in = fopen(input_fn, "r")) == NULL)
    {
        perror("failed to open input file!");
        return 1;
    }

    while (((c = getc(in)) != EOF))
    {
        uppercase_count += is_uppercase(c);
        lowercase_count += is_lowercase(c);
    }

    if ((out = fopen(output_fn, "w")) == NULL)
    {
        perror("failed to open output file!");
        return 1;
    }

    fprintf(out, "%d %d", lowercase_count, uppercase_count);

    fclose(in);
    fclose(out);

    return 0;
}