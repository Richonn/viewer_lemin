/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** init_struct
*/

#include <stdio.h>
#include <stdlib.h>
#include "ant.h"

int init_struct(ant_t *ant)
{
    ant->brut = NULL;
    ant->error = 0;
    ant->list = malloc(sizeof(link_t));
    ant->list->first = NULL;
    read_input(ant);
    if (ant->list->first == NULL)
        return 84;
    list_to_tab(ant);
    return 0;
}
