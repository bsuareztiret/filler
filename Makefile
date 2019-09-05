# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/11 10:20:35 by bsuarez-          #+#    #+#              #
#    Updated: 2019/09/05 13:18:30 by bsuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler.out
CC = gcc
CFLAGS += -Wall -Wextra -Werror
HEAD =		filler_includes.h\
			libft.h\
			libftprintf.h
FILE =		get_next_line.c\
			nt_detection.c\
			nt_read_info.c\
			nt_set_transform.c\
			libftprintf.a

SRC = $(addprefix ./src/, get_next_line.c nt_init.c nt_detection.c nt_read_info.c nt_getchar.c nt_set_transform.c libftprintf.a)
HD = $(addprefix ./includes/, filler_includes.h libft.h libftprintf.h)
O_FILES = $(FILE:%.c=%.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(PA) $(HD)

clean:
	$(RM) $(O_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all
