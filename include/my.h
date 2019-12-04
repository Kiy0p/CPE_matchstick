/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** write a header contains prototypes of all functions in libmy.a
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#ifndef MY_H
#define MY_H

struct infoo {
    int lines;
    int nbr_matches;
    int total_matches;
    int total_cols;
};
typedef struct infoo infoo_t;

int my_getnbr(char const *str);
void my_putchar(char c);
int my_putnbr(int nb);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
long long my_revnbr(long long nbr);
int get_info(infoo_t util);
int get_loop(char **tab, infoo_t util);
int game_loop(char **tab, infoo_t util);
void print_tab(char **tab, infoo_t util);
char **ia_turn(char **tab, infoo_t util, int *info);
char **game_loop_input(char **tab, infoo_t util, int *info);
char **mod_map(char **tab, infoo_t util, int *info);
int check_if_neg(int nbr);

#endif
