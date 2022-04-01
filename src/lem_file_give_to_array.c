/*
** EPITECH PROJECT, 2022
** file give to array
** File description:
** file give to array
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

char **augmente_size_array (char **map, char *str)
{
    int len_array = my_arraylen(map);
    int len_str = 512;
    char **tmp = malloc(sizeof(char *) * (len_array + 2));
    int i;
    for (i = 0; i < len_array; i++) {
        tmp[i] = malloc(sizeof(char) * len_str);
        my_memset(tmp[i], len_str - 1, '\0');
        my_strcpy(tmp[i], map[i]);
    }
    free(map);
    tmp[len_array] = str;
    tmp[len_array + 1] = NULL;
    return tmp;
}

char **file_give_to_array ()
{
    char **array = malloc(sizeof(char *));
    array[0] = NULL;
    char *str;
    while ((str = my_scanf())) {
        my_putstr(str);
        array = augmente_size_array(array, str);
    }
    return array;
}
