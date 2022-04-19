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

#define MYEOF         -2
#define UNKNOWN     -1
#define COMMAND     0
#define COMMENT     1
#define ROOM        2
#define TUNNEL      3
#define ANT         4

typedef struct node_room {
    int nmb_tunnels;
    struct node_room **tunnel;
    int fourmi;
    int pos_x;
    int pos_y;
    char *name;
    int type;
    int visited;
    int from;
} node_room;

struct ant {
    int pos;
    int path;
    int number;
};

// * ////////////// SRC DIR //////////////////////////////////////////

// complete according to file

node_room **complete_according_to_file (char **file);

// is a room

node_room **add_room_in_list (node_room **list, char *str);
// node_room **add_room_in_list (node_room **list, char *str, int nmb_rooms);

int is_a_room (char *str);

int is_a_tunnel (char *str);

// create node

node_room *new_node_empty (char *name, int x, int y);

void connect_node (node_room *room1, node_room *room2);

void free_node_and_his_tunnels (node_room *room);

// disp infos

void disp_all_infos_according_to_array (char **array);

// start end

char *cur_name(char *str);

char *get_name(char **arr, char *str);

void add_type(node_room **rooms, char **arr);

// main

int main (int ac, char **av);
void free_alls_rooms (node_room **rooms);

// file give to array

char **file_give_to_array (void);

// File integrity check (error gestion)
int file_integrity_check(char **file);

// Line integrity checks (error gestion)
int is_there_command(char *line);
int is_there_comment(char *line);
int check_tunnel_definition(char *line);
int check_room_definition(char *line);
int check_ant_number(char *line);

/**
 * Returns -1 on unknown pattern
 * Returns 0 if comment or command
 * Returns 1 if room definition
 * Returns 2 if move
 * Returns 3 if number of ants
*/
int get_line_identity(char *line);
