/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** read_input
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ant.h"

int is_alpha_num(char c)
{
    if (c >= '1' && c <= '9')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c == '.')
        return 1;
    return 0;
}

char *del_space(char *str)
{
    int i = 0;
    int j = 0;
    char *new = malloc(sizeof(char) * rc_strlen(str) + 1);

    for (; is_alpha_num(str[i]) != 1; i++)
        if (str[i] == '\0')
            return 0;
    for (; is_alpha_num(str[i]) == 0; i++);
    for (; str[i]; i++) {
        for (; is_alpha_num(str[i]) == 0 &&
        is_alpha_num(str[i + 1]) == 0 && str[i + 1] != '\0'; i++);
        new[j] = str[i];
        j++;
    }
    new[j] = '\0';
    return new;
}

int is_line_comment(char *str)
{
    if (str[0] == '#' && str[1] != '#')
        return 1;
    return 0;
}

char *rm_comment(char *str)
{
    int a = 0;
    int len = 0;
    char *new = malloc(sizeof(char) * rc_strlen(str));

    for (int i = 0; str[i] != '#'; i++, len++);
    for (; a != len; a++)
        new[a] = str[a];
    new[a] = '\n';
    new = del_space(new);
    return new;
}

int read_input(ant_t *ant)
{
    size_t size;

    for (; getline(&ant->brut, &size, stdin) != -1; ) {
        if (is_line_comment(ant->brut) == 1)
            continue;
        if (is_cmd_cmm(ant->brut) == 1)
            ant->brut = rm_comment(ant->brut);
        add_node(ant->list, ant->brut);
    }
    free(ant->brut);
    return 0;
}
