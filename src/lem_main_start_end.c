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
    for (int x = 0; arr[x] != NULL ; x++) {
        if (my_strcmp(str, arr[x]) == 0) {
            return cur_name(arr[x + 1]);
        }
    }
    return NULL;
}

void end_st_samexy(node_room **rooms, char **arr)
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for (int x = 0; rooms[x]; x++) {
        (rooms[x]->type == 1) ? x1 = rooms[x]->pos_x, y1 = rooms[x]->pos_y : 0;
        (rooms[x]->type == 0) ? x2 = rooms[x]->pos_x, y2 = rooms[x]->pos_y : 0;
    }
    if (x1 == x2 && y1 == y2) {
        free_alls_rooms (rooms);
        free_my_arr(arr);
        exit(84);
    }
}

int connected_start_end(node_room *se)
{
    se->visited = 1;
    if(se->type == 0)
        return 1;
    for (int x = 0; se->tunnel[x] != NULL; x++) {
        if(se->tunnel[x]->visited != 1) {
            if(connected_start_end(se->tunnel[x]) == 1)
                return 1;
        }
    }
    return 0;
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

    int x = 0;
    for(; rooms[x] != NULL && rooms[x]->type != 1; x++);
    node_room *se = rooms[x];
    if(connected_start_end(se) == 0) {
        free_alls_rooms (rooms);
        free_my_arr(arr);
        exit (84);
    }
    end_st_samexy(rooms, arr);
}
