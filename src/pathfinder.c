/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** pathfinder
*/

#include "my.h"
#include "ant.h"

path_t *add_cell(path_t *old, char *name)
{
    path_t *cell = malloc(sizeof(path_t));
    old->next = cell;
    cell->back = old;
    cell->link = malloc(sizeof(tunnel_t));
    cell->link->next = NULL;
    cell->link->back = NULL;
    cell->link->cell = NULL;
    cell->link_map = NULL;
    cell->next = NULL;
    cell->name = name;
    cell->weight = -1;
    return cell;
}

path_t *create_node(char *name)
{
    path_t *cell = malloc(sizeof(path_t));
    cell->back = NULL;
    cell->link = malloc(sizeof(tunnel_t));
    cell->link->next = NULL;
    cell->link->back = NULL;
    cell->link->cell = NULL;
    cell->link_map = NULL;
    cell->next = NULL;
    cell->name = name;
    cell->weight = -1;
    return cell;
}

void solver(path_t *node, int weight)
{
    if (node && node->weight == -1) {
        node->weight = weight;
        tunnel_t *temp = node->link;
        while (temp) {
            solver(temp->cell, weight + 1);
            temp = temp->next;
        }
    }
}

void pathfinder(ant_t *ant)
{
    antman_t *anthill = malloc(sizeof(antman_t));
    char *s_start = ant->l_start->head->name;
    char *s_room = NULL;
    anthill->link_node = create_node(s_start);
    room_t *temp = ant->l_room->head;
    path_t *temp2 = anthill->link_node;
    while (temp) {
        s_room = temp->name;
        temp2 = add_cell(temp2, s_room);
        temp = temp->next;
    }
    char *s_end = ant->l_end->head->name;
    temp2 = add_cell(temp2, s_end);
    path_init(anthill->link_node, ant);
    temp2 = anthill->link_node;
    solver(temp2, 0);
    display_all(anthill->link_node);
    freeall(anthill);
    return;
}
