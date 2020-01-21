/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** my_putnbr_base
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"

int size_len(unsigned int nbr, int div)
{
    int len = 0;

    while (nbr > 0) {
        nbr /= div;
        len++;
    }
    return (len);
}

int my_putnbr_base(unsigned int nbr, char *base)
{
    int i = 0;
    int base_size = my_strlen(base);
    char *result = malloc(sizeof(char) * (size_len(nbr, base_size) + 1));
    while (nbr > 0)
    {
        result[i++] = base[nbr % base_size];
        nbr /= base_size;
    }
    result[i] = '\0';
    return (0);
}
