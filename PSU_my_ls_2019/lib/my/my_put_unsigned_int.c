/*
** EPITECH PROJECT, 2019
** put_unsigned
** File description:
** unsigned_int
*/

void my_putchar(char c);

void my_putstr(char *str);

int my_put_unsigned_int(unsigned int nb)
{
    if (nb == 4294967295) {
        my_putstr("4294967295");
        return (0);
    }
    if (nb < 0) {
        my_putstr("error: not unsigned int");
    }
    if (nb > 9) {
        my_put_unsigned_int(nb / 10);
    }
    my_putchar(nb % 10 + 48);
}

