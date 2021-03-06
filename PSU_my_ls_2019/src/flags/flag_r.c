/*
** EPITECH PROJECT, 2020
** ls_r
** File description:
** ls
*/

#include "../../include/ls.h"
#include "../../include/my.h"
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

char *my_merging_strings(char *empty_line, char *buffer)
{
    int i = 0;
    int cnt = 0;
    char *new_line;
    int size = my_strlen(empty_line) + my_strlen(buffer);

    while (empty_line[i] != '\0') {
        i++;
    }
    new_line = malloc(sizeof(char) * (i + size + 1));
    i = 0;
    while (empty_line[i] != '\0') {
        new_line[i] = empty_line[i];
        i++;
    }
    while (cnt < size) {
        new_line[i + cnt] = buffer[cnt];
        cnt++;
    }
    new_line[i + size] = '\0';
    return (new_line);
}

char **sorting_name(char **array)
{
    int i = 0;
    char *tmp;

    while (array[i + 1]) {
        if (my_strcmp(my_strlowcase(array[i]),
                      my_strlowcase(array[i + 1])) < 0) {
            tmp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = tmp;
            i = -1;
        }
        i++;
    }
    return array;
}

void l_r(void)
{
    struct dirent *current_directory;
    struct stat my_stat;
    DIR *directory = opendir(".");
    char *str;
    char *big_str = "\0";
    char **name;

    while ((current_directory = readdir(directory)) != NULL) {
        if (current_directory->d_name[0] != '.') {
            stat(current_directory->d_name, &my_stat);
            str = current_directory->d_name;
            big_str = my_merging_strings(big_str, str);
            big_str = my_merging_strings(big_str, " ");
        }
    }
    name = my_str_to_wordtab(big_str);
    name = sorting_name(name);
    my_show_word_array(name);
    closedir(directory);
}
