/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** complete_according_to_file
*/

#include "my.h"
#include "lem_header.h"

node_room *room1_fun (node_room **all_rooms, char **str, int size_str)
{
    int j = 0, i = 0, size;
    for (size = 0; all_rooms[size]; size++);
    char *room1_name = malloc(sizeof(char) * size_str);
    my_memset(room1_name, '\0', size_str);
    for (j = 0; (*str)[j] && (*str)[j] != '-'; j++)
        room1_name[i++] = (*str)[j];
    (*str) += j + 1;
    node_room *room1 = NULL;
    for (int a = 0; a < size; a++) {
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

node_room *room2_fun (node_room **all_rooms, char *str, int size_str)
{
    char *room2_name = malloc(sizeof(char) * size_str);
    int i = 0, size;
    my_memset(room2_name, '\0', size_str);
    for (size = 0; all_rooms[size]; size++);
    for (int j = 0; str[j] && str[j] != '-'; j++)
        room2_name[i] = str[j];
    node_room *room2 = NULL;
    for (int a = 0; a < size; a++) {
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

void connect_node_with_str (node_room **all_rooms, char *str)
{
    int size_str = my_strlen(str) + 1, i = 0, j;
    node_room *room1 = room1_fun(all_rooms, &str, size_str);
    if (!room1)
        return;
    node_room *room2 = room2_fun(all_rooms, str, size_str);
    if (!room2)
        return;
    connect_node(room1, room2);
}

node_room **complete_according_to_file (char **file)
{
    int nmb_fourmis = my_getnbr(*file), i;
    node_room **all_rooms = malloc(sizeof(node_room *));
    all_rooms[0] = NULL;
    int file_type;
    my_printf("ok 1.1\n");
    for (i = 1; file[i]; i++) {
        if ((file_type = is_a_room(file[i])) == 1)
            all_rooms = add_room_in_list(all_rooms, file[i]);
        else if (file_type == 2)
            break;
    }
    my_printf("ok 1.2\n");
    my_printf("name de 0: %s\n", all_rooms[0] ? "YES" : "NO");

    for (int j = 0; all_rooms[j]; j++) {
        my_printf("name : %s\n", all_rooms[j]->name);
    }

    for (i = i; file[i]; i++)
        if ((file_type = is_a_tunnel(file[i])))
            connect_node_with_str(all_rooms, file[i]);
    return all_rooms;
}

// TODO verif que 2 rooms n'aient pas le même nom
