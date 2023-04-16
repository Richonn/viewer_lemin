/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** add_to_rlist
*/

#include "ant.h"
#include <unistd.h>
#include <stdlib.h>

void put_in_rlist(lroom_t *l_room, char **tab)
{
    room_t *room = malloc(sizeof(room_t));
    room_t *tmp = l_room->head;

    room->name = rc_strdup(tab[0]);
    room->x = rc_getnbr(tab[1]);
    room->y = rc_getnbr(tab[2]);
    room->next = NULL;
    if (tmp == NULL) {
        l_room->head = room;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = room;
    return;
}

void push_in_rlist(lroom_t *l_room, char **tab)
{
    room_t *room = malloc(sizeof(room_t));

    room->name = rc_strdup(tab[0]);
    room->x = rc_getnbr(tab[1]);
    room->y = rc_getnbr(tab[2]);
    room->next = l_room->head;
    l_room->head = room;
    return;
}

void display_rlist(lroom_t *l_room)
{
    room_t *room = l_room->head;

    while (room != NULL) {
        my_printf("name: %s x:%d y:%d\n", room->name, room->x, room->y);
        room = room->next;
    }
}

void init_rlist(ant_t *ant)
{
    ant->l_start = malloc(sizeof(lroom_t));
    ant->l_start->head = NULL;
    ant->l_end = malloc(sizeof(lroom_t));
    ant->l_end->head = NULL;
    ant->l_room = malloc(sizeof(lroom_t));
    ant->l_room->head = NULL;
}
