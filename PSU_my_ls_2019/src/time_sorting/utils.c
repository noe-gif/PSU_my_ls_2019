/*
** EPITECH PROJECT, 2020
** utils
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

char **sort__name(char **array)
{
    int i = 0;
    char *tmp;

    while (array[i + 1]) {
        if (my_strcmp(my_strlowcase(array[i]),
                      my_strlowcase(array[i + 1])) > 0) {
            tmp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = tmp;
            i = -1;
        }
        i++;
    }
    return (array);
}
