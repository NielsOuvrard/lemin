/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** lem_in
*/

#include "my.h"
#include "lem_header.h"

void dump_graph (node_room **rooms)
{
    my_printf("\n");
    for (int x = 0; rooms[x]; x++) {
        my_printf("name : %s\ttype : %d\tnmb fourmis : %d\t\tpos x-y : %d-%d\n",
        rooms[x]->name, rooms[x]->type, rooms[x]->fourmi,
        rooms[x]->pos_x, rooms[x]->pos_y);
    }
}

void free_alls_rooms (node_room **rooms)
{
    for (int x = 0; rooms[x]; x++) {
        free(rooms[x]->name);
        free(rooms[x]->tunnel);
        free(rooms[x]);
    }
    free(rooms);
}

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

void do_pathfinding(node_room **rooms)
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
            for (int k = 1; k <= rooms[start]->fourmi; k++)
                my_printf("P%d-%s%c", k, rooms[start]->tunnel[j]->name,
                (k == rooms[start]->fourmi) ? '\n' : ' ');
            return;
        }
    node_room ***paths = malloc(sizeof(node_room **) * (rooms[start]->nmb_tunnels + 1));
    for (int j = 0; j < rooms[start]->nmb_tunnels; j++) {
        paths[j] = malloc(sizeof(node_room *) * (size + 1));
        for (int i = 0; i < size; i++)
            paths[j][i] = NULL;
        paths[j][size] = NULL;
    }
    paths[rooms[start]->nmb_tunnels] = NULL;
    rooms[start]->visited = 4;
    int k = 0, loop = 0;
    for (int a = 0; a < rooms[start]->nmb_tunnels; a++) {
        while (rooms[end]->visited != 3) {
            for (int i = 0; rooms[i]; i++) {
                if (rooms[i]->visited != 3)
                    continue;
                for (int j = 0; j < rooms[i]->nmb_tunnels; j++) {
                    if (rooms[i]->tunnel[j]->visited == 0) {
                        rooms[i]->tunnel[j]->visited = 4;
                        rooms[i]->tunnel[j]->from = i;
                    }
                }
            }
            for (int i = 0; rooms[i]; i++)
                (rooms[i]->visited == 3) ? rooms[i]->visited = 1 : 0;
            for (int i = 0; rooms[i]; i++)
                (rooms[i]->visited == 4) ? rooms[i]->visited = 3 : 0;
        }
        k = 0;
        if (rooms[end]->visited == 3) {
            for (int i = end; i != start; i = rooms[i]->from) {
                rooms[i]->visited = 2;
                paths[a][k] = rooms[i];
                k++;
            }
        }
        for (int x = 0; rooms[x]; x++)
            (rooms[x]->visited != 2 && x != start) ? rooms[x]->visited = 0 : 0;
        rooms[end]->visited = 0;
        rooms[start]->visited = 4;
    }
    paths = my_revpath(paths);
    int len = 0, search_lowest = 0, lowest_pos;
    int *len_path = malloc(sizeof(int) * (rooms[start]->nmb_tunnels + 1));
    int *o_len_path = malloc(sizeof(int) * (rooms[start]->nmb_tunnels + 1));
    for (int i = 0; i < rooms[start]->nmb_tunnels; i++) {
        len = 0;
        for (int c = 0; paths[i][c]; c++)
            len++;
        len_path[i] = len + 1;
        o_len_path[i] = len;
    }
    len_path[rooms[start]->nmb_tunnels] = -1;
    o_len_path[rooms[start]->nmb_tunnels] = -1;
    struct ant **ant_list = malloc(sizeof(struct ant *) * (rooms[start]->fourmi + 1));
    for (int i = 0; i < rooms[start]->fourmi; i++) {
        ant_list[i] = malloc(sizeof(struct ant));
        ant_list[i]->number = i + 1;
        search_lowest = -1;
        for (int j = 0; j < rooms[start]->nmb_tunnels; j++) {
            if (len_path[j] < search_lowest || search_lowest == -1) {
                search_lowest = len_path[j];
                lowest_pos = j;
            }
        }
        ant_list[i]->path = lowest_pos;
        ant_list[i]->pos = o_len_path[lowest_pos] - len_path[lowest_pos];
        len_path[lowest_pos] += 1;
    }
    ant_list[rooms[start]->fourmi] = NULL;
    int check = 1;
    while (check) {
        check = 0;
        for (int i = 0; ant_list[i]; i++) {
            ant_list[i]->pos += 1;
            if (ant_list[i]->pos >= 0 && ant_list[i]->pos < o_len_path[ant_list[i]->path]) {
                my_printf("%cP%d-%s", (check) ? ' ' : '\n', ant_list[i]->number, paths[ant_list[i]->path][ant_list[i]->pos]->name);
                check = 1;
            }
        }
    }
    my_printf("\n");
    return;
}

int lem_in(void)
{
    char **array = file_give_to_array();
    if (file_integrity_check(array) == -1)
        return 84;
    disp_all_infos_according_to_array(array);
    node_room **rooms = complete_according_to_file(array);
    add_type(rooms, array);
    do_pathfinding(rooms);
    // dump_graph(rooms);
    free_alls_rooms(rooms);
    free_my_arr(array);
    return 0;
}

int main (int ac, char **av)
{
    return lem_in();
}

// * mettre NULL à la fin
