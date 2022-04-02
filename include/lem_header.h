/*
** EPITECH PROJECT, 2021
** header du lem-in
** File description:
** bcp de definitions
*/
#pragma once

// read
#include <sys/types.h>
#include <sys/uio.h>
// write && read
#include <unistd.h>
// malloc / free
#include <stdlib.h>
// getline
#include <stdio.h>
// bool
#include <stdbool.h>

#define BUFF_SIZE 512

typedef struct node_room {
    // ? nmb tunnels ou dernier element null ?
    int nmb_tunnels;
    struct node_room **tunnel;
    int fourmi;
    int pos_x;
    int pos_y;
    char *name;
} node_room;

// * ////////////// SRC DIR //////////////////////////////////////////
// complete according to file

node_room **complete_according_to_file (char **file, int *a);

// create node

node_room *new_node_empty (char *name, int x, int y);

void connect_node (node_room *room1, node_room *room2);

void free_node_and_his_tunnels (node_room *room);

// main

int main (int ac, char **av);

// file give to array

char **file_give_to_array ();
