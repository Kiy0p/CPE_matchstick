/*
** EPITECH PROJECT, 2019
** ia_input.c
** File description:
** ia's turn
*/

#include "../include/my.h"

int *check_pipe_line(char **tab, int rand_tab[], infoo_t util)
{
    rand_tab[0] = random() % util.lines + 1;
    for (int i = 0; i < util.total_cols; i++) {
        if (tab[rand_tab[0]][i] == '|')
            rand_tab[2]++;
    }
    if (rand_tab[2] == 0)
        check_pipe_line(tab, rand_tab, util);
    return (rand_tab);
}

char **mod_map_ia(char **tab, infoo_t util, int rand_tab[])
{
    int j = rand_tab[0];
    int i = rand_tab[1];

    for (int k = util.total_cols; k > 0; k--) {
        if (tab[j][k] == '|' && i > 0) {
            tab[j][k] = ' ';
            i--;
        }
    }
    print_tab(tab, util);
    return (tab);
}

void message_output(int *rand_tab)
{
    my_putstr("AI removed ");
    my_putnbr(rand_tab[1]);
    my_putstr(" match(es) from line ");
    my_putnbr(rand_tab[0]);
    my_putchar('\n');
}

char **ia_turn(char **tab, infoo_t util, int *info)
{
    int matches_per_line = 0;
    int *rand_tab = malloc(sizeof(int) * 3);
    rand_tab[0] = 0;
    rand_tab[1] = 0;
    rand_tab[2] = 0;

    my_putstr("\nAI's turn...\n");
    srandom(time(0));
    while (rand_tab[0] == 0 || rand_tab[2] == 0) {
        rand_tab = check_pipe_line(tab, rand_tab, util);
    }
    while (rand_tab[1] == 0 || rand_tab[1] > util.nbr_matches)
        rand_tab[1] = random() % rand_tab[2] + 1;
    if (rand_tab[2] <= util.nbr_matches && info[2] == util.nbr_matches)
        rand_tab[1] = rand_tab[2] - 1;
    message_output(rand_tab);
    mod_map_ia(tab, util, rand_tab);
    return (tab);
}