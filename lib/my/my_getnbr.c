/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** converts an char * into an int
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int nbr = 0;
    int i = 0;
    int ret = 0;

    if (str[0] == '-') {
        i++;
        ret++;
    }
    for (;str[i] > 47 && str[i] < 58; i++)
        nbr = nbr * 10 + str[i] - 48;
    if (ret > 0)
        nbr = nbr * -1;
    return (nbr);
}
