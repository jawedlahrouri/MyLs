/*
** EPITECH PROJECT, 2024
** my_sort_params
** File description:
** sort params
*/

#include <stdarg.h>
#include <stdio.h>
#include "../include/my.h"

int sort_name(char **tab, int *swap)
{
    char *temp = NULL;

    if (tab == NULL)
        return 84;
    for (int i = 0; tab[i + 1] != NULL; i++) {
        if (my_strnmajcmp(tab[i], tab[i + 1]) > 0) {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
            *swap = 1;
        }
    }
    return 0;
}

int bubble_sort(char **tab)
{
    int swap;

    if (tab == NULL)
        return 84;
    do {
        swap = 0;
        sort_name(tab, &swap);
    } while (swap);
    return 0;
}
