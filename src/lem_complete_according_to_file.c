/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** complete_according_to_file
*/

#include "my.h"
#include "lem_header.h"

node_room *room1_fun (node_room **all_rooms, char **str,
int nmb_rooms, int size_str)
{
    int j = 0, i = 0;
    char *room1_name = malloc(sizeof(char) * size_str);
    my_memset(room1_name, '\0', size_str);
    for (j = 0; (*str)[j] && (*str)[j] != '-'; j++)
        room1_name[i++] = (*str)[j];
    (*str) += j + 1;
    node_room *room1 = NULL;
    for (int a = 0; a < nmb_rooms; a++) {
        if (!my_strvcmp(room1_name, all_rooms[a]->name)) {
            room1 = all_rooms[a];
            break;
        }
    }
    if (!room1_name[0]) {
        free(room1_name);
        return NULL;
    }
    free(room1_name);
    return room1;
}

node_room *room2_fun (node_room **all_rooms, char *str,
int nmb_rooms, int size_str)
{
    char *room2_name = malloc(sizeof(char) * size_str);
    my_memset(room2_name, '\0', size_str);
    int i = 0;
    for (int j = 0; str[j] && str[j] != '-'; j++)
        room2_name[i] = str[j];
    node_room *room2 = NULL;
    for (int a = 0; a < nmb_rooms; a++) {
        if (!my_strvcmp(room2_name, all_rooms[a]->name)) {
            room2 = all_rooms[a];
            break;
        }
    }
    if (!room2_name[0]) {
        free(room2_name);
        return NULL;
    }
    free(room2_name);
    return room2;
}

void connect_node_with_str (node_room **all_rooms, char *str, int nmb_rooms)
{
    int size_str = my_strlen(str) + 1, i = 0, j;
    node_room *room1 = room1_fun(all_rooms, &str, nmb_rooms, size_str);
    if (!room1)
        return;
    node_room *room2 = room2_fun(all_rooms, str, nmb_rooms, size_str);
    if (!room2)
        return;
    connect_node(room1, room2);
}

node_room **complete_according_to_file (char **file, int *nmb_rooms)
{
    int nmb_fourmis = my_getnbr(*file), i;
    node_room **all_rooms = NULL;
    int file_type;
    for (i = 1; file[i]; i++) {
        if ((file_type = is_a_room(file[i])) == 1)
            all_rooms = add_room_in_list(all_rooms, file[i], (*nmb_rooms)++);
        else if (file_type == 2)
            break;
    }
    for (i = i; file[i]; i++)
        if ((file_type = is_a_tunnel(file[i])))
            connect_node_with_str(all_rooms, file[i], (*nmb_rooms));
    return all_rooms;
}

// TODO verif que 2 rooms n'aient pas le même nom
