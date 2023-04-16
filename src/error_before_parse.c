/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** error_multiple
*/

#include "ant.h"
#include <stddef.h>
#include <stdlib.h>

int is_a_room(char *room)
{
    int pos = 0;
    char **tab = NULL;

    for (pos = 0; room[pos] != ' ' && room[pos] != '\0'; pos++);
    if (room[pos] == '\0')
        return 1;
    tab = my_str_to_word_array(room, ' ');
    if (tab[3] != NULL)
        return 1;
    if (my_str_isnum(tab[1]) != 0 && my_str_isnum(tab[2]) != 0)
        return 1;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    return 0;
}

int is_a_pipe(char *pipe)
{
    int pos = 0;
    char **tab = NULL;

    tab = my_str_to_word_array(pipe, '-');
    if (tab[1] == NULL)
        return 1;
    if (tab[2] != NULL)
        return 1;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    return 0;
}

int check_multi_cmd(ant_t *ant, char *cmd)
{
    int count = 0;

    for (int i = 0; ant->input[i] != NULL; i++) {
        if (rc_strcmp(ant->input[i], cmd) == 0)
            count++;
    }
    if (count != 1)
        return 84;
    return 0;
}

int check_error_before(ant_t *ant)
{
    if (check_multi_cmd(ant, "##start\n") != 0)
        return 84;
    if (check_multi_cmd(ant, "##end\n") != 0)
        return 84;
    if (check_all_room(ant) != 0)
        return 84;
    if (ant->ant <= 0)
        return 84;
    return 0;
}
