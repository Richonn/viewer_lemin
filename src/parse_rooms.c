/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** parse_rooms
*/

#include "ant.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int set_start(ant_t *ant, int pos)
{
    char **tab = NULL;

    if (ant->l_start->head != NULL)
        return (pos + 1);
    pos += 1;
    tab = my_str_to_word_array(ant->input[pos], ' ');
    push_in_rlist(ant->l_start, tab);
    return (pos + 1);
}

int set_room(ant_t *ant, int pos)
{
    char **tab = NULL;

    if (ant->input[pos] == NULL) {
        return pos;
    }
    for (; is_a_room(ant->input[pos]) != 0; pos++) {
        if (rc_strcmp(ant->input[pos], "##end\n") == 0) {
            return pos;
        }
    }
    tab = my_str_to_word_array(ant->input[pos], ' ');
    put_in_rlist(ant->l_room, tab);
    return (pos + 1);
}

int set_end(ant_t *ant, int pos)
{
    char **tab = NULL;

    if (ant->input[pos] == NULL)
        return pos;
    pos += 1;
    tab = my_str_to_word_array(ant->input[pos], ' ');
    put_in_rlist(ant->l_end, tab);
    return (pos + 1);
}

int set_pipe(ant_t *ant, int pos)
{
    char **tab = NULL;
    int len = rc_strlen(ant->input[pos]) - 1;

    if (ant->input[pos][len] == '\n')
        ant->input[pos][len] = '\0';
    tab = my_str_to_word_array(ant->input[pos], '-');
    put_in_plist(ant->l_pipe, tab);
    return (pos + 1);
}

void parse_rooms(ant_t *ant)
{
    int pos = 1;
    int len = 0;

    init_plist(ant);
    init_rlist(ant);
    for (; ant->input[len] != NULL; len++);
    while (pos < len) {
        if (rc_strcmp(ant->input[pos], "##start\n") == 0)
            pos = set_start(ant, pos);
        if (is_a_room(ant->input[pos]) == 0)
            pos = set_room(ant, pos);
        if (rc_strcmp(ant->input[pos], "##end\n") == 0)
            pos = set_end(ant, pos);
        if (is_a_pipe(ant->input[pos]) == 0)
            pos = set_pipe(ant, pos);
    }
    return;
}
