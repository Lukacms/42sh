##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##


SRC	=	my_printf/my_printf.c					\
		my_printf/my_putaddr.c					\
		my_printf/flags/flag_handler_b.c		\
		my_printf/flags/flag_handler_c.c		\
		my_printf/flags/flag_handler_d.c		\
		my_printf/flags/flag_handler_i.c		\
		my_printf/flags/flag_handler_lower_s.c	\
		my_printf/flags/flag_handler_lower_x.c	\
		my_printf/flags/flag_handler_o.c		\
		my_printf/flags/flag_handler_p.c		\
		my_printf/flags/flag_handler_percent.c	\
		my_printf/flags/flag_handler_u.c		\
		my_printf/flags/flag_handler_upper_s.c	\
		my_printf/flags/flag_handler_upper_x.c	\

SRC_LIB	=	my_compute_power_rec.c				\
			my_compute_square_root.c 			\
			my_find_prime_sup.c 				\
			my_getnbr.c 						\
			my_isneg.c							\
			my_is_prime.c						\
			my_putchar.c						\
			my_put_nbr.c						\
			my_putstr.c							\
			my_revstr.c							\
			my_showmem.c						\
			my_showstr.c						\
			my_sort_int_array.c					\
			my_strcapitalize.c					\
			my_strcat.c							\
			my_strcmp.c							\
			my_strcpy.c							\
			my_str_isalpha.c					\
			my_str_islower.c					\
			my_str_isnum.c						\
			my_str_isprintable.c				\
			my_str_isupper.c					\
			my_strlen.c							\
			my_strlowcase.c						\
			my_strncat.c						\
			my_strncmp.c						\
			my_strncpy.c						\
			my_strstr.c							\
			my_strupcase.c						\
			my_swap.c							\
			concat_params.c						\
			my_str_to_word_array.c				\
			my_strdup.c							\
			my_show_word_array.c				\
			my_put_nbr_base.c					\
			my_strndup.c						\
			my_int_to_str.c						\
			load_file_in_mem.c					\
			free_array.c						\
			my_reallocarray.c					\
			my_memset.c							\
			dup_array.c							\
			str_to_word_array.c					\
			concat_arrays.c						\
			array_len.c							\
			char_in_str.c						\

OBJ	=	$(SRC:.c=.o)

OBJ_LIB	=	$(SRC_LIB:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./

all:	$(NAME)

$(NAME):	$(OBJ)	$(OBJ_LIB)
	@ar rc $(NAME) $(OBJ) $(OBJ_LIB)
	@cp my.h ../../include
	@mv libmy.a ../

clean:
	@rm -f $(OBJ) $(OBJ_MAIN) $(OBJ_LIB)

fclean:	clean
	@rm -f ../$(NAME)

re:	fclean all clean

.PHONY: fclean all clean
