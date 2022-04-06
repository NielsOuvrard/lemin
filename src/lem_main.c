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
    for (int x = 0; rooms[x] != NULL; x++) {
        printf("name : %s\ttype : %d\tnmb fourmis : %d\n",
        rooms[x]->name, rooms[x]->type, rooms[x]->fourmi);
    }
}

int lem_in(void)
{
    char **array = file_give_to_array();
    my_show_word_array(array);
    int imb_rooms = 0;
    node_room **rooms = complete_according_to_file(array, &imb_rooms);
    add_type(rooms, array);
    my_printf("\n");
    dump_graph(rooms);
    free_my_arr(array);
    return 0;
}

int main (int ac, char **av)
{
    return lem_in();
}
