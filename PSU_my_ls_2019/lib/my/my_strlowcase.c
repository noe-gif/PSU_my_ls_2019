/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** low
*/

#include "../../include/my.h"

char *my_strlowcase(char *str)
{
    char *copy = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    copy = my_strcpy(copy, str);
    while (copy[i]) {
        if (copy[i] >= 'A' && copy[i] <= 'Z')
            copy[i] += 32;
        i++;
    }
    return copy;
}
