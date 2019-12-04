/*
** EPITECH PROJECT, 2019
** get_input.c
** File description:
** gets the input from the player
*/

#include "../include/my.h"

int get_loop(char **tab, infoo_t util)
{
    int c_d = 0;
    int nbr = 0;
    long unsigned int nbytes = 100;
    char *my_string = malloc(sizeof(char) * (nbytes + 1));

    c_d = getline(&my_string, &nbytes, stdin);
    for (int i = 0; i < c_d - 1; i++) {
        if (my_string[i] < 48 || my_string[i] > 57)
            return (-963);
    }
    nbr = my_getnbr(my_string);
    if (c_d == -1)
        return (-852);
    if (c_d != -1)
        return (nbr);
}

int funtion_for_iff(int j, infoo_t util, char **tab)
{
    int pipe = 0;

    for (int i = 0; i < (util.total_cols); i++) {
        if (tab[j][i] == '|')
            pipe++;
    }
    return (pipe);
}

char **mod_map(char **tab, infoo_t util, int *info)
{
    int j = info[0];
    int i = info[1];

    for (int k = util.total_cols; k > 0; k--) {
        if (tab[j][k] == '|' && i > 0) {
            tab[j][k] = ' ';
            i--;
        }
    }
    print_tab(tab, util);
    return (tab);
}

int second_loop(char **tab, infoo_t util, int *info)
{
    tab = game_loop_input(tab, util, info);
    if (tab[0][0] == 'e')
        return (-1);
    info[2] = 0;
    for (int j = 0; j < (util.lines + 3); j++)
        info[2] += funtion_for_iff(j, util, tab);
    if (info[2] == 0) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    tab = ia_turn(tab, util, info);
    info[2] = 0;
    for (int j = 0; j < (util.lines + 3); j++)
        info[2] += funtion_for_iff(j, util, tab);
    if (info[2] == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    else
        return (0);
}

int game_loop(char **tab, infoo_t util)
{
    int *info = malloc(sizeof(int) * 5);
    info[0] = 0;
    info[1] = 0;
    info[2] = 1;
    info[3] = 0;
    info[4] = 0;

    while (info[4] == 0) {
        info[4] = second_loop(tab, util, info);
        if (tab[0][0] == 'e')
            return (0);
    }
    return (info[4]);
}