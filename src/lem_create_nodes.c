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
    node->tunnel = NULL;
    node->nmb_tunnels = 0;
    return node;
}

void new_tunnel (node_room *source, node_room *destination)
{
    source->nmb_tunnels++;
    ptrs_room *tunnel_room_1 = malloc(sizeof(ptrs_room) * source->nmb_tunnels);
    for (int i = 0; i < source->nmb_tunnels - 1; i++)
        tunnel_room_1[i].room = source->tunnel[i].room;
    tunnel_room_1[source->nmb_tunnels - 1].room = destination;
    free(source->tunnel);
    source->tunnel = tunnel_room_1;
}

void connect_node (node_room *room1, node_room *room2)
{
    new_tunnel(room1, room2);
    new_tunnel(room2, room1);
    return;
}

void free_node_and_his_tunnels (node_room *room)
{
    free(room->tunnel);
    free(room);
}