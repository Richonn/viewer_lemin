/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** add_node
*/

#include <stdlib.h>
#include "ant.h"

void add_node(list_t *list, char *str)
{
    link_t *new = malloc(sizeof(link_t));
    link_t *tmp = list->first;

    new->data = rc_strdup(str);
    new->next = NULL;
    if (list->first == NULL) {
        list->first = new;
        return;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;
}
