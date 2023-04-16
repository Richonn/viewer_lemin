/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** my
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "ant.h"

typedef struct antman {
    int **anthill;
    int *end;

    struct path *link_node;
} antman_t;

typedef struct tunnel {
    struct path *cell;
    struct tunnel *next;
    struct tunnel *back;
} tunnel_t;

typedef struct path {
    int weight;
    char *name;
    struct path *back;
    struct path *next;
    struct tunnel *link;
    struct antman *link_map;
} path_t;

void display_all(path_t *node);
path_t *add_cell(path_t *old, char *name);
void pathfinder(ant_t *ant);
void path_init(path_t *node, ant_t *ant);
void freeall(antman_t *anthill);
