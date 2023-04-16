/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** rc_strlen
*/

#include "ant.h"

int rc_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++);
    return i;
}
