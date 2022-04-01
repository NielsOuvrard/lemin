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
    struct node_room **tunnel;
    int nmb_tunnels;
    int fourmi;
} node_room;

// * ////////////// SRC DIR //////////////////////////////////////////

// create node

node_room *new_node_empty (void);

void connect_node (node_room *room1, node_room *room2);

void free_node_and_his_tunnels (node_room *room);

// main

int main (int ac, char **av);

// file give to array

char **file_give_to_array ();
