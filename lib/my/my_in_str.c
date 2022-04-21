/*
** EPITECH PROJECT, 2022
** mylib
** File description:
** my_in_str
*/

#include "my.h"

int my_in_str(char intruder, const char *selection)
{
    while (*selection != 0) {
        if (intruder == *selection)
            return 1;
        selection++;
    }
    return 0;
}
