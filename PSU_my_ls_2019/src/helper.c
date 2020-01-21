/*
** EPITECH PROJECT, 2020
** helper
** File description:
** ls
*/

#include "../include/my.h"

void helper(void)
{
    my_printf("Usage: ./my_ls [OPTION]..."
"[FILE]... [FILE2]...\n\n");
    my_printf("\t -a, --all"
"do not ignore entries starting with.\n");
    my_printf("\t -d, --directory            list directories "
"themselves, not their contents\n");
    my_printf("\t -r, --reverse"
"reverse order while sorting\n");
    my_printf("\t -t,                        sort"
"by modification time, newest first\n");
    my_printf("\t -l,                        sort"
"with information about all the files in cd\n");
}
