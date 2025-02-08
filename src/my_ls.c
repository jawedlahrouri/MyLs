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

int handle_file(char *path, ls_flags_t *flags)
{
    struct stat path_stat;

    if (stat(path, &path_stat) != 0) {
        my_printf("ls: cannot access '%s': No such file or directory\n", path);
        return 84;
    }
    if (S_ISREG(path_stat.st_mode)) {
        if (flags->flag_l)
            print_flagl(path);
        my_printf("%s\n", path);
        return 0;
    }
    return 1;
}

int handle_directory(char *path, ls_flags_t *flags)
{
    char **tab;
    DIR *dir = opendir(path);

    if (!dir) {
        my_printf("ls: cannot open directory '%s': Permission denied\n", path);
        return 84;
    }
    closedir(dir);
    tab = dir_to_tab(path, flags->flag_a);
    print_entries(tab, flags);
    return 0;
}

int list_directory(char *path, char *flags_str)
{
    ls_flags_t flags;

    initialize_flags(&flags);
    if (flags_str)
        find_flags(flags_str, &flags);
    if (execute_flagd(path, &flags) == 1)
        return 0;
    if (handle_file(path, &flags) == 0)
        return 0;
    return handle_directory(path, &flags);
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
