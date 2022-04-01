/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** lem_in
*/

#include "my.h"
#include "lem_header.h"


int lem_in (void)
{
    // ./lem_in < anthill_trivial
    char **array = file_give_to_array();
    my_show_word_array(array);
    free_my_arr(array);

    node_room *room1 = new_node_empty();
    node_room *room2 = new_node_empty();
    my_putstr("\non connect room1 - room2\n");
    connect_node(room1, room2);


    node_room *room3 = new_node_empty();
    my_putstr("on connect room2 - room3\n");
    connect_node(room2, room3);
    room1->fourmi = 19;
    room2->fourmi = 25;
    room3->fourmi = 31;
    my_printf("nmb fourmis room1->tunnel[0].room->fourmi : %d\n", room1->tunnel[0].room->fourmi);
    my_printf("nmb fourmis room2 : %d\n", room2->fourmi);

    my_printf("nmb fourmis room2->tunnel[1].room : %d \n",
    room2->tunnel[1].room->fourmi);

    my_printf("nmb fourmis room2->tunnel[0].room : %d \n",
    room2->tunnel[0].room->fourmi);

    free_node_and_his_tunnels(room1);
    free_node_and_his_tunnels(room2);
    return 0;
}

int main (int ac, char **av)
{
    return lem_in();
}
