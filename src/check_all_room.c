/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** check_all_room
*/

#include "ant.h"

int check_all_room(ant_t *ant)
{
    int count = 0;

    for (int i = 0; ant->input[i]; i++) {
        if (rc_strcmp(ant->input[i],"##start\n") == 0 ||
        rc_strcmp(ant->input[i],"##end\n") == 0) {
            (is_a_room(ant->input[i + 1]) != 0) ? count++ : 0;
        }
    }
    if (count != 0)
        return 84;
    return 0;
}
