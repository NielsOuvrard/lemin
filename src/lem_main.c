/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** lem_in
*/

#include "my.h"
#include "lem_header.h"

void free_node_and_his_tunnels (node_room *room)
{
    free(room->list_tunnels);
    free(room);
}

int lem_in (void)
{
    // char **array = file_give_to_array();
    // my_show_word_array(array);
    // free_my_arr(array);

    node_room *room1 = new_node_empty();
    node_room *room2 = new_node_empty();
    connect_node(room1, room2);
    room2->fourmi = 35;
    my_putstr(" nmb fourmis room1->list_tunnels[0].room->fourmi :\n");
    my_putint(room1->list_tunnels[0].room->fourmi);
    my_putstr("\n");


    my_putstr(" nmb fourmis room2 :\n");
    my_putint(room2->fourmi);
    my_putstr("\n");

    free_node_and_his_tunnels(room1);
    free_node_and_his_tunnels(room2);
    return 0;
}

int main (int ac, char **av)
{
    return lem_in();
}
