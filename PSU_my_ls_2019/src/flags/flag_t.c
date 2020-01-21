/*
** EPITECH PROJECT, 2017
** ls
** File description:
** dandt
*/

#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <grp.h>
#include <fcntl.h>
#include <string.h>
#include <getopt.h>
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
#include "../../include/my.h"
#include "../../include/ls.h"

char *file___to___inspect(char *ls, char *file)
{
    char *str = my_strdup(ls);

    str = my_strcat(str, "/");
    str = my_strcat(str, file);
    return (str);
}

char **swap_time(int str1, int str2, char **tab)
{
    char *tmp = my_strdup(tab[str1]);

    tab[str1] = my_strdup(tab[str2]);
    tab[str2] = my_strdup(tmp);
    free(tmp);
    return (tab);
}

char **check_time(char **tab, char *directory)
{
    int y = 0;
    char *str = NULL;
    char *str2 = NULL;
    long tmp = 0;
    struct stat my_stat;

    while (tab[y + 1]) {
        str = file___to___inspect(directory, tab[y]);
        str2 = file___to___inspect(directory, tab[y + 1]);
        stat(str, &my_stat);
        tmp = my_stat.st_mtime;
        stat(str2, &my_stat);
        if (tmp < my_stat.st_mtime) {
            swap_time(y, y + 1, tab);
            y = 0;
        }
        else
            y++;
    }
    return (tab);
}

void flag_t(char *directory)
{
    DIR *dir = opendir(directory);
    struct dirent *current_directory;
    char **tab;
    char *names = "\0";

    while ((current_directory = readdir(dir)) != 0) {
        if ((current_directory->d_name[0] != '.')) {
            names = my_strcat(names, current_directory->d_name);
            names = my_strcat(names, "\n");
        }
    }
    tab = my__str__to__word__array(names, "\n");
    tab = check_time(tab, directory);
    my_show_word_array(tab);
}
