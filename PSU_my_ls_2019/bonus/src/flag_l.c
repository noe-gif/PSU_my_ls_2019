/*
** EPITECH PROJECT, 2020
** flag_l
** File description:
** ls
*/

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
#include "../include/ls.h"
#include "../include/my.h"

void disp_total_block(char *rep)
{
    struct stat sb;
    struct dirent *drt;
    int tot = 0;
    char *cat;
    DIR *dir = opendir(rep);

    while ((drt = readdir(dir))) {
        cat = my_strcat(my_strcat(rep, "/"), drt->d_name);
        if ((lstat(cat, &sb)) == 0)
            (drt->d_name[0] != '.') ? tot += sb.st_blocks : 0;
    }
    closedir(dir);
    my_printf("total %d\n", tot / 2);
}

void print_rights(struct stat my_stat)
{
    my_putstr( (S_ISDIR(my_stat.st_mode)) ? "d" : "-");
    my_putstr( (my_stat.st_mode & S_IRUSR) ? "r" : "-");
    my_putstr( (my_stat.st_mode & S_IWUSR) ? "w" : "-");
    my_putstr( (my_stat.st_mode & S_IXUSR) ? "x" : "-");
    my_putstr( (my_stat.st_mode & S_IRGRP) ? "r" : "-");
    my_putstr( (my_stat.st_mode & S_IWGRP) ? "w" : "-");
    my_putstr( (my_stat.st_mode & S_IXGRP) ? "x" : "-");
    my_putstr( (my_stat.st_mode & S_IROTH) ? "r" : "-");
    my_putstr( (my_stat.st_mode & S_IWOTH) ? "w" : "-");
    my_putstr( (my_stat.st_mode & S_IXOTH) ? "x" : "-");
}

void complete_l(struct dirent *current_directory, struct stat my_stat,
                char *dirname)
{
    char *str;
    struct passwd *pwd;
    struct group *grp;

    str = file_to_inspect(dirname, current_directory->d_name);
    stat(str, &my_stat);
    pwd = getpwuid(my_stat.st_uid);
    grp = getgrgid(my_stat.st_gid);
    print_rights(my_stat);
    my_printf(" %d %s ", my_stat.st_nlink, pwd->pw_name);
    my_printf("%s %d \t ", grp->gr_name, my_stat.st_size);
    my_putstr("\b\b\b\b\b\b\b ");
    write(1, (ctime(&my_stat.st_mtime) + 4),
          (my_strlen(ctime(&my_stat.st_mtime)) - 13));
}

void print_info(struct dirent *current_directory, struct stat my_stat,
                struct tm lt, struct passwd *pwd)
{

    if (pwd != 0) {
        my_putchar(' ');
        if (S_ISDIR(my_stat.st_mode) == 1) {
            my_printf("\033[1;34m");
            my_printf("%s", current_directory->d_name);
            my_printf("\033[0m");
        }
        else if (!(my_stat.st_mode & S_IXOTH)) {
            my_printf("%s", current_directory->d_name);
        }
        if (my_stat.st_mode & S_IXOTH && S_ISDIR(my_stat.st_mode) == 0) {
            my_printf("\033[1;32m");
            my_printf("%s", current_directory->d_name);
            my_printf("\033[0m");
        }
        my_putchar('\n');
    }
}

void flag_l(char *dirname)
{
    struct dirent *current_directory;
    struct stat my_stat;
    struct tm lt;
    struct passwd *pwd;
    DIR *directory = opendir(dirname);

    disp_total_block(dirname);
    while (current_directory = readdir(directory)) {
        if (current_directory->d_name[0] != '.') {
            stat(current_directory->d_name, &my_stat);
            if ((stat(current_directory->d_name, &my_stat)) == 0) {
                pwd = getpwuid(my_stat.st_uid);
            }
            complete_l(current_directory, my_stat, dirname);
            print_info(current_directory, my_stat, lt, pwd);
        }
    }
}
