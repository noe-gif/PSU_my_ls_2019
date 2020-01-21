/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct
*/

#ifndef STRUCT
#define STRUCT
//____________________________________________
//flags_______________________________________

int flag_l(char *dirname);
int flag__l(char *dirname);
void flag_z(void);
void flag_a(void);
void flag__a(char *dir);
void ls(void);
int l_s(char *dirname);
void l_r(void);
void flag_d(void);
void flag_t(char *directory);
void helper(void);
//____________________________________________
//functions___________________________________

int final_parsing(int ac, char **av);
int isFile(const char *name);
char **sort__name(char **array);
char **check_time(char **tab, char *directory);
int my_delim(char s, char *lim);
int while_delim(char const *str, int i, char *lim);
int count_word(char const *str, char *lim);
int word_size(char *str, int i, char *lim);
char **my__str__to__word__array(char *str, char *lim);
int check_type(char *dir);
int compare_time(char *str);
char *my_merge_strings(char *empty_line, char *buffer);
void disp_total_block(char *rep);
int check_type(char *dir);
int *array_of_int(char **nombre);
int *sort_number(int *array);
char **sort_name(char **name);
char *erase_space(char *str);
int isfile(const char *name);
int check_file_type(char *dir);
int is__file(const char *name);
int check__file__type(char *dir);

#endif /* STRUCT  */
