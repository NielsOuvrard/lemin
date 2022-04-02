/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** complete_according_to_file
*/

#include "my.h"
#include "lem_header.h"

node_room **add_room_in_list (node_room **list, char *str, int nmb_rooms)
{
    node_room **new = malloc(sizeof(node_room *) * (nmb_rooms + 1));
    for (int i = 0; i < nmb_rooms; i++)
        new[i] = list[i];
    free(list);
    int size_name = my_strlen(str) + 1, x, y;
    // my_printf("size str : %d\n", size_name);
    char *name = malloc(sizeof(char) * size_name);
    my_memset(name, '\0', size_name - 1);
    int i;
    for (i = 0; str[i] && str[i] != ' '; i++)
        name[i] = str[i];
    str += i;
    // my_printf("new room %s\n", name);
    x = my_getnbr(str);
    while (my_isdidgit(*str))
        str++;
    y = my_getnbr(str);
    new[nmb_rooms] = new_node_empty(name, x, y);
    return new;
}

int is_a_room (char *str)
{
    if (str[0] == '#')
        return 0;
    while (my_isdidgit(*str))
        str++;
    if (str[0] == '-')
        return 2;
    else if (str[0] == ' ')
        str++;
    else
        return 0;
    while (my_isdidgit(*str))
        str++;
    if (*str)
        str++;
    else
        return 0;
    while (my_isdidgit(*str))
        str++;
    if (str[0] && str[0] != '#' && str[0] != ' ')     // ? plutieurs espaces ...
        return 0;
    return 1;
}

int is_a_tunnel (char *str)
{
    int dash = 0, i = 0;
    for (i = 0; str[i]; i++)
        if (str[i] == '-' && str[i + 1])
            dash++;
    if (dash == 1)
        return 1;
    return 0;
}

void connect_node_with_str (node_room **all_rooms, char *str, int nmb_rooms)
{
    int size_str = my_strlen(str) + 1, i = 0, j;
    char *room1_name = malloc(sizeof(char) * size_str);
    my_memset(room1_name, size_str, '\0');
    for (j = 0; str[j] && str[j] != '-'; j++) {
        room1_name[i++] = str[j];
    }
    str += j + 1;
    node_room *room1 = NULL;
    for (int a = 0; a < nmb_rooms; a++) {
        // my_printf("on check %s avec %s\n", room1_name, all_rooms[a]->name);
        if (!my_strvcmp(room1_name, all_rooms[a]->name)) {
            room1 = all_rooms[a];
            break;
        }
    }
    char *room2_name = malloc(sizeof(char) * size_str);
    my_memset(room2_name, size_str, '\0');
    i = 0;
    for (j = 0; str[j] && str[j] != '-'; j++) {
        room2_name[i] = str[j];
    }
    node_room *room2 = NULL;
    for (int a = 0; a < nmb_rooms; a++) {
        // my_printf("on check %s avec %s\n", room2_name, all_rooms[a]->name);
        if (!my_strvcmp(room2_name, all_rooms[a]->name)) {
            room2 = all_rooms[a];
            break;
        }
    }
    if (!room1_name[0] || !room2_name[0]) {
        // my_printf("room non trouvée\n");
        free(room1_name);
        free(room2_name);
        return;
    }
    // my_printf("tunnel : %s - %s\n", room1_name, room2_name);
    free(room1_name);
    free(room2_name);
    connect_node(room1, room2);
}

node_room **complete_according_to_file (char **file, int *nmb_rooms)
{
    int nmb_fourmis = my_getnbr(*file), i;
    node_room **all_rooms = NULL;
    (*nmb_rooms) = 0;
    int file_type;
    for (i = 1; file[i]; i++) {
        if ((file_type = is_a_room(file[i])) == 1)
            all_rooms = add_room_in_list(all_rooms, file[i], (*nmb_rooms)++);
        else if (file_type == 2)
            break;
    }
    // my_printf("\nnmb de rooms : %d\n", (*nmb_rooms));
    int connections = 0;
    for (i = i; file[i]; i++) {
        if ((file_type = is_a_tunnel(file[i]))) {
            // my_printf("plus 1\n");
            connect_node_with_str(all_rooms, file[i], (*nmb_rooms));
            connections++;
        }
    }
    // my_printf("\nnmb de tunnels : %d\n", connections);
    // my_printf("\nend : %s\nstart : %s\n", end, start);
    return all_rooms;
}

// TODO verif que 2 rooms n'aient pas le même nom

// my_isdidgit(char)
//  = malloc(sizeof(node_room *));



// char *start, *end;
// for (i = 0; file[i]; i++)
//     if (!my_strcmp(file[i], "##start"))
//         start = file[i + 1];
// while (start[0] == '#')
//     start = file[i++];

// for (i = 0; file[i]; i++)
//     if (!my_strcmp(file[i], "##end"))
//         end = file[i + 1];
// while (end[0] == '#')
//     end = file[i++];

