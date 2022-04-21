/*
** EPITECH PROJECT, 2022
** mylib
** File description:
** my_trimchar
*/

#include "my.h"

char *my_trimchar_start(char *str, const char *trailing_char)
{
    int i = 0;
    while (my_in_str(str[i], trailing_char))
        i++;
    my_strcpy(str, str + i);
    return str;
}

char *my_trimchar_end(char *str, const char *trailing_char)
{
    int i = my_strlen(str) - 1;
    while (i >= 0 && my_in_str(str[i], trailing_char)) {
        str[i] = 0;
        i--;
    }
    return str;
}

char *my_trimchar(char *str, const char *trailing_char, char mode)
{
    if (*str == 0)
        return str;
    if (mode == 'e')
        return my_trimchar_end(str, trailing_char);
    if (mode == 's')
        return my_trimchar_start(str, trailing_char);
    return str;
}
