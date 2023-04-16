/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** list_to_tab
*/

#include <stdlib.h>
#include "ant.h"

int size_list(list_t *list)
{
    int i = 0;

    for (link_t *pos = list->first; pos != NULL; pos = pos->next, i++);
    return i;
}

void list_to_tab(ant_t *ant)
{
    int i = 0;
    int size = size_list(ant->list);

    ant->input = malloc(sizeof(char *) * (size + 1));
    for (link_t *pos = ant->list->first; pos != NULL; pos = pos->next, i++) {
        ant->input[i] = malloc(sizeof(char) * (rc_strlen(pos->data) + 1));
        ant->input[i] = rc_strdup(pos->data);
    }
    ant->input[size] = NULL;
}
