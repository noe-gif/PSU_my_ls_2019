/*
** EPITECH PROJECT, 2019
** putstr
** File description:
** d
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
