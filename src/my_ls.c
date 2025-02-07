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

void init_flags(ls_flags_t *flags)
{
    flags->flag_l = 0;
    flags->flag_a = 0;
    flags->flag_r = 0;
    flags->flag_d = 0;
}

void find_flags(char *flags_str, ls_flags_t *flags)
{
    for (int i = 0; flags_str[i] != '\0'; i++) {
        if (flags_str[i] == 'l')
            flags->flag_l = 1;
        if (flags_str[i] == 'a')
        flags->flag_a = 1;
        if (flags_str[i] == 'r')
        flags->flag_r = 1;
        if (flags_str[i] == 'd')
        flags->flag_d = 1;
    }
}

int handle_errors(char *path)
{
    if (access(path, F_OK) != 0) {
        my_printf("ls: cannot access '%s': No such file or directory\n", path);
        return 84;
    }
    if (access(path, R_OK) != 0) {
        my_printf("ls: cannot open directory '%s': Permission denied\n", path);
        return 84;
    }
    return 0;
}

int list_directory(char *path, char *flags_str)
{
    ls_flags_t flags;
    char **tab = NULL;
    struct stat path_stat;
    DIR *dir;

    init_flags(&flags);
    if (flags_str != NULL)
        find_flags(flags_str, &flags);
    if (handle_errors(path) == 84)
        return 84;
    stat(path, &path_stat);
    if (flags.flag_d) {
        if (flags.flag_l)
            print_flagl(path);
        my_printf("%s\n", path);
        return 84;
    }
    dir = opendir(path);
    if (!dir) {
        my_printf("ls: cannot open directory '%s': Permission denied\n", path);
        return 84;
    }
    closedir(dir);
    tab = dir_to_tab(path, flags.flag_a);
    if (flags.flag_r)
        reverse_array(tab);
    for (int i = 0; tab[i] != NULL; i++) {
        if (flags.flag_l == 1){
            print_flagl(tab[i]);
            my_printf("%s\n", tab[i]);
        } else
            my_printf("%s\n", tab[i]);
    }
    return 0;
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
    } else if (stat(arg, &path_stat) == 0) {
        *path = arg;
    } else {
        my_printf("ls: cannot access '%s': No such file or directory\n", arg);
        exit(84);
    }
}

int main(int argc, char **argv)
{
    char *path = NULL;
    char *flags_str = NULL;

    for (int i = 1; i < argc; i++)
        parse_argument(argv[i], &path, &flags_str);
    if (path == NULL)
        path = ".";
    if (list_directory(path, flags_str) == 84)
        return 84;
    return 0;
}
