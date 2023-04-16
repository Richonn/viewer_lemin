/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** check_valid_pipe
*/

#include "ant.h"
#include <stddef.h>

int mini_validate_pipe(ant_t *ant, char *pipe)
{
    char **tab = NULL;
    int val = rc_strlen(pipe);
    lroom_t *listing = listing_rooms(ant);
    room_t *room = NULL;

    if (pipe[val - 1] == '\n')
        pipe[val - 1] = '\0';
    tab = my_str_to_word_array(pipe, '-');
    if (rc_strcmp(tab[0], tab[1]) == 0)
        return 84;
    room = find_in_rlist_name(listing, tab[0]);
    if (room == NULL)
        return 84;
    room = find_in_rlist_name(listing, tab[1]);
    if (room == NULL)
        return 84;
    return 0;
}

int check_valid_pipe(ant_t *ant)
{
    int count = 0;

    for (int i = 0; ant->input[i] != NULL; i++) {
        if (is_a_pipe(ant->input[i]) == 0)
            count = mini_validate_pipe(ant, ant->input[i]);
        if (count != 0)
            return 84;
    }
    return 0;
}
