/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** create node
*/

#include "my.h"
#include "lem_header.h"

node_room *new_node_empty (void)
{
    node_room *node = malloc(sizeof(node_room));
    node->fourmi = 0;
    node->list_tunnels = NULL;
    node->nmb_tunnels = 0;
    return node;
}

void connect_node (node_room *room1, node_room *room2)
{
    room1->nmb_tunnels++;
    ptrs_room *tunnel_room_1 = malloc(sizeof(ptrs_room) * room1->nmb_tunnels);
    for (int i = 0; i < room1->nmb_tunnels - 1; i++)
        tunnel_room_1[i].room = room1->list_tunnels[i].room;
    tunnel_room_1[room1->nmb_tunnels - 1].room = room2;
    free(room1->list_tunnels);
    room1->list_tunnels = tunnel_room_1;

    room2->nmb_tunnels++;
    ptrs_room *tunnel_room_2 = malloc(sizeof(ptrs_room) * room2->nmb_tunnels);
    for (int i = 0; i < room2->nmb_tunnels - 1; i++)
        tunnel_room_2[i].room = room2->list_tunnels[i].room;
    tunnel_room_2[room2->nmb_tunnels - 1].room = room1;
    free(room2->list_tunnels);
    room2->list_tunnels = tunnel_room_2;
    return;
}
