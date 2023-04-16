/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** print_tab
*/

#include "ant.h"

void print_line_tab(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        rc_putstr(tab[i]);
        rc_putchar('\n');
    }
}

void print_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        rc_putstr(tab[i]);
}
