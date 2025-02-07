/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** flag t
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

int compare_time(const char *file1, const char *file2)
{
    struct stat stat1;
    struct stat stat2;

    stat(file1, &stat1);
    stat(file2, &stat2);
    return stat2.st_mtime - stat1.st_mtime;
}

void sort_time(char **tab)
{
    int i = 0;
    int j = 0;
    char *temp;

    for (i = 1; tab[i] != NULL; i++) {
        temp = tab[i];
        j = i - 1;
        while (j >= 0 && compare_time(tab[j], temp) > 0) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = temp;
    }
}
