/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** lem_in
*/

#include "my.h"
#include "lem_header.h"

void dump_graph (node_room **rooms, int nmb_rooms)
{
    for (int x = 0; x < nmb_rooms; x++) {
        printf("name : %s\ttype : %d\tnmb fourmis : %d\n",
        rooms[x]->name, rooms[x]->type, rooms[x]->fourmi);
    }
}

void free_alls_rooms (node_room **rooms, int nmb_rooms)
{
    for (int x = 0; x < nmb_rooms; x++) {
        free(rooms[x]->name);
        free(rooms[x]->tunnel);
        free(rooms[x]);
    }
    free(rooms);
}

int lem_in(void)
{
    char **array = file_give_to_array();
    my_show_word_array(array);
    int nmb_rooms = 0;
    node_room **rooms = complete_according_to_file(array, &nmb_rooms);
    add_type(rooms, array, nmb_rooms);
    dump_graph(rooms, nmb_rooms);
    free_alls_rooms(rooms, nmb_rooms);
    free_my_arr(array);
    return 0;
}

int main (int ac, char **av)
{
    return lem_in();
}
