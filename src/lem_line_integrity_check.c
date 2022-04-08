/*
** EPITECH PROJECT, 2022
** B-CPE-200-MAR-2-1-lemin-niels.ouvrard
** File description:
** lem_line_integrity_check
*/

#include "lem_header.h"
#include "my.h"


int is_there_comment(char *line)
{
    while (*line != 0 && *line == ' ')
        line++;
    if (*line == '#')
        return 1;
    return 0;
}

int is_there_command(char *line)
{
    if ((line[0] != 0 && line[1] != 0) && (line[0] == '#' && line[1] == '#'))
        return 1;
    return 0;
}

int check_tunnel_definition(char *line)
{
    if (*line == 0)
        return 0;
    while (my_isalphanum(*line) && *line != 0)
        line++;
    if (*line != '-')
        return 0;
    else
        line++;
    while (my_isalphanum(*line) && *line != 0)
        line++;
    if (*line != 0 && !is_there_comment(line))
        return 0;
    return 1;
}

int check_room_definition(char *line)
{
    if (*line == 0)
        return 0;
    while (my_isalphanum(*line) && *line != 0)
        line++;
    if (*line != ' ')
        return 0;
    else
        line++;
    while (my_isdidgit(*line) && *line != 0)
        line++;
    if (*line != ' ')
        return 0;
    else
        line++;
    while (my_isdidgit(*line) && *line != 0)
        line++;
    if (*line != 0 && !is_there_comment(line))
        return 0;
    return 1;
}

int check_ant_number(char *line)
{
    if (*line == 0) {
        return 0;
    }
    while (my_isdidgit(*line))
        line++;
    if (*line != 0 && !is_there_comment(line))
        return 0;
    return 1;
}
