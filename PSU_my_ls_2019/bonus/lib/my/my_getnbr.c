/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** getnbr
*/

int my_put_nbr(int nb);

int check_sign(char c)
{
    if (c == '-')
        return (-1);
    else
        return (1);
}

int my_getnbr(char *str)
{
    int	nb = 0;
    int	sign = 1;
    int	i = 0;

    while (str[i] == '+' || str[i] == '-') {
        sign = sign * check_sign(str[i]);
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
        }
        else
            return (nb * sign);
        if (nb < 0)
            return (0);
        i++;
    }
    return (nb * sign);
}
