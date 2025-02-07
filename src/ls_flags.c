/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** handle flag fonction call
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

int execute_flags(char *path, ls_flags_t *flags)
{
    struct stat path_stat;

    stat(path, &path_stat);
    if (flags->flag_d) {
        if (flags->flag_l)
            print_flagl(path);
        my_printf("%s\n", path);
        return 84;
    }
    return 0;
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

void initilize_flags(ls_flags_t *flags)
{
    flags->flag_l = 0;
    flags->flag_a = 0;
    flags->flag_r = 0;
    flags->flag_d = 0;
}

int calculate_total(char **tab)
{
    struct stat file_stat;
    int total_blocks = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (stat(tab[i], &file_stat) == 0) {
            total_blocks += file_stat.st_blocks;
        }
    }
    return total_blocks;
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
