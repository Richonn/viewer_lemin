/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** check_same_pos
*/

#include "ant.h"
#include <stddef.h>
#include <stdlib.h>

int *give_room_coord(char *all_room)
{
    int *room_coord = malloc(sizeof(int) * 3);
    int pos = 0;

    for (pos = 0; all_room[pos] != ' '; pos++);
    room_coord[0] = rc_getnbr(&all_room[pos]);
    for (pos += 1; all_room[pos] != ' '; pos++);
    room_coord[1] = rc_getnbr(&all_room[pos]);
    room_coord[2] = 0;
    return room_coord;
}

int find_double_coor(ant_t *ant, int *coord)
{
    lroom_t *listing = listing_rooms(ant);
    room_t *room = NULL;

    room = find_in_rlist_coor(listing, coord[0], coord[1]);
    if (room == NULL || room->next == NULL)
        return 0;
    room = room->next;
    while (room != NULL) {
        if (coord[0] == room->x && coord[1] == room->y)
            return 84;
        room = room->next;
    }
    return 0;
}

int check_same_pos(ant_t *ant)
{
    int count = 0;
    int *coord = NULL;

    for (int i = 0; ant->input[i] != NULL && count == 0; i++) {
        if (is_a_room(ant->input[i]) == 0) {
            coord = give_room_coord(ant->input[i]);
            count = find_double_coor(ant, coord);
        }
    }
    return count;
}
