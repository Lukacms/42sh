/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** functions prototypes
*/

#ifndef    MY_H
    #define    MY_H

    #include <sys/types.h>
    #include <stdarg.h>

typedef struct pflag_handler_s {
    char flag;
    void (*handler)(va_list);
} pflag_handler_t;

void my_putaddr(unsigned long addr);
void flag_handler_b(va_list ap);
void flag_handler_c(va_list ap);
void flag_handler_d(va_list ap);
void flag_handler_i(va_list ap);
void flag_handler_lower_s(va_list ap);
void flag_handler_lower_x(va_list ap);
void flag_handler_o(va_list ap);
void flag_handler_p(va_list ap);
void flag_handler_percent(va_list ap);
void flag_handler_u(va_list ap);
void flag_handler_upper_s(va_list ap);
void flag_handler_upper_x(va_list ap);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
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
int my_strncmp(char const *s1, char const *s2, int n);
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
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);
int my_show_word_array(char * const *tab);
char *concat_params(int argc, char **argv);
int my_putnbr_base_unsign(unsigned int nbr, char const *base);
int my_putnbr_base(int nbr , char const *base);
int my_printf(char *str, ...);
int my_putnbr_base_unsigned_long(unsigned long nbr, char const *base);
char *my_strndup(char *const src, int n);
char *my_int_to_str(int nb);
char *load_file_in_mem(char const *filepath);
void free_array(void **array);
char **my_reallocarray(char **ptr, u_int y, u_int x);
void my_memset(char *ptr, u_int x, char c);
char **dup_array(char * const origin[]);
char **str_to_array_choice(char *src, char *delim);
char **concate_arrays(char **src, char **add);
int array_len(char **array);

#endif /*MY_H*/
