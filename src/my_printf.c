/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** mini_printf
*/

#include "ant.h"
#include <stdarg.h>

int my_printf(char *format, ...)
{
    va_list ap;
    int count = 0;
    int len = rc_strlen(format);

    va_start(ap, format);
    for (int i = 0; i < len; i++) {
        (format[i] == '%') ? (i++,
        (format[i] == 'c') ? (rc_putchar((char)va_arg(ap, int)), count++) : 0,
        (format[i] == 'd' || format[i] == 'i') ?
        rc_putnbr(va_arg(ap, int)) : 0,
        (format[i] == 's') ? rc_putstr(va_arg(ap, char *)) : 0,
        (format[i] == '%') ? (rc_putchar('%'), count++) : 0)
        : rc_putchar(format[i]);
        (format[i - 1] != '%' && format[i - 1] >= ' ') ? count++ : count;
    }
    va_end(ap);
    return count;
}
