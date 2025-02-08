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

int handle_errors(char *path)
{
    struct stat path_stat;
    DIR *dir;

    if (stat(path, &path_stat) != 0)
        return 84;
    if (S_ISDIR(path_stat.st_mode)) {
        dir = opendir(path);
        if (!dir) {
            my_printf("ls: cannot open directory '%s': ", path);
            my_printf("Permission denied\n");
            return 84;
        }
        closedir(dir);
    }
    return 0;
}

int check_directory(char *path)
{
    DIR *dir = opendir(path);

    if (!dir) {
        my_printf("ls: cannot open directory '%s': Permission denied\n", path);
        return 84;
    }
    closedir(dir);
    return 0;
}

void print_entries(char **tab, ls_flags_t *flags)
{
    int total = 0;

    if (flags->flag_t)
        sort_time(tab);
    if (flags->flag_r)
        reverse_tab(tab);
    if (flags->flag_l) {
        total = calculate_total(tab);
        my_printf("total %d\n", total);
    }
    for (int i = 0; tab[i] != NULL; i++) {
        if (flags->flag_l)
            print_flagl(tab[i]);
        my_printf("%s\n", tab[i]);
    }
}

int list_directory(char *path, char *flags_str)
{
    ls_flags_t flags;
    char **tab = NULL;

    initilize_flags(&flags);
    if (flags_str != NULL)
        find_flags(flags_str, &flags);
    if (check_directory(path) == 84)
        return 84;
    if (handle_errors(path) == 84)
        return 84;
    if (execute_flags(path, &flags) == 84)
        return 84;
    tab = dir_to_tab(path, flags.flag_a);
    print_entries(tab, &flags);
    return 0;
}

int main(int argc, char **argv)
{
    char *path = NULL;
    char *flags_str = NULL;

    for (int i = 1; i < argc; i++)
        if (parse_argument(argv[i], &path, &flags_str) == 84)
            return 84;
    if (path == NULL)
        path = ".";
    if (list_directory(path, flags_str) == 84)
        return 84;
    return 0;
}
