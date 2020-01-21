/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>

struct info_param *my_params_to_array(int ac, char **av);

int size_len(unsigned int nbr, int div);
char *my_strcat(char *dest, char const *src);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_getnbr(char *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_wordtab(char *str);
int my_show_word_array(char * const *tab);
int my_printf(char *str, ...);
int my_puthexa(long long int nbr, char *base);
int my_putnbr_base(unsigned int nbr, char *base);
int my_put_unsigned_int(unsigned int nb);
char *my_strdup(char const *src);

#endif /* MY_H_ */
