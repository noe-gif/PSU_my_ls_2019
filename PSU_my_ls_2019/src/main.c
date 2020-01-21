/*
** EPITECH PROJECT, 2020
** ls
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include "../include/ls.h"
#include "../include/my.h"

int is__file(const char *name)
{
    DIR* directory = opendir(name);

    if (directory != NULL) {
        closedir(directory);
        return 0;
    }
    if (errno == ENOTDIR) {
        return 1;
    }
    return -1;
}

int check__file__type(char *dir)
{
    if ((is__file(dir) == -1)) {
        return (84);
    }
    return (0);
}

int switch_last_args(int ac, char **av)
{
    if ((ac == 2) && (av[1][0] == '-') && (av[1][1] == 'r')) {
        l_r();
        return (0);
    }
    if ((ac == 3) && (av[1][0] == '-') && (av[1][1] == 'd'))
        check_type(av[2]);
    if ((ac == 3) && (av[1][0] == '-') && (av[1][1] == 'a'))
        flag__a(av[2]);
    if ((isFile(av[1]) == 1) && (isFile(av[2]) == 0) &&
        (isFile(av[2]) != 84) && (ac == 3)) {
        my_printf("%s\n\n", av[1]);
        my_printf("%s:\n", av[2]);
        l_s(av[2]);
        return (0);
    }
    return (5);
}

int switch_agrs(int ac, char **av)
{
    if (av[1][0] == '-' && ac == 2) {
        switch (av[1][1]) {
        case 'a':
            flag_a();
            break;
        case 'l':
            flag_l(".");
            break;
        case 'd':
            flag_d();
            break;
        case 't':
            flag_t(".");
            break;
        case 'h':
            helper();
            break;
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        ls();
        return (1);
    }
    if ((ac == 3) && (av[1][0] == '-') && (av[1][1] == 'l'))
        flag_l(av[2]);
    if ((av[1][0] != '-') && (isFile(av[1]) == 0) && (ac == 2)) {
        l_s(av[1]);
        return (0);
    }
    if ((av[1][0] != '-') && (isFile(av[1]) == 1) && (ac == 2)) {
        my_printf("%s\n", av[1]);
        return (0);
    }
    switch_last_args(ac, av);
    switch_agrs(ac, av);
    final_parsing(ac, av);
    return (0);
}
