/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** putnbr
*/

void my_putchar(char c);

int my_putstr(char *str);

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + 48);
    return (0);
}
