/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** rc_strdup
*/

#include <stdlib.h>
#include "ant.h"

char *rc_strdup(char *src)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (rc_strlen(src) + 1));

    for (; src[i]; i++)
        str[i] = src[i];
    str[i] = '\0';
    return str;
}
