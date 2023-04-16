/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** my_str_is_num
*/

#include "ant.h"

int my_str_isnum(char *str)
{
    int res = 0;
    int len = rc_strlen(str);

    if (len == 0)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        (str[i] < '0' || str[i] > '9') ? res++ : i;
        if (res != 0)
            return 0;
    }
    return 1;
}
