/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** same as cpy but for only n char
*/

#include "../include/my.h"
char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; n != 0; i++) {
        dest[i] = src[i];
        n = n - 1;
    }
    return (dest);
}
