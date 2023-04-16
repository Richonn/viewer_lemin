/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** error_after_parse
*/

#include "ant.h"
#include <stddef.h>
#include <stdlib.h>

lroom_t *listing_rooms(ant_t *ant)
{
    lroom_t *listing = malloc(sizeof(lroom_t));
    int i = 0;
    char **tab = NULL;

    listing->head = NULL;
    for (; ant->input[i] != NULL && is_a_room(ant->input[i]) != 0; i++);
    tab = my_str_to_word_array(ant->input[i], ' ');
    push_in_rlist(listing, tab);
    i++;
    for (; ant->input[i] != NULL; i++) {
        if (is_a_room(ant->input[i]) == 0) {
            tab = my_str_to_word_array(ant->input[i], ' ');
            put_in_rlist(listing, tab);
        }
    }
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
    return listing;
}

char *give_room_name(char *all_room)
{
    char *room_name = NULL;
    int len = 0;

    for (len = 0; all_room[len] != ' '; len++);
    room_name = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
        room_name[i] = all_room[i];
    room_name[len] = '\0';
    return room_name;
}

int find_double(ant_t *ant, char *name)
{
    lroom_t *listing = listing_rooms(ant);
    room_t *room = NULL;

    room = find_in_rlist_name(listing, name);
    if (room == NULL || room->next == NULL)
        return 0;
    room = room->next;
    while (rc_strcmp(room->name, name) != 0) {
        room = room->next;
        if (room == NULL)
            return 0;
    }
    if (room != NULL)
        return 84;
    return 0;
}

int check_same_name(ant_t *ant)
{
    int count = 0;
    char *name = NULL;

    for (int i = 0; ant->input[i] != NULL && count == 0; i++) {
        if (is_a_room(ant->input[i]) == 0) {
            name = give_room_name(ant->input[i]);
            count = find_double(ant, name);
        }
    }
    return count;
}
