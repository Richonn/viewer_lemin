/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** path_free
*/

#include "my.h"
#include "ant.h"

void free_link(tunnel_t *node)
{
    while (node) {
        tunnel_t *temp = node;
        node = node->next;
        free(temp);
    }
}

void free_node(path_t *node)
{
    while (node) {
        path_t *temp = node;
        node = node->next;
        free(temp);
    }
}

void freeall(antman_t *anthill)
{
    path_t *temp = anthill->link_node;
    free_node(temp);
    free(anthill);
    return;
}
