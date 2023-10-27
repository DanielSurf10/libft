# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 19:29:07 by danbarbo          #+#    #+#              #
#    Updated: 2023/10/27 13:44:47 by danbarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -c
INCLUDE = .
SRC		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
			ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJ		= ${SRC:%.c=%.o}

all: ${NAME}

%.o: %.c
	${CC} ${FLAGS} -I ${INCLUDE} $< -o $@
	ar rcs ${NAME} $@

${NAME}: ${OBJ}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

so:			# APAGAR ESSA BOSTA		# APAGAR ESSA BOSTA		# APAGAR ESSA BOSTA
	$(CC) -nostartfiles -fPIC $(FLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

teste:		# APAGAR ESSA BOSTA		# APAGAR ESSA BOSTA		# APAGAR ESSA BOSTA
	make fclean
	rm -f libft.h.gch	# APAGAR ESSA BOSTA		# APAGAR ESSA BOSTA
	rm -f libft.so		# APAGAR ESSA BOSTA		# APAGAR ESSA BOSTA
	make -C ../tester f
	make fclean

.PHONY: all clean fclean re
