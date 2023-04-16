/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** my_find_in_rlist
*/

#include "ant.h"
#include <stddef.h>

room_t *find_in_rlist_name(lroom_t *list, char *to_find)
{
    room_t *room = list->head;

    while (rc_strcmp(room->name, to_find) != 0) {
        room = room->next;
        if (room == NULL)
            return 0;
    }
    if (room == NULL)
        return NULL;
    return room;
}

room_t *find_in_rlist_coor(lroom_t *list, int x_find, int y_find)
{
    room_t *room = list->head;

    while (room != NULL) {
        if (x_find == room->x && y_find == room->y)
            return room;
        room = room->next;
    }
    if (room == NULL)
        return NULL;
    return room;
}
