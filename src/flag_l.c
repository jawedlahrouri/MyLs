/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** handle flag l
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

void int_to_str(long num, char *buffer)
{
    char temp[20];
    int i = 0;
    int j = 0;

    if (num == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }
    while (num > 0) {
        temp[i] = (num % 10) + '0';
        num /= 10;
        i++;
    }
    temp[i] = '\0';
    for (; i > 0; j++) {
        buffer[j] = temp[i];
        i--;
    }
    buffer[j] = '\0';
}

void fill_buffer(struct stat *fs, char *buf, char *time)
{
    buf[0] = '\0';
    my_printf("%d", fs->st_nlink);
    my_strcat(buf, " ");
    my_strcat(buf, getpwuid(fs->st_uid) ? getpwuid(fs->st_uid)->pw_name : "?");
    my_strcat(buf, " ");
    my_strcat(buf, getgrgid(fs->st_gid) ? getgrgid(fs->st_gid)->gr_name : "?");
    my_strcat(buf, " ");
    my_printf("%s", buf);
    my_printf("%d ", fs->st_size);
    my_printf("%s ", time);
}

static void extract_time(time_t raw_time, char *buffer)
{
    char *time_str = ctime(&raw_time);

    if (!time_str)
        return;
    for (int i = 4; i < 16; i++) {
        buffer[i - 4] = time_str[i];
    }
    buffer[12] = '\0';
}

static void get_permissions(mode_t mode, char *buffer)
{
    buffer[0] = (S_ISDIR(mode)) ? 'd' : '-';
    buffer[1] = (mode & S_IRUSR) ? 'r' : '-';
    buffer[2] = (mode & S_IWUSR) ? 'w' : '-';
    buffer[3] = (mode & S_IXUSR) ? 'x' : '-';
    buffer[4] = (mode & S_IRGRP) ? 'r' : '-';
    buffer[5] = (mode & S_IWGRP) ? 'w' : '-';
    buffer[6] = (mode & S_IXGRP) ? 'x' : '-';
    buffer[7] = (mode & S_IROTH) ? 'r' : '-';
    buffer[8] = (mode & S_IWOTH) ? 'w' : '-';
    buffer[9] = (mode & S_IXOTH) ? 'x' : '-';
    buffer[10] = '\0';
}

void file_data(const char *file, struct stat *fs, char *perm, char *time)
{
    if (stat(file, fs) < 0)
        return;
    get_permissions(fs->st_mode, perm);
    extract_time(fs->st_mtime, time);
}

void print_flagl(const char *file)
{
    struct stat fs;
    char perm[11];
    char time[20];
    char *buf = malloc(sizeof(char) * 1024);

    file_data(file, &fs, perm, time);
    my_printf("%s ", perm);
    fill_buffer(&fs, buf, time);
    return;
}
