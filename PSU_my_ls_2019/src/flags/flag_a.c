/*
** EPITECH PROJECT, 2020
** ls
** File description:
** bootsrap
*/

#include <stdio.h>
#include "../../include/ls.h"
#include "../../include/my.h"
#include <dirent.h>
#include <string.h>

void flag_a(void)
{
    DIR* directory = opendir(".");
    struct dirent *cur;

    while (cur = readdir(directory)) {
        my_putstr(cur->d_name);
        my_putstr("  ");
    }
    my_putchar('\n');
    closedir(directory);
}

void flag__a(char *dir)
{
    DIR* directory = opendir(dir);
    struct dirent *cur;
    int	files =	0;

    while (cur = readdir(directory)) {
        if (files == 8)
            my_putchar('\n');
        my_putstr(cur->d_name);
        my_putstr("  ");
        files++;
    }
    my_putchar('\n');
    closedir(directory);
}
