/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** rc_punbr
*/

#include "ant.h"

int rc_putnbr(int nb)
{
    int size;

    if (nb < 0)
        nb = -nb;
    if (nb < 10) {
        rc_putchar(nb + 48);
        return 1;
    }
    if (nb > 9) {
        size = rc_putnbr(nb / 10);
        rc_putchar(nb % 10 + 48);
        return 1 + size;
    }
    return 0;
}
