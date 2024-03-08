/*
G10
Самое длинное слово
В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное слово и вывести его в файл .txt. 
Случай, когда самых длинных слов может быть несколько, не обрабатывать. 

Данные на входе: 	Строка из английских букв и пробелов. Не более 1000 символов. 
Данные на выходе: 	Одно слово из английских букв. 

Пример
Данные на входе: 	Hello beautiful world 
Данные на выходе: 	beautiful 
*/

#include <stdio.h>
#include <strings.h>


int main() {
    char *input_fn = "task05_in.txt";
    char *output_fn = "task05_out.txt";
    FILE *in, *out;
    char str[1000] = {'\0'};
    char max_str[1000] = {'\0'};

    if ((in = fopen(input_fn, "r")) == NULL)
    {
        perror("failed to open input file!");
        return 1;
    }

    while(fscanf(in, "%s", str) == 1) {
        if (strlen(str) > strlen(max_str)) {
            strcpy(max_str, str);
        }
    };
    fclose(in);

    if ((out = fopen(output_fn, "w")) == NULL)
    {
        perror("failed to open output file!");
        return 1;
    }

    fprintf(out, "%s", max_str);
    fclose(out);

    return 0;
}