/*
** EPITECH PROJECT, 2022
** rush2_2
** File description:
** rush2_2
*/

#include "my.h"
#include "frequences.h"

int char_lowcase(char c);
int get_number_letter(char *str);
int occurence_letter(char c, char *str);
int ret_occurence_letter(char c, char *str);
int ret_percentage(char c, char *str);

int get_percentage(char c, char *str)
{
    float percentage = 0;
    int occurence = occurence_letter(c, str);
    int nb_letter = get_number_letter(str);

    percentage = ((float)occurence / (float)nb_letter) * 100.0f;
    my_putchar(' ');
    my_putchar('(');
    my_put_nbr((int)percentage);
    my_putchar('.');
    my_put_nbr((int)(percentage * 10) % 10);
    my_put_nbr((int)(percentage * 100) % 10);
    my_putchar('%');
    my_putchar(')');
    return percentage;
}

void conditional_bloc1(char *str, int index_language)
{
    if (index_language == 0)
        my_putstr("=> English");
    if (index_language == 1)
        my_putstr("=> French");
    if (index_language == 2)
        my_putstr("=> German");
    if (index_language == 3)
        my_putstr("=> Spanish");
}

float conditional_bloc2(char *str, int i, int j)
{
    float difference = ret_percentage('a' + i, str) - alphabet[i][j];
    if (difference < 0)
        difference *= -1;
    return difference;
}

void detect_language(char *str)
{
    float counter[4] = {0, 0, 0, 0};
    int index_language = 0;

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 4; j++) {
            counter[j] += conditional_bloc2(str, i, j);
        }
    }
    for (int i = 1; i < 4; i++) {
        if (counter[i] < counter[index_language])
            index_language = i;
    }
    conditional_bloc1(str, index_language);
}

int main(int argc, char **argv)
{
    if (argc <= 2)
        return 84;
    for (int i = 2; i < argc; i++) {
        get_percentage(argv[i][0], argv[1]);
        my_putchar('\n');
    }
    detect_language(argv[1]);
    return 0;
}
