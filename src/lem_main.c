/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** lem_in
*/

#include "my.h"
#include "lem_header.h"

void free_alls_rooms (node_room **rooms)
{
    for (int x = 0; rooms[x]; x++) {
        free(rooms[x]->name);
        free(rooms[x]->tunnel);
        free(rooms[x]);
    }
    free(rooms);
}

int lem_in(void)
{
    int return_value = 0;
    char **array = file_give_to_array();
    if (file_integrity_check(array) == -1)
        return 84;
    node_room **rooms = complete_according_to_file(array);
    if (add_type(rooms, array) == -1)
        return 84;
    if (return_value = do_pathfinding(rooms))
        my_putchar('\n');
    free_alls_rooms(rooms);
    free_my_arr(array);
    return return_value;
}

int main (int ac, char **av)
{
    return lem_in();
}

// * mettre NULL à la fin
// check si il y a un iquement le nombre de fourmi / same for the room list
// check si chemin existe
// check qu'il n'y ai pas de merde au milieu
// (penser à afficher tous ce qui est valide avant)
// si pas de liaisons affiché tout sauf la partie #moves
