/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** print_list
*/

#include <stdlib.h>
#include "ant.h"

void print_list(list_t *list)
{
    for (link_t *pos = list->first; pos != NULL; pos = pos->next)
        rc_putstr(pos->data);
}
