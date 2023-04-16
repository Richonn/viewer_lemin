/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** my_str_to_word_array
*/

#include "ant.h"
#include <unistd.h>
#include <stdlib.h>

int is_alpha(char c, char stop)
{
    if (c == stop)
        return 0;
    return 1;
}

int countword(char const *str, char stop)
{
    int k = 0;

    if (is_alpha(str[0], stop) != 0)
        k++;
    for (int i = 0; str[i] != '\0'; i++) {
        (is_alpha(str[i], stop) == 0 && is_alpha(str[i + 1], stop) != 0) ?
        k++ : i;
    }
    return k;
}

char *check_string(char *str, char c, int len, char stop)
{
    if (is_alpha(c, stop) != 0)
        str = malloc(sizeof(char) * len + 1);
    return str;
}

char **my_str_to_word_array(char *str, char stop)
{
    int word = countword(str, stop);
    char **tab = malloc(sizeof(char *) * (word + 1));
    int k = 0;

    if (word == 0) {
        tab[0] = NULL;
        return tab;
    }
    word = rc_strlen(str);
    for (int i = 0, len = 0; i <= word; i++) {
        for (int n = i; str[n] && is_alpha(str[n], stop) != 0; len++, n++);
        tab[k] = check_string(tab[k], str[i], len, stop);
        for (int j = 0; str[i] && is_alpha(str[i], stop) != 0; i++, j++) {
            tab[k][j] = str[i];
            tab[k][j + 1] = '\0';
        }
        (is_alpha(str[i - 1], stop) != 0 && i != 0) ? k++ : k;
    }
    tab[k] = NULL;
    return tab;
}
