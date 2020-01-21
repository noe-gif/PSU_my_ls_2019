/*
** EPITECH PROJECT, 2020
** flag_d
** File description:
** ls
*/

#include "../../include/my.h"
#include "../../include/ls.h"
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void flag_d(void)
{
    DIR* directory = opendir(".");
    struct dirent *cur;

    while (cur = readdir(directory)) {
        if (cur->d_name[0] == '.' &&
            cur->d_name[my_strlen(cur->d_name)-1] != '~') {
            my_putstr(cur->d_name);
            my_putchar('\n');
            return;
        }
    }
    closedir(directory);
}

int isFile(const char *name)
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

int check_type(char *dir)
{
    if ((isFile(dir) == 1) || (isFile(dir) == 0)) {
        my_putstr(dir);
        my_putchar('\n');
    }
    else {
        my_printf("ls: cannot access '%s'", dir);
        my_printf(": No such file or directory");
        my_putchar('\n');
        return (84);
    }
    return (0);
}
