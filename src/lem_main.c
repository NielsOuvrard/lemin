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
        printf("name : %s\ttype : %d\tnmb fourmis : %d\t\tpos x-y : %d-%d\n",
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

int lem_in(void)
{
    char **array = file_give_to_array();
    disp_all_infos_according_to_array(array);
    node_room **rooms = complete_according_to_file(array);
    add_type(rooms, array);
    dump_graph(rooms);
    free_alls_rooms(rooms);
    free_my_arr(array);
    return 0;
}

int main (int ac, char **av)
{
    return lem_in();
}

// * mettre NULL à la fin
