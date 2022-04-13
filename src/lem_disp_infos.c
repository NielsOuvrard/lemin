/*
** EPITECH PROJECT, 2022
** lem_in
** File description:
** lem_in
*/

#include "my.h"
#include "lem_header.h"

void disp_all_infos_2 (char *str)
{
    if (str[0] == '#' && str[1] == '#') {
        my_putstr(str);
        my_putchar('\n');
        return;
    }
    for (int j = 0; str[j]; j++) {
        if (j > 0 && str[j] == '#') {
            my_putchar('\n');
            return;
        } else if (str[j] == '#') {
            return;
        }
        my_putchar(str[j]);
    }
    my_putchar('\n');
}

void disp_all_infos_according_to_array (char **array)
{
    my_printf("#number_of_ants\n%s\n#rooms\n", array[0]);
    bool tunnel = false;
    for (int i = 1; array[i]; i++) {
        if (!tunnel && is_a_tunnel(array[i])) {
            tunnel = true;
            my_putstr("#tunnels\n");
        }
        disp_all_infos_2(array[i]);
    }
    my_putstr("#moves");
}
