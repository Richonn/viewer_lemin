/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** path_display
*/

#include "my.h"
#include "ant.h"
#include <stdio.h>

void display_node(tunnel_t *link)
{
    tunnel_t *temp = link;
    while (temp) {
        if (temp->cell != NULL)
            my_printf("pipe : %s | ", temp->cell->name);
        temp = temp->next;
    }
}

void display_all(path_t *node)
{
    path_t *temp = node;
    while (temp) {
        my_printf("nom de salle : %s | ", temp->name);
        display_node(temp->link);
        my_printf("poids : %d\n", temp->weight);
        temp = temp->next;
    }
}
