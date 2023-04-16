/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** add_to_plist
*/

#include "ant.h"
#include <unistd.h>
#include <stdlib.h>

void put_in_plist(lpipe_t *l_pipe, char **tab)
{
    pipe_t *pipe = malloc(sizeof(pipe_t));
    pipe_t *tmp = l_pipe->head;

    pipe->from = rc_strdup(tab[0]);
    pipe->to = rc_strdup(tab[1]);
    pipe->next = NULL;
    if (tmp == NULL) {
        l_pipe->head = pipe;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = pipe;
    return;
}

void push_in_plist(lpipe_t *l_pipe, char **tab)
{
    pipe_t *pipe = malloc(sizeof(pipe_t));

    pipe->from = rc_strdup(tab[0]);
    pipe->to = rc_strdup(tab[1]);
    pipe->next = l_pipe->head;
    l_pipe->head = pipe;
    return;
}

void display_plist(lpipe_t *l_pipe)
{
    pipe_t *pipe = l_pipe->head;

    while (pipe != NULL) {
        my_printf("from:%s_to:%s\n", pipe->from, pipe->to);
        pipe = pipe->next;
    }
}

void init_plist(ant_t *ant)
{
    ant->l_pipe = malloc(sizeof(lroom_t));
    ant->l_pipe->head = NULL;
}
