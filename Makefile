# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/11 10:20:35 by bsuarez-          #+#    #+#              #
#    Updated: 2019/10/08 13:17:51 by bsuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsuarez-.filler
CC = gcc
CFLAGS += -Ofast -Wall -Wextra -Werror
SANITIZE = -fsanitize=address
LIBFTP =./libftprintf
HEADER = ./includes
DIR_S = ./src
DIR_O = ./obj
SOURCES = board_resolv.c \
		  get_next_line.c \
		  grep_info.c \
		  init_struct.c \
		  is_placable.c \
		  look_map.c \
		  invasion.c \
		  main.c
SRCS = $(addprefix $(DIR_S)/, $(SOURCES))
OBJS = $(SOURCES:.c=.o)
OBJS_DIR = $(addprefix $(DIR_O)/, $(OBJS))
MV = $(shell mv bsuarez-.filler ./resources/players)
RN = $(shell rm a.out)
DP = $(shell rm ./resources/players/bsuarez-.filler)

HD = $(addprefix ./includes/, filler_includes.h libft.h libftprintf.h)

all: $(NAME)

$(NAME):
	@printf '[\033[0;32m....................\033[0m] (0%%)\r'
	@printf '[\033[0;32m********............\033[0m] (40%%)\r'
	@make -C $(LIBFTP)
	@cp libftprintf/libftprintf.a ./
	@mkdir -p obj
	@printf '[\033[0;32m**********..........\033[0m] (50%%)\r'
	@$(CC) $(CFLAGS) -I $(HEADER) -c $(SRCS)
	@printf '[\033[0;32m****************....\033[0m] (70%%)\r'
	@mv $(OBJS) $(DIR_O)
	@$(CC) $(CFLAGS) $(OBJS_DIR) libftprintf.a -o $(NAME)
	@printf '[\033[0;32m********************\033[0m] (100%%)\r'
	@echo "bsuarez-.filler \033[0;32mcreated ~ [\/].\033[0m"~

move: $(NAME)
	@$(MV)

san:
	@printf '[\033[0;32m....................\033[0m] (0%%)\r'
	@printf '[\033[0;32m********............\033[0m] (40%%)\r'
	@make -C $(LIBFTP)
	@cp libftprintf/libftprintf.a ./
	@mkdir -p obj
	@printf '[\033[0;32m**********..........\033[0m] (50%%)\r'
	@$(CC) $(CFLAGS) -I $(HEADER) -c $(SRCS)
	@printf '[\033[0;32m****************....\033[0m] (70%%)\r'
	@mv $(OBJS) $(DIR_O)
	@$(CC) $(CFLAGS) $(SANITIZE) $(OBJS_DIR) libftprintf.a -o $(NAME)
	@printf '[\033[0;32m********************\033[0m] (100%%)\r'
	@$(MV)
	@echo "bsuarez-.filler with fsanatize \033[0;32mcreated ~ [\/].\033[0m"~

val:
		@printf '[\033[0;32m....................\033[0m] (0%%)\r'
		@printf '[\033[0;32m********............\033[0m] (40%%)\r'
		@make -C $(LIBFTP)
		@cp libftprintf/libftprintf.a ./
		@mkdir -p obj
		@printf '[\033[0;32m**********..........\033[0m] (50%%)\r'
		@$(CC) $(CFLAGS) -I $(HEADER) -c $(SRCS)
		@printf '[\033[0;32m****************....\033[0m] (70%%)\r'
		@mv $(OBJS) $(DIR_O)
		@$(CC) $(CFLAGS) $(SANITIZE) $(OBJS_DIR) libftprintf.a -o $(NAME)
		@printf '[\033[0;32m********************\033[0m] (100%%)\r'
		@$(MV)
		@echo "bsuarez-.filler with valgrind \033[0;32mcreated ~ [\/].\033[0m"~


clean:
	@printf '[\033[0;32m********************\033[0m] (100%%)\r'
	@ make clean -C $(LIBFTP)
	@$(RM) -rf $(OBJS)
	@$(RM) -rf $(DIR_O)
	@echo "[FILLER]   All files .o have been \033[1;31mdeleted\033[0m."

fclean: clean
	@printf '[\033[0;32m********************\033[0m] (100%%)\r'
	@make fclean -C $(LIBFTP)
	@$(RM) -rf $(NAME)
	@$(RM) -rf ./resources/players/bsuarez-.filler
	@$(RM) -rf ./libftprintf.a
	@echo "$(NAME) has been \033[1;31mdeleted\033[0m."

re: fclean all

.PHONY: all clean fclaen re san move val
