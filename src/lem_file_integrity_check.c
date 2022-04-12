/*
** EPITECH PROJECT, 2022
** B-CPE-200-MAR-2-1-lemin-niels.ouvrard
** File description:
** lem_file_integrity_check
*/

#include "lem_header.h"
#include "my.h"

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
    if (state != TUNNEL)
        return -1;
    while (state == COMMENT || state == TUNNEL)
        state = get_line_identity(*(++file));
    if (state != MYEOF || (start != 1 || end != 1))
        return -1;
    return 0;
}

int file_integrity_check2(char **file, int state, int start, int end)
{
    while (state == COMMAND || state == COMMENT || state == ROOM) {
        if (state == COMMAND && !my_strcmp(*file, "##start")) {
            if (get_line_identity(file[1]) != ROOM)
                return -1;
            start++;
        }
        if (state == COMMAND && !my_strcmp(*file, "##end")) {
            if (get_line_identity(file[1]) != ROOM)
                return -1;
            end++;
        }
        state = get_line_identity(*(++file));
    }
    return file_integrity_check3(file, state, start, end);
}

int file_integrity_check(char **file)
{
    int state = get_line_identity(*file), start = 0, end = 0;
    while (state == COMMENT || state == ANT) {
        if (state == ANT)
            break;
        state = get_line_identity(*(++file));
    }
    if (state != ANT)
        return -1;
    state = get_line_identity(*(++file));
    return file_integrity_check2(file, state, start, end);
}
