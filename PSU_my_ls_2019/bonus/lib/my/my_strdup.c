/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** lib
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    dest = my_strcpy(dest, src);
    return (dest);
}
