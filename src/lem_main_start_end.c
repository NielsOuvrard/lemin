/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** lem_in
*/

#include "my.h"
#include "lem_header.h"

char *cur_name(char *str)
{   int x, w;
    for (x = 0; str[x] != ' '; x++);
    char *yes = malloc(sizeof (char) * (x + 1));
    for (w = 0; str[w] != ' '; w++)
        yes[w] = str[w];
    yes[w] = '\0';
    return yes;
}

char *get_name(char **arr, char *str)
{
    for (int x = 0; arr[x] != NULL ; x++) {
        if (my_strcmp(str, arr[x]) == 0) {
            return cur_name(arr[x + 1]);
        }
    }
    return NULL;
}

void add_type(node_room **rooms, char **arr)
{
    char *start = get_name(arr, "##start");
    if (!start)
        return;
    char *end = get_name(arr, "##end");
    if (!end)
        return;
    int tot_fourm = my_getnbr(arr[0]), size;
    for (int x = 0; rooms[x]; x++) {
        if (!my_strcmp(start, rooms[x]->name)) {
            rooms[x]->type = START;
            rooms[x]->fourmi = tot_fourm;
        } else if (!my_strcmp(end, rooms[x]->name)) {
            rooms[x]->type = END;
        } else {
            rooms[x]->type = NORMAL;
        }
    }
    free(start);
    free(end);
}
