/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "ant.h"
#include "my.h"

int main(int ac, char **av)
{
    ant_t *ant;

    if (ac > 1)
        return 84;
    ant = malloc(sizeof(ant_t));
    if (init_struct(ant) == 84)
        return 84;
    parser(ant);
    check_error(ant);
    if (ant->error != 0) {
        print_res(ant);
        return 84;
    }
    print_res(ant);
    put_in_tab(ant);
    return 0;
}
