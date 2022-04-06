/*
** EPITECH PROJECT, 2021
** header du lem-in
** File description:
** bcp de definitions
*/
#pragma once

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define BUFF_SIZE 512

#define END 0
#define START 1
#define NORMAL 2

typedef struct node_room {
    int nmb_tunnels;
    int type;
    struct node_room **tunnel;
    int fourmi;
    int pos_x;
    int pos_y;
    char *name;
} node_room;

// * ////////////// SRC DIR //////////////////////////////////////////

// complete according to file

node_room **complete_according_to_file (char **file, int *a);

// is a room

node_room **add_room_in_list (node_room **list, char *str, int nmb_rooms);

int is_a_room (char *str);

int is_a_tunnel (char *str);

// create node

node_room *new_node_empty (char *name, int x, int y);

void connect_node (node_room *room1, node_room *room2);

void free_node_and_his_tunnels (node_room *room);

// start end

char *cur_name(char *str);

char *get_name(char **arr, char *str);

void add_type(node_room **rooms, char **arr);

// main

int main (int ac, char **av);

// file give to array

char **file_give_to_array ();
