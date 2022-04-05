/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** lem_in
*/

#include "my.h"
#include "lem_header.h"

int get_nbrspe(char *yes, int *x)
{
    int res = 0, neg = 1;
    if (yes[*x] == '-') {
        neg = -1;
        (*x)++;
    }
    while (yes[*x] >= '0' && yes[*x] <= '9') {
        res = res * 10;
        res = res + (yes[*x] - 48);
        (*x)++;
    }
    res = res * neg;
    return res;
}

char *cur_name(char *str)
{   int x = 0, w = 0;
    for (; str[x] != ' '; x++);
    char *yes = malloc(sizeof (char) * (x + 1));
    for (; str[w] != ' '; w++)
        yes[w] = str[w];
    yes[w] = '\0';
    return yes;
}

char *get_name(char **arr, char *str)
{
    for (int x = 0; arr[x] != NULL ; x++) {
        if (my_strcmp(str, arr[x]) == 0) {
            return cur_name(arr[x + 1]);
        }
    }
}

void add_type(node_room **rooms, char **arr)
{
    char *st = get_name(arr, "##start");
    char *en = get_name(arr, "##end");
    int tot_fourm = my_getnbr(arr[0]);
    for (int x = 0; rooms[x] != NULL; x++) {
        if(my_strcmp(st, rooms[x]->name) == 0) {
            rooms[x]->type = 1;
            rooms[x]->fourmi = tot_fourm;
            continue;
        }
        if(my_strcmp(en, rooms[x]->name) == 0) {
            rooms[x]->type = 0;
            continue;
        }
        rooms[x]->type = 2;
    }
}

int lem_in(void)
{
    // ./lem_in < anthill_trivial
    char **array = file_give_to_array();
    my_show_word_array(array);
    int imb_rooms;
    node_room **rooms = complete_according_to_file(array, &imb_rooms);
    add_type(rooms, array);
    for (int x = 0; rooms[x] != NULL; x++) {
        printf("%s %d %d\n", rooms[x]->name, rooms[x]->type, rooms[x]->fourmi);
    }
    free_my_arr(array);
}

int main (int ac, char **av)
{
    return lem_in();
}
