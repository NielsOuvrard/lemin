/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** lem_in
*/

#include "my.h"
#include "lem_header.h"

int main (int ac, char **av)
{
    char **array = file_give_to_array();
    my_show_word_array(array);
    free_my_arr(array);
    return 0;
}
