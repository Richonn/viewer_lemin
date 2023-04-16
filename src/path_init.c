/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** path_init
*/

#include "my.h"
#include "ant.h"
#include <stdio.h>

path_t *path_search(path_t *temp, char *name)
{
    while (temp) {
        if (rc_strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

tunnel_t *tunnel_init(tunnel_t *old)
{
    tunnel_t *node = malloc(sizeof(tunnel_t));
    node->back = old;
    node->next = NULL;
    return node;
}

void node_end(tunnel_t *node, path_t *tamp, char *name)
{
    if (node->back == NULL && node->next == NULL) {
        node->cell = path_search(tamp, name);
        node->next = tunnel_init(node);
        return;
    } else {
        while (node->next != NULL)
            node = node->next;
        node->next = tunnel_init(node);
        node->next->cell = path_search(tamp, name);
    }

}

void path_scan(path_t *temp, pipe_t *tmp, path_t *node)
{
    path_t *tamp = node;
    if (rc_strcmp(temp->name, tmp->from) == 0) {
        tunnel_t *tomp = temp->link;
        node_end(tomp, tamp, tmp->to);
    }
    tamp = node;
    if (rc_strcmp(temp->name, tmp->to) == 0) {
        tunnel_t *tomp = temp->link;
        node_end(tomp, tamp, tmp->from);
    }
}

void path_init(path_t *node, ant_t *ant)
{
    pipe_t *tmp = ant->l_pipe->head;
    while (tmp->next) {
        path_t *temp = node;
        my_printf("%s <-> ", tmp->from);
        my_printf("%s\n", tmp->to);
        while (temp) {
            path_scan(temp, tmp, node);
            temp = temp->next;
        }
        tmp = tmp->next;
    }
    return;
}
