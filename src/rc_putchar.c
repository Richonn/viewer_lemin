/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** rc_putchar
*/

#include <unistd.h>

void rc_putchar(char c)
{
    write(1, &c, 1);
}
