/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** complete_according_to_file
*/

#include "my.h"
#include "lem_header.h"

node_room **add_room_in_list (node_room **list, char *str, int nmb_rooms)
{
    node_room **new = malloc(sizeof(node_room *) * (nmb_rooms + 1));
    for (int i = 0; i < nmb_rooms; i++)
        new[i] = list[i];
    free(list);
    int size_name = my_strlen(str) + 1, x, y;
    char *name = malloc(sizeof(char) * size_name);
    my_memset(name, '\0', size_name - 1);
    int i;
    for (i = 0; str[i] && str[i] != ' '; i++)
        name[i] = str[i];
    str += i;
    x = my_getnbr(str);
    while (my_isdidgit(*str))
        str++;
    y = my_getnbr(str);
    new[nmb_rooms] = new_node_empty(name, x, y);
    return new;
}

int is_a_room (char *str)
{
    if (str[0] == '#')
        return 0;
    while (my_isdidgit(*str))
        str++;
    if (str[0] == '-')
        return 2;
    else if (str[0] == ' ')
        str++;
    else
        return 0;
    while (my_isdidgit(*str))
        str++;
    if (*str)
        str++;
    else
        return 0;
    while (my_isdidgit(*str))
        str++;
    if (str[0] && str[0] != '#' && str[0] != ' ')
        return 0;
    return 1;
}
// ? plutieurs espaces ...

int is_a_tunnel (char *str)
{
    int dash = 0, i = 0;
    for (i = 0; str[i]; i++)
        if (str[i] == '-' && str[i + 1])
            dash++;
    if (dash == 1)
        return 1;
    return 0;
}
