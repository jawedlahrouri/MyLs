##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile
##

pathdir = lib

NAME = libmy.a
EXEC = my_ls



SRC	=	./src/my_ls.c \
		./src/flag_l.c \
		./src/list_directory.c \
		./src/ls_flags.c \
		./src/flag_t.c \
		$(pathdir)/my_strnmajcmp.c \
		$(pathdir)/my_strdup.c \
		$(pathdir)/my_strncmp.c \
		$(pathdir)/my_compute_power_rec.c \
		$(pathdir)/my_compute_square_root.c \
		$(pathdir)/my_isneg.c \
		$(pathdir)/my_put_nbr.c \
		$(pathdir)/my_putchar.c \
		$(pathdir)/my_putstr.c \
		$(pathdir)/my_revstr.c \
		$(pathdir)/my_strcat.c \
		$(pathdir)/my_strcpy.c \
		$(pathdir)/my_strlen.c \
		$(pathdir)/my_strncat.c \
		$(pathdir)/my_strncpy.c \
		$(pathdir)/flag_c.c \
		$(pathdir)/flag_d.c \
		$(pathdir)/flag_i.c \
		$(pathdir)/flag_o.c \
		$(pathdir)/flag_percent.c \
		$(pathdir)/flag_s.c \
		$(pathdir)/flag_x.c \
		$(pathdir)/flag_x2.c \
		$(pathdir)/my_printf.c \
		$(pathdir)/my_sort_params.c

OBJ  	=	 $(SRC:.c=.o)

ORGANIZED = my_ls
CFLAGS = -Iinclude/ -W -Wall -Wextra

$(ORGANIZED): $(OBJ)
		gcc $(OBJ) -o $(ORGANIZED) $(CFLAGS) $(LDFLAGS)

all: 	$(ORGANIZED)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(ORGANIZED)

re:
		$(MAKE) fclean
		$(MAKE) all

debug:
		$(MAKE) clean
		gcc -g -Wall -Wextra -W $(SRC) -o $(ORGANIZED) $(CFLAGS)
