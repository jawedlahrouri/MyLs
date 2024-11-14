/*
** EPITECH PROJECT, 2024
** bs_myls
** File description:
** my_ls
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>


int my_ls(int argc, char **argv)
{
    DIR *directory;
    struct dirent *entry;
    directory = opendir(".");
    if (directory == NULL)
        return 84;
    while (1) {
        entry = readdir(directory);
        if (entry == NULL)
            break;
        if (entry->d_name[0] == '.')
            continue;
        my_printf("%s\n", entry->d_name);
    }
    if (closedir(directory) == -1)
        return 84;
    return 0;
}

int main(int argc, char **argv)
{
    my_ls(argc, argv);
}
