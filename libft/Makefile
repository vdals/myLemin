# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnydia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 16:55:31 by jnydia            #+#    #+#              #
#    Updated: 2019/09/16 18:22:25 by jnydia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRCS = ft_lstnew.c ft_clean_array.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_striter.c ft_putchar.c ft_putchar_fd.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_putstr.c ft_putstr_fd.c ft_putnbr.c ft_putnbr_fd.c ft_strtrim.c gwl.c ft_strsplit.c ft_countwords.c ft_putendl.c ft_putendl_fd.c ineg.c ft_itoa.c ft_strrev.c gla.c get_next_line.c ft_countword.c math_1.c ft_print_base.c ft_get_format.c ft_shorter.c ft_hashnco.c ft_shorter_high.c ft_shorter_high2.c size_print.c ft_printf.c print_symb.c ft_shorter_int.c ft_get_format_int.c ft_hashnco2.c float.c ft_shorter_float.c ft_ltoa.c ft_shorter_int2.c print_symb2.c print_symb3.c ft_shorter2.c ft_shorter3.c ft_length_of_num.c

O_FILES = ${SRCS:.c=.o}

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCS) $(O_FILES) $(HEADER)
		ar rc $(NAME) $(O_FILES)
		ranlib $(NAME)

$(O_FILES): %.o: %.c
			gcc -c $(FLAGS) $< -I$(HEADER)

clean:
		rm -rf $(O_FILES)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY:all clean fclean re
