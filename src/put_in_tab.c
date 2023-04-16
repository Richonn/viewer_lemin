/*
** EPITECH PROJECT, 2023
** bonus_lemin
** File description:
** put_in_tab
*/

#include <stdio.h>
#include <stdlib.h>
#include "ant.h"

int set_size(int max, int min)
{
    if (max > 0 && min < 0)
        return max + (min * -1);
    if (max < 0 && min < 0)
        return (max - min) * -1;
    if (max > 0 && min == 0)
        return max + 1;
    return max + min;
}

void create_tab(ant_t *ant)
{
    int i = 0;
    int j = 0;
    int size_x = set_size(ant->max_x, ant->min_x);
    int size_y = set_size(ant->max_y, ant->min_y) + 1;

    ant->map = malloc(sizeof(char *) * (size_y) + 1);
    for (; i != size_y; i++) {
        ant->map[i] = malloc(sizeof(char) * size_x + 1);
        for (j = 0; j != size_x; j++)
            ant->map[i][j] = '-';
        ant->map[i][j] = '\0';
    }
    ant->map[i] = NULL;
    print_line_tab(ant->map);
}

void put_start_end(ant_t *ant)
{
    int i = 0;
    int j = 0;

    for (i = 0; i != ant->l_start->head->y; i++);
    for (j = 0; j != ant->l_start->head->x; j++);
    ant->map[i][j] = 'S';
    for (i = 0; i != ant->l_end->head->y; i++);
    for (j = 0; j != ant->l_end->head->x; j++);
    ant->map[i][j] = 'E';
}

void put_in_tab(ant_t *ant)
{
    int i = 0;
    int j = 0;

    create_tab(ant);
    put_start_end(ant);
    for (room_t *pos = ant->l_room->head; pos != NULL; pos = pos->next) {
        for (i = 0; i != pos->y; i++);
        for (j = 0; j != pos->x; j++);
        ant->map[i][j] = pos->name[0];
    }
    print_line_tab(ant->map);
}
