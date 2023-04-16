/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** check_error
*/

#include <stdio.h>
#include <stdlib.h>
#include "ant.h"

int is_cmd_cmm(char *str)
{
    for (int i = 0; str[i] != '\n'; i++) {
        if (str[i] == '#' && str[i + 1] != '#')
            return 1;
        if (str[i] == '#' && str[i + 1] == '#')
            return 2;
    }
    return 0;
}

int check_room_name(lroom_t *l_room)
{
    char *name;
    room_t *pos = l_room->head;

    name = rc_strdup(pos->name);
    for (pos = pos->next; pos != NULL; pos = pos->next) {
        if (rc_strcmp(pos->name, name) == 0) {
            free(name);
            return 1;
        }
        free(name);
        name = rc_strdup(pos->name);
    }
    free(name);
    return 0;
}

int check_error(ant_t *ant)
{
    if (ant->l_room->head != NULL)
        if (check_room_name(ant->l_room) != 0)
            ant->error = 1;
    return 0;
}
