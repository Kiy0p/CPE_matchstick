/*
** EPITECH PROJECT, 2019
** error_input.c
** File description:
** manages error input from player
*/

#include "../include/my.h"

int check_pipes (infoo_t util, char **tab, int *info)
{
    for (int i = 0; i < util.total_cols; i++) {
        if (tab[info[0]][i] == '|')
            info[3]++;
    }
    return (info[3]);
}

int *rand_line(char **tab, int *info, infoo_t util)
{
    my_putstr("Line: ");
    info[0] = get_loop(tab, util);
    if (info[0] == -852)
        return (info);
    if (info[0] > util.lines || info[0] <= 0 && info[0] != -963)
        my_putstr("Error: this line is out of range\n");
    if (info[0] == -963)
        my_putstr("Error: invalid input (positive number expected)\n");
    info[3] = 0;
    if (info[0] <= util.lines && info[0] >= 0)
        info[3] = check_pipes(util, tab, info);
    if (info[3] == 0 && info[0] < util.lines && info[0] > 0)
        my_putstr("Error: not enough matches on this line\n");
    if (info[0] > util.lines || info[0] <= 0 || info[3] == 0)
        info = rand_line(tab, info, util);
    return (info);
}

int *rand_matches(char **tab, int *info, infoo_t util)
{
    my_putstr("Matches: ");
    info[1] = get_loop(tab, util);
    if (info[1] == -852)
        return (info);
    if (info[1] > info[3] && info[1] < util.nbr_matches)
        my_putstr("Error: not enough matches on this line\n");
    if (info[1] <= 0 && info[1] != -963)
        my_putstr("Error: you have to remove at least one match\n");
    else if (info[1] > util.nbr_matches) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(util.nbr_matches);
        my_putstr(" matches per turn\n");
    }
    if (info[1] == -963)
        my_putstr("Error: invalid input (positive number expected)\n");
    if (info[1] <= 0 || info[1] > info[3] || info[1] > util.nbr_matches) {
        rand_line(tab, info, util);
        rand_matches(tab, info, util);
    }
    return (info);
}

char **game_loop_input(char **tab, infoo_t util, int *info)
{
    my_putstr("\nYour turn:\n");
    info = rand_line(tab, info, util);
    if (info[0] == -852) {
        tab[0][0] = 'e';
        return (tab);
    }
    info = rand_matches(tab, info, util);
    if (info[1] == -852) {
        tab[0][0] = 'e';
        return (tab);
    }
    my_putstr("Player removed ");
    my_putnbr(info[1]);
    my_putstr(" match(es) from line ");
    my_putnbr(info[0]);
    my_putchar('\n');
    tab = mod_map(tab, util, info);
    return (tab);
}
