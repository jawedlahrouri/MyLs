/*
** EPITECH PROJECT, 2024
** bs_myls
** File description:
** my_ls
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "../include/my.h"

void find_flag(char *flags, int *flag_l, int *flag_a)
{
    for (int i = 0; flags[i] != '\0'; i++) {
        if (flags[i] == 'l')
            *flag_l = 1;
        if (flags[i] == 'a')
            *flag_a = 1;
        if (flags[i] == 'r')
            *flag_l = 1;
        if (flags[i] == 'd')
            *flag_a = 1;
    }
}

void list_directory(char *path, char *flags)
{
    int flag_l = 0;
    int flag_a = 0;
    char **tab = NULL;

    if (flags != NULL)
        find_flag(flags, &flag_l, &flag_a);
    tab = dir_to_tab(path, flag_a);
    for (int i = 0; tab[i] != NULL; i++) {
        if (flag_l == 1){
            print_flagl(tab[i]);
            my_printf("%s\n", tab[i]);
        } else {
            my_printf("%s", tab[i]);
            my_putchar('\n');
        }
    }
}

void parse_argument(char *arg, char **path, char **flags)
{
    struct stat path_stat;
    char *temp = NULL;

    if (arg[0] == '-') {
        if (*flags == NULL)
            *flags = my_strdup(arg);
        else {
            temp = malloc(my_strlen(*flags) + my_strlen(arg) + 1);
            my_strcpy(temp, *flags);
            my_strcat(temp, arg + 1);
            free(*flags);
            *flags = temp;
        }
    } else if (stat(arg, &path_stat) == 0 && S_ISDIR(path_stat.st_mode)) {
        *path = arg;
    }
}

int main(int argc, char **argv)
{
    char *path = NULL;
    char *flags = NULL;
    int flag_l = 0;
    int flag_a = 0;

    for (int i = 1; i < argc; i++)
        parse_argument(argv[i], &path, &flags);
    if (path == NULL)
        path = ".";
    if (flags != NULL)
        find_flag(flags, &flag_l, &flag_a);
    list_directory(path, flags);
    return 0;
}
