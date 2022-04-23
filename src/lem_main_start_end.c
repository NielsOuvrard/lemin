/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** lem_in
*/

#include "my.h"
#include "lem_header.h"

char *cur_name(char *str)
{
    int x, w;
    for (x = 0; str[x] != ' '; x++);
    char *yes = malloc(sizeof(char) * (x + 1));
    for (w = 0; str[w] != ' '; w++)
        yes[w] = str[w];
    yes[w] = '\0';
    return yes;
}

char *get_name(char **arr, char *str)
{
    for (int x = 0; arr[x] != NULL; x++) {
        if (my_strcmp(str, arr[x]) == 0)
            return cur_name(arr[x + 1]);
    }
    return NULL;
}

int end_st_samexy(node_room **ro, char **arr)
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for (int x = 0; ro[x]; x++) {
        (ro[x]->type == 1) ? x1 = ro[x]->pos_x, y1 = ro[x]->pos_y : 0;
        (ro[x]->type == 0) ? x2 = ro[x]->pos_x, y2 = ro[x]->pos_y : 0;
    }
    if (x1 == x2 && y1 == y2) {
        free_alls_rooms(ro);
        free_my_arr(arr);
        return (-1);
    }
}

int add_type(node_room **rooms, char **arr)
{
    char *start = get_name(arr, "##start"), *end = get_name(arr, "##end");
    if (!start || !end) return -1;
    int tot_fourm = my_getnbr(arr[0]), size;
    for (int x = 0; rooms[x]; x++) {
        if (!my_strcmp(start, rooms[x]->name)) {
            rooms[x]->type = START;
            rooms[x]->fourmi = tot_fourm;
            continue;
        }
        if (!my_strcmp(end, rooms[x]->name)) {
            rooms[x]->type = END;
            continue;
        }
        rooms[x]->type = NORMAL;
    }
    free(start);
    free(end);
    return end_st_samexy(rooms, arr);
}
