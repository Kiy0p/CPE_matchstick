/*
** EPITECH PROJECT, 2019
** manage_map.c
** File description:
** second step of the matchstick.
*/

#include "../include/my.h"

void print_tab(char **tab, infoo_t util)
{
    for (int j = 0; j < (util.lines + 3); j++) {
        for (int i = 0; i < (util.total_cols); i++)
            my_putchar(tab[j][i]);
        if (j != util.lines)
            my_putchar('\n');
    }
}

void put_pipe(infoo_t util, int line, char **tab)
{
    tab[line + 1][0] = '*';
    for (int j = 1; j < util.total_cols; j++) {
        if (j >= (util.total_cols / 2 - line)
        && j <= (util.total_cols / 2 + line))
            tab[line + 1][j] = '|';
        else if (j < util.total_cols)
            tab[line + 1][j] = ' ';
    }
    tab[line + 1][util.total_cols - 1] = '*';
}

void print_box(infoo_t util, char **tab)
{
    for (int i = 0; i < util.total_cols; i++) {
        tab[0][i] = '*';
    }
    for (int line = 0; line < util.lines; line++) {
        put_pipe(util, line, tab);
    }
    for (int i = 0; i < util.total_cols; i++) {
        tab[util.lines + 2][i] = '*';
    }
}

int get_info(infoo_t util)
{
    char **tab = malloc(sizeof(char *) * (util.lines + 2));
    int exit = 0;

    util.total_matches = util.lines * util.lines;
    util.total_cols = (util.lines * 2 + 1);
    for (int i = 0; i < (util.lines + 3); i++)
        tab[i] = malloc(sizeof(char) * util.total_cols);
    print_box(util, tab);
    print_tab(tab, util);
    exit = game_loop(tab, util);
    return (exit);
}