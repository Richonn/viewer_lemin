/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** print_res
*/

#include <stdlib.h>
#include "ant.h"

void print_room(lroom_t *l_room)
{
    my_printf("#rooms\n");
    for (room_t *pos = l_room->head; pos != NULL; pos = pos->next)
        my_printf("%s %d %d\n", pos->name, pos->x, pos->y);
}

void print_end(lroom_t *l_end)
{
    my_printf("##end\n");
    for (room_t *pos = l_end->head; pos != NULL; pos = pos->next)
        my_printf("%s %d %d\n", pos->name, pos->x, pos->y);
}

void print_tunnels(lpipe_t *l_pipe)
{
    my_printf("#tunnels\n");
    for (pipe_t *pos = l_pipe->head; pos != NULL; pos = pos->next)
        my_printf("%s-%s\n", pos->from, pos->to);
}

void print_res(ant_t *ant)
{
    my_printf("#number_of_ants\n%d\n", ant->ant);
    (ant->l_room->head != NULL) ? print_room(ant->l_room) :
    my_printf("#rooms\n");
    my_printf("##start\n%s ", ant->l_start->head->name);
    my_printf("%d %d\n", ant->l_start->head->x, ant->l_start->head->y);
    print_end(ant->l_end);
    print_tunnels(ant->l_pipe);
}
