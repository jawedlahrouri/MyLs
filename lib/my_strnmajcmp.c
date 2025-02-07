/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** compare str en prenant les maj en compte
*/

int maj_to_low(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int my_strnmajcmp(char *str1, char *str2)
{
    char c1;
    char c2;

    for (int i = 0; (str1[i] != '\0' || str2[i] != '\0'); i++) {
        c1 = maj_to_low(str1[i]);
        c2 = maj_to_low(str2[i]);
        if (c1 != c2)
            return c1 - c2;
    }
    return 0;
}
