/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** copies a string
*/

#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int count = 0;

    while (src[i] > '\0') {
        dest[i] = src[i];
        i+1;
    }
    dest[count] = '\0';
    return (dest);
}
