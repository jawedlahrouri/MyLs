/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** Header avec les fonctions
*/


#include <stdio.h>
#include <stdarg.h>

#ifndef MY_H
    #define MY_H

typedef struct {
    int flag_l;
    int flag_a;
    int flag_r;
    int flag_d;
    int flag_t;
} ls_flags_t;

int my_isneg(int nb);
void my_put_nbr(int nb);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_putchar(char c);
int my_printf(const char *format, ...);
void flag_d(va_list list);
void flag_o(va_list list);
void flag_s(va_list list);
void flag_i(va_list list);
void flag_c(va_list list);
void flag_percent(va_list list);
void flag_x2(va_list list);
void flag_x(va_list list);
int flag_detector(const char *format, int i, va_list list);
int main(int argc, char **argv);
int my_strncmp(char *const str1, char *const str2);
int bubble_sort(char **tab);
char *my_strdup(char const *src);
void print_flagl(const char *file);
char **dir_to_tab(char *path, int flag_a);
int my_strnmajcmp(char *str1, char *str2);
void reverse_tab(char **tab);
int execute_flagd(char *path, ls_flags_t *flags);
void find_flags(char *flags_str, ls_flags_t *flags);
void initialize_flags(ls_flags_t *flags);
int calculate_total(char **tab);
int parse_argument(char *arg, char **path, char **flags);
void sort_time(char **tab);
#endif /*my.h*/
