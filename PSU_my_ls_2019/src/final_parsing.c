/*
** EPITECH PROJECT, 2020
** parsing
** File description:
** ls
*/

#include "../include/ls.h"
#include "../include/my.h"

int final_parsing(int ac, char **av)
{
    if ((ac == 3) && (isFile(av[1]) != 1) && (isFile(av[2]) != 1)
        && (av[1][0] != '-') && (ac == 3) && (ac < 4)) {
        my_printf("%s", av[1]);
        my_putstr(":\n");
        l_s(av[1]);
        my_printf("\n%s:\n", av[2]);
        l_s(av[2]);
        return (1);
    }
    return (0);
}
