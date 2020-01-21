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

char *file_to_inspect(char *ls, char *file)
{
    char *str = my_strdup(ls);

    if (my_strcmp(str, ".") == 0) {
        str = my_strcat(str, "/");
        str = my_strcat(str, file);
        return (str);
    }
    str = my_strcat(str, "/");
    str = my_strcat(str, file);
    return (str);
}

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
        }
        return (4);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    switch_agrs(ac, av);
    return (0);
}
