/*
** EPITECH PROJECT, 2019
** my_puthexa
** File description:
** my_puthexa
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"

int size_len(unsigned int nbr, int div);

int my_puthexa(long long int nbr, char *base)
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
