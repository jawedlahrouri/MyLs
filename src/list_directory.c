/*
** EPITECH PROJECT, 2024
** myls
** File description:
** list directory
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
    for (entry = readdir(dir); entry != NULL; entry = readdir(dir))
            count++;
    closedir(dir);
    return count;
}

char **dir_to_tab(char *path, int flag_a)
{
    DIR *dir = opendir(path);
    struct dirent *entry;
    int count = count_directory(path) + 1;
    char **tab = malloc(sizeof(char *) * count);
    int i = 0;

    if (!dir)
        return NULL;
    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (flag_a || entry->d_name[0] != '.') {
            tab[i] = my_strdup(entry->d_name);
            i++;
        }
    }
    tab[i] = NULL;
    bubble_sort(tab);
    closedir(dir);
    return tab;
}

void reverse_tab(char **tab)
{
    int i = 0;
    int j = 0;
    char *temp;

    for (j = 0; tab[j] != NULL; j++);
    j--;
    while (i < j) {
        temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
        i++;
        j--;
    }
}
