/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** lem_in
*/

#include "my.h"
#include "lem_header.h"

char *my_scanf (void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t lower_case = 0;
    lower_case = getline(&line, &len, stdin);
    if (lower_case < 0) {
        free(line);
        return NULL;
    }
    return line;
}

int main (int ac, char **av)
{
    char *str;
    while ((str = my_scanf())) {
        my_putstr(str);
        free(str);
    }
    return 0;
}
