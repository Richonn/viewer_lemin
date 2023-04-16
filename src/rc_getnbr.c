/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** rc_getnbr
*/

#include "ant.h"

int check_int(int nb, int neg, char *str, int i)
{
    unsigned int a = nb;

    a = a * 10 + str[i] - '0';
    if (a > 2147483647 && neg % 2 == 0)
        return 0;
    if (a > 2147483648 && neg % 2 != 0)
        return 0;
    return 1;
}

int rc_getnbr(char *str)
{
    long res = 0;
    int neg = 0;
    int i = 0;

    for (; str[i] < '0' || str[i] > '9'; i++)
        if (str[i] == '-')
            neg++;
    for (; str[i] >= '0' && str[i] <= '9' && str[i]; i++) {
        if (check_int(res, neg, str, i) == 0)
            return 0;
        res = res * 10 + str[i] - '0';
    }
    if (neg % 2 != 0)
        res = res * -1;
    return res;
}
