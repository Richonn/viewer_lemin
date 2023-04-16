/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-leandre.cacarie
** File description:
** ant
*/

#pragma once
typedef struct room {
    char *name;
    int x;
    int y;
    struct room *next;
}room_t;

typedef struct l_room {
    room_t *head;
}lroom_t;

typedef struct pipe {
    char *from;
    char *to;
    struct pipe *next;
}pipe_t;

typedef struct l_pipe {
    pipe_t *head;
}lpipe_t;

typedef struct link {
    char *data;
    struct link *next;
} link_t;

typedef struct list {
    link_t *first;
} list_t;

typedef struct ant {
    int ant;
    int error;
    char *brut;
    char **input;
    char **no_com;
    char **map;
    int max_x;
    int max_y;
    int min_x;
    int min_y;
    list_t *list;
    lroom_t *l_room;
    lroom_t *l_end;
    lroom_t *l_start;
    lpipe_t *l_pipe;
} ant_t;

// lib
void rc_putchar(char c);
void rc_putstr(char *str);
int rc_strlen(char *str);
char *rc_strdup(char *src);
void print_tab(char **tab);
void print_list(list_t *list);
int rc_strcmp(char *s1, char *s2);
int rc_getnbr(char *str);
int is_cmd_cmm(char *str);
char *clean_str(char *str);
int my_printf(char *format, ...);
int rc_putnbr(int nb);
char **my_str_to_word_array(char *str, char stop);
int my_str_isnum(char *str);
void print_line_tab(char **tab);
// list
void add_node(list_t *list, char *str);
void list_to_tab(ant_t *ant);
// error handling
int check_error(ant_t *ant);
int check_error_before(ant_t *ant);
int check_same_name(ant_t *ant);
int check_same_pos(ant_t *ant);
int check_all_room(ant_t *ant);
int check_valid_pipe(ant_t *ant);
// struct
int init_struct(ant_t *ant);
// recup input
void get_no_com(ant_t *ant);
int read_input(ant_t *ant);
// parser
int parser(ant_t *ant);
// parse file
void parse_init(ant_t *ant);
void parse_rooms(ant_t *ant);
int is_a_room(char *room);
int is_a_pipe(char *pipe);
lroom_t *listing_rooms(ant_t *ant);
// manipulate pipe_list and room_list
void put_in_rlist(lroom_t *l_room, char **tab);
void push_in_rlist(lroom_t *l_room, char **tab);
void display_rlist(lroom_t *l_room);
void put_in_plist(lpipe_t *l_pipe, char **tab);
void push_in_plist(lpipe_t *l_pipe, char **tab);
void display_plist(lpipe_t *l_pipe);
room_t *find_in_rlist_name(lroom_t *list, char *to_find);
room_t *find_in_rlist_coor(lroom_t *list, int x_find, int y_find);
void init_rlist(ant_t *ant);
void init_plist(ant_t *ant);
// print res
void print_res(ant_t *ant);
// bonus
void put_in_tab(ant_t *ant);
