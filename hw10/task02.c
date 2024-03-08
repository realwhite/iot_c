/*
G5 ДЗ 2
Заменить a на b
В файле .txt дана символьная строка не более 1000 символов.
Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные.
Результат записать в .txt.

Данные на входе: 	Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Данные на выходе: 	Строка из маленьких и больших английских букв, знаков препинания и пробелов.

Пример
Данные на входе: 	aabbccddABCD
Данные на выходе: 	bbaaccddBACD
*/

#include <stdio.h>
#include <stdlib.h>

char convert_char(char c)
{
    char c_to_write;

    switch (c)
    {
    case 'a':
        c_to_write = 'b';
        break;
    case 'b':
        c_to_write = 'a';
        break;
    case 'A':
        c_to_write = 'B';
        break;
    case 'B':
        c_to_write = 'A';
        break;

    default:
        c_to_write = c;
        break;
    }

    return c_to_write;
}

int main()
{
    char *input_fn = "task02_in.txt";
    char *output_fn = "task02_out.txt";
    char c;
    FILE *in, *out;

    if ((in = fopen(input_fn, "r")) == NULL)
    {
        perror("failed to open input file!");
        return 1;
    }

    if ((out = fopen(output_fn, "w")) == NULL)
    {
        perror("failed to open output file!");
        return 1;
    }

    while (((c = getc(in)) != EOF))
    {

        putc(convert_char(c), out);
    }

    fclose(in);
    fclose(out);

    return 0;
}