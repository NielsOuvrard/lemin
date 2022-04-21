/*
** EPITECH PROJECT, 2022
** B-CPE-200-MAR-2-1-lemin-niels.ouvrard
** File description:
** lem_file_integrity_check
*/

#include "lem_header.h"
#include "my.h"

void my_print_until(char *str, char stop, bool newline)
{
    int i;
    for (i = 0; str[i] != 0 && str[i] != stop; i++);
    str[i] = 0;
    my_trimchar(str, " ", 'e');
    write(1, str, my_strlen(str));
    if (newline == true)
        write(1, "\n", 1);
}

int get_line_identity(char *line)
{
    if (line == NULL)
        return MYEOF;
    if (is_there_command(line))
        return COMMAND;
    if (is_there_comment(line))
        return COMMENT;
    if (check_room_definition(line))
        return ROOM;
    if (check_tunnel_definition(line))
        return TUNNEL;
    if (check_ant_number(line))
        return ANT;
    return UNKNOWN;
}

int file_integrity_check3(char **file, int state, int start, int end)
{
    my_printf("#tunnels\n");
    if (state != TUNNEL)
        return -1;
    while (state == COMMENT || state == TUNNEL) {
        if (state == TUNNEL)
            my_print_until(*file, '#', true);
        state = get_line_identity(*(++file));
    }
    if (state != MYEOF || (start != 1 || end != 1))
        return -1;
    my_printf("#moves");
    return 0;
}

int file_integrity_check2(char **file, int state, int start, int end)
{
    while (state == COMMAND || state == COMMENT || state == ROOM) {
        if (state == COMMAND && !my_strcmp(*file, "##start")) {
            my_printf("##start\n");
            if (get_line_identity(file[1]) != ROOM || ++start > 1)
                return -1;
        }
        if (state == COMMAND && !my_strcmp(*file, "##end")) {
            my_printf("##end\n");
            if (get_line_identity(file[1]) != ROOM || ++end > 1)
                return -1;
        }
        if (state == ROOM)
            my_print_until(*file, '#', true);
        state = get_line_identity(*(++file));
    }
    if (state != TUNNEL)
        return -1;
    return file_integrity_check3(file, state, start, end);
}

int file_integrity_check(char **file)
{
    my_printf("#number_of_ants\n");
    int state = get_line_identity(*file), start = 0, end = 0, ant = 0;
    if (state != COMMENT && state != ANT)
        return -1;
    while (state == COMMENT || state == ANT) {
        if (state == ANT && ++ant > 1) {
            return -1;
        }
        if (state == ANT)
            my_print_until(*file, '#', true);
        state = get_line_identity(*(++file));
    }
    if (state != COMMAND && state != COMMENT && state != ROOM)
        return -1;
    my_printf("#rooms\n");
    return file_integrity_check2(file, state, start, end);
}
