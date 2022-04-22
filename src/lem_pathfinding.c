/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** lem_in
*/

#include "my.h"
#include "lem_header.h"

void print_final(struct ant **ant_list, int *o_len_path, node_room ***paths)
{
    int check = 1;
    while (check) {
        check = 0;
        for (int i = 0; ant_list[i]; i++) {
            ant_list[i]->pos += 1;
            (ant_list[i]->pos >= 0 && ant_list[i]->pos <
            o_len_path[ant_list[i]->path]) ? my_printf("%cP%d-%s",
            (check) ? ' ' : '\n', ant_list[i]->number,
            paths[ant_list[i]->path][ant_list[i]->pos]->name) : 0;
            (ant_list[i]->pos >= 0 && ant_list[i]->pos <
            o_len_path[ant_list[i]->path]) ? check = 1 : 0;
        }
    }
    my_printf("\n");
}

void free_pathfinding(int *len_path, int *o_len_path, struct ant **ant_list)
{
    free(len_path);
    free(o_len_path);
    for (int i = 0; ant_list[i]; i++)
        free(ant_list[i]);
    free(ant_list);
}

void choose_path_and_display(node_room **rooms, int start, node_room ***paths)
{
    int len = 0;
    int *len_path = malloc(sizeof(int) * (rooms[start]->nmb_tunnels + 1));
    int *o_len_path = malloc(sizeof(int) * (rooms[start]->nmb_tunnels + 1));
    for (int i = 0; i < rooms[start]->nmb_tunnels; i++) {
        len_path[i] = -1;
        o_len_path[i] = -1;
        if (paths[i] == NULL)
            continue;
        len = 0;
        for (; paths[i][len]; len++);
        len_path[i] = len + 1;
        o_len_path[i] = len;
    }
    len_path[rooms[start]->nmb_tunnels] = -1;
    o_len_path[rooms[start]->nmb_tunnels] = -1;
    struct ant **ant_list = creat_ant_list(rooms, start, len_path, o_len_path);
    print_final(ant_list, o_len_path, paths);
    free_pathfinding(len_path, o_len_path, ant_list);
}

int calc_and_dispaly(node_room **rooms, int start, int end, int size)
{
    node_room ***paths = malloc(sizeof(node_room **) *
    (rooms[start]->nmb_tunnels + 1));
    for (int j = 0; j < rooms[start]->nmb_tunnels; j++) {
        paths[j] = malloc(sizeof(node_room *) * (size + 1));
        for (int i = 0; i < size; i++)
            paths[j][i] = NULL;
        paths[j][size] = NULL;
    }
    paths[rooms[start]->nmb_tunnels] = NULL;
    rooms[start]->visited = 4;
    for (int a = 0; a < rooms[start]->nmb_tunnels; a++)
        paths[a] = find_paths(rooms, paths[a], end, start);
    if (paths[0] == NULL)
        return 84;
    paths = my_revpath(paths);
    choose_path_and_display(rooms, start, paths);
    for (int j = 0; j < rooms[start]->nmb_tunnels; j++)
        free(paths[j]);
    free(paths);
    return 0;
}

int do_pathfinding(node_room **rooms)
{
    int start = 0, end = 0, size = 0;
    for (int x = 0; rooms[x]; x++) {
        (rooms[x]->type == 0) ? end = x : 0;
        (rooms[x]->type == 1) ? start = x : 0;
        rooms[x]->visited = 0;
        rooms[x]->from = -1;
        size++;
    }
    for (int j = 0; j < rooms[start]->nmb_tunnels; j++)
        if (rooms[start]->tunnel[j]->type == 0) {
            print_start_end(rooms, start, j);
            return 0;
        }
    if (calc_and_dispaly(rooms, start, end, size))
        return 84;
    return 0;
}
