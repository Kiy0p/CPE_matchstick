/*
** EPITECH PROJECT, 2019
** init_match.c
** File description:
** first step for the matchstick
*/

#include "../include/my.h"

int errors(int ac, char **av)
{
    int i = 0;
    int j = 0;
    int length_one = 0;
    int length_two = 0;

    if (ac != 3) {
        my_putstr("You need to give 2 arguments");
        return (84);
    }
    else if (ac == 3) {
        length_one = my_strlen(av[1]);
        length_two = my_strlen(av[2]);
    }
    for (i = 0; av[1][i] > 47 && av[1][i] < 58; i++);
    for (j = 0; av[2][j] > 47 && av[2][j] < 58; j++);
    if (i != length_one || j != length_two) {
        my_putstr("Arguments need to be of type integer");
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    char **tab;
    infoo_t util;
    int error_return = errors(ac, av);
    int exit = 0;

    if (error_return == 84)
        return (84);
    util.lines = my_getnbr(av[1]);
    util.nbr_matches = my_getnbr(av[2]);
    if (util.lines <= 1) {
        my_putstr("You must play with more then one line.");
        return (84);
    }
    if (util.lines >= 100) {
        my_putstr("You must play with less then 100 lines");
        return (84);
    }
    exit = get_info(util);
    return (exit);
}
