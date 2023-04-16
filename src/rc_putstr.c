/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** rc_putstr
*/

#include "ant.h"

void rc_putstr(char *str)
{
    for (int i = 0; str[i]; i++)
        rc_putchar(str[i]);
}
