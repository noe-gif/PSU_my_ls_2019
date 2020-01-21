/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../include/my.h"

int first_flags(char *str, va_list ap, int i)
{
    switch (str[i + 1]) {
    case 'b':
        my_putnbr_base(va_arg(ap, unsigned int), "01");
        break;
    case 'o':
        my_putnbr_base(va_arg(ap, unsigned int), "01234567");
        break;
    case 'u':
        my_put_unsigned_int(va_arg(ap, unsigned int));
        break;
    }
    return (i);
}

int second_flags(char *str, va_list ap, int i)
{
    switch (str[i + 1]) {
    case 'i':
        my_put_nbr(va_arg(ap, int));
        break;
    case 'x':
        my_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
        break;
    case 'X':
        my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
        break;
    }
    return (i);
}

int third_flags(char *str, va_list ap, int i)
{
    switch (str[i + 1]) {
    case '%':
        my_putchar('%');
        break;
    case 'p':
        my_putstr("0x");
        my_puthexa(va_arg(ap, long long int), "0123456789abcdef");
        break;
    }
    return (i);
}

int last_flags(char *str, va_list ap, int i)
{
    if (str[i] == '%') {
 	switch (str[i + 1]) {
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        case 'd':
            my_put_nbr(va_arg(ap, int));
            break;
        }
        first_flags(str, ap, i);
        second_flags(str, ap, i);
        third_flags(str, ap, i);
        return (1);
    }
    else
        return (0);
}

int my_printf(char *str, ...)
{
    va_list ap;
    int i = 0;
    int last = 0;

    va_start(ap, str);
    while (str[i] != '\0') {
        last = last_flags(str, ap, i);
        if (last == 1)
            i++;
        if (last == 0)
            my_putchar(str[i]);
        i++;
    }
    va_end(ap);
    return (0);
}
