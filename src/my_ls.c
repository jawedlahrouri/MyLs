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

int count_directory(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *entry;
    int count = 0;

    if (!dir)
        return 0;
    entry = readdir(dir);
    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (entry->d_name[0] != '.')
            count++;
    }
    closedir(dir);
    return count;
}

char **dir_to_tab(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *entry;
    char **tab = malloc(sizeof(char *) * (count_directory(path) + 1));
    int i = 0;

    if (!dir)
        return NULL;
    entry = readdir(dir);
    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (entry->d_name[0] != '.') {
            tab[i] = my_strdup(entry->d_name);
            i++;
        }
    }
    tab[i] = NULL;
    bubble_sort(tab);
    closedir(dir);
    return tab;
}

void find_flag(char *flags, int *flag_l)
{
    for (int i = 0; flags[i] != '\0'; i++)
        if (flags[i] == 'l')
            *flag_l = 1;
}

void print_separator(char **tab, int i)
{
    if (tab[i + 1] == NULL)
        my_putchar('\n');
    else
        my_putstr("  ");
}
void list_directory(char *path, char *flags)
{
    char full_path[1024];
    int flag_l = 0;
    char **tab = dir_to_tab(path);
    char *buffer = NULL;

    if (flags != NULL)
        find_flag(flags, &flag_l);
    for (int i = 0; tab[i] != NULL; i++) {
        if (flag_l == 1){
            print_flagl(tab[i]);
            my_printf("%s\n", tab[i]);
        } else{
            my_printf("%s", tab[i]);
            print_separator(tab, i);
        }
    }
}

int main(int argc, char **argv)
{
    char *path = NULL;
    char *flags = NULL;

    for (int i = 1; argv[i] != NULL; i++)
        if (argv[i][0] == '/')
            path = argv[i];
        else if (argv[i][0] == '-' && flags == NULL){
            flags = strdup(argv[i]);
        }
    if (path == NULL)
        path = ".";
    list_directory(path, flags);
    return 0;
}
