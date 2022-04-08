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
    int n = 0b000;
    if (*line == 0)
        return 0;
    for (; my_isalphanum(*line) && *line != 0; line++, n = n | 0b01);
    if (*line != '-')
        return 0;
    else
        line++;
    for (; my_isalphanum(*line) && *line != 0; line++, n = n | 0b10);
    if ((*line != 0 && !is_there_comment(line)) || (n & 0b11) != 0b11)
        return 0;
    return 1;
}

int check_room_definition(char *line)
{
    int n = 0b000;
    if (*line == 0)
        return 0;
    for (; my_isalphanum(*line) && *line != 0; line++, n = n | 0b001);
    if (*line != ' ')
        return 0;
    else
        line++;
    for (; my_isdidgit(*line) && *line != 0; line++, n = n | 0b010);
    if (*line != ' ')
        return 0;
    else
        line++;
    for (; my_isdidgit(*line) && *line != 0; line++, n = n | 0b100);
    if ((*line != 0 && !is_there_comment(line)) || (n & 0b111) != 0b111)
        return 0;
    return 1;
}

int check_ant_number(char *line)
{
    int n = 0b0;
    if (*line == 0)
        return 0;
    for (; my_isdidgit(*line); line++, n = n | 0b1);
    if ((*line != 0 && !is_there_comment(line)) || (n & 0b1) != 0b1)
        return 0;
    return 1;
}
