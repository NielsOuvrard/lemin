/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** lem_in
*/

#include "my.h"
#include "lem_header.h"

node_room ***my_revpath(node_room ***paths)
{
    int i = 0, j = 0;
    node_room *c;
    for (int k = 0; paths[k]; k++) {
        i = 0;
        for (int l = 0; paths[k][l]; l++)
            i++;
        i--;
        j = 0;
        while (j < (i / 2) + 1) {
            c = paths[k][i - j];
            paths[k][i - j] = paths[k][j];
            paths[k][j] = c;
            j++;
        }
    }
    return paths;
}

node_room **visit_room(node_room **rooms)
{
    for (int i = 0; rooms[i]; i++) {
        if (rooms[i]->visited != 3)
            continue;
        for (int j = 0; j < rooms[i]->nmb_tunnels; j++) {
            (rooms[i]->tunnel[j]->visited == 0) ?
            rooms[i]->tunnel[j]->from = i : 0;
            (rooms[i]->tunnel[j]->visited == 0) ?
            rooms[i]->tunnel[j]->visited = 4 : 0;
        }
    }
    for (int i = 0; rooms[i]; i++)
        (rooms[i]->visited == 3) ? rooms[i]->visited = 1 : 0;
    for (int i = 0; rooms[i]; i++)
        (rooms[i]->visited == 4) ? rooms[i]->visited = 3 : 0;
    return rooms;
}

node_room **find_paths(node_room **rooms, node_room **paths, int end,
int start)
{
    int count_2 = 0, count = 0, size = 0, k = 0, j = 0, old_count = 0;
    for (; rooms[size]; size++);
    while (rooms[end]->visited != 3) {
        rooms = visit_room(rooms);
        for (j = 0, old_count = count, count = 0; rooms[j]; j++)
            (rooms[j]->visited == 1 || rooms[j]->visited == 2) ? count++ : 0;
        (count == old_count) ? count_2++ : 0;
        if (count_2 > 2)
            return NULL;
    }
    if (rooms[end]->visited == 3)
        for (int i = end; i != start; i = rooms[i]->from, k++) {
            rooms[i]->visited = 2;
            paths[k] = rooms[i];
        }
    for (int x = 0; rooms[x]; x++)
        (rooms[x]->visited != 2 && x != start) ? rooms[x]->visited = 0 : 0;
    rooms[end]->visited = 0;
    rooms[start]->visited = 4;
    return paths;
}

void print_start_end(node_room **rooms, int start, int j)
{
    my_putchar('\n');
    for (int k = 1; k <= rooms[start]->fourmi; k++)
        my_printf("P%d-%s%c", k, rooms[start]->tunnel[j]->name,
        (k == rooms[start]->fourmi) ? '\n' : ' ');
}

struct ant **creat_ant_list(node_room **rooms, int start, int *len_path,
int *o_len_path)
{
    int search_lowest = 0, lowest_pos;
    struct ant **ant_list = malloc(sizeof(struct ant *) *
    (rooms[start]->fourmi + 1));
    for (int i = 0; i < rooms[start]->fourmi; i++) {
        ant_list[i] = malloc(sizeof(struct ant));
        ant_list[i]->number = i + 1;
        search_lowest = -1;
        for (int j = 0; len_path[j] != -1; j++) {
            (len_path[j] < search_lowest || search_lowest == -1) ?
            lowest_pos = j : 0;
            (len_path[j] < search_lowest || search_lowest == -1) ?
            search_lowest = len_path[j] : 0;
        }
        ant_list[i]->path = lowest_pos;
        ant_list[i]->pos = o_len_path[lowest_pos] - len_path[lowest_pos];
        len_path[lowest_pos] += 1;
    }
    ant_list[rooms[start]->fourmi] = NULL;
    return ant_list;
}
