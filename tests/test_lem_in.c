/*
** EPITECH PROJECT, 2021
** test_my_strncpy.
** File description:
** test lem in
*/

#include <criterion/criterion.h>
#include "my.h"
#include "lem_header.h"

int lem_in(void);

Test(lem_in , copy_string_in_empty_array)
{
    int output_lem_in = lem_in();
    cr_assert(output_lem_in == 0);
}
