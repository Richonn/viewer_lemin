/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** parser
*/

#include <stdio.h>
#include "ant.h"

int check_pipe(ant_t *ant)
{
    for (int i = 0; ant->input[i]; i++)
        if (is_a_pipe(ant->input[i]) == 0)
            return 0;
    return 84;
}

int check_input(ant_t *ant)
{
    if (ant->ant <= 0)
        return 84;
    if (check_error_before(ant) != 0)
        return 84;
    if (check_same_name(ant) != 0)
        return 84;
    if (check_same_pos(ant) != 0)
        return 84;
    if (check_pipe(ant) != 0)
        return 84;
    if (check_valid_pipe(ant) != 0)
        return 84;
    return 0;
}

void recup_values_max(ant_t *ant)
{
    ant->max_x = ant->l_start->head->x;
    if (ant->l_end->head->x > ant->max_x)
        ant->max_x = ant->l_end->head->x;
    for (room_t *pos = ant->l_room->head; pos != NULL; pos = pos->next)
        if (pos->x > ant->max_x)
            ant->max_x = pos->x;
    ant->max_y = ant->l_start->head->y;
    if (ant->l_end->head->y > ant->max_y)
        ant->max_y = ant->l_end->head->y;
    for (room_t *pos = ant->l_room->head; pos != NULL; pos = pos->next)
        if (pos->y > ant->max_y)
            ant->max_y = pos->y;
}

void recup_values_min(ant_t *ant)
{
    ant->min_x = ant->l_start->head->x;
    if (ant->l_end->head->x < ant->min_x)
        ant->min_x = ant->l_end->head->x;
    for (room_t *pos = ant->l_room->head; pos != NULL; pos = pos->next)
        if (pos->x < ant->min_x)
            ant->min_x = pos->x;
    ant->min_y = ant->l_start->head->y;
    if (ant->l_end->head->y < ant->min_y)
        ant->min_y = ant->l_end->head->y;
    for (room_t *pos = ant->l_room->head; pos != NULL; pos = pos->next)
        if (pos->y < ant->min_y)
            ant->min_y = pos->y;
}

int parser(ant_t *ant)
{
    int i = 0;

    if (is_cmd_cmm(ant->input[0]) == 0)
        ant->ant = rc_getnbr(ant->input[0]);
    else
        for (; ant->input[i][0] == '#'; i++);
    ant->ant = rc_getnbr(ant->input[i]);
    if (check_input(ant) != 0)
        ant->error = 1;
    parse_rooms(ant);
    recup_values_max(ant);
    recup_values_min(ant);
    return 0;
}
