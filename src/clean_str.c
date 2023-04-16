/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** clean_str
*/

#include "ant.h"
#include <unistd.h>
#include <stdlib.h>

char *clean_str(char *str)
{
    char *res = malloc(sizeof(char) * rc_strlen(str) + 1);
    int i = 0;

    for (i = 0; str[i] == ' ' && str[i] != '\t'; i++);
    for (int j = 0; str[i + 1] != '\0'; i++) {
        (str[i] == '\t') ? str[i] = ' ' : i;
        (str[i] != ' ') ? (res[j] = str[i], j++) : i;
        (str[i] == ' ' && str[i + 1] != ' ') ? (res[j] = ' ', j++) : i;
        res[j] = '\0';
    }
    return res;
}
