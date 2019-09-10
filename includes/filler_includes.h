/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_includes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:23:43 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/09/10 12:45:50 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_INCLUDES_H
# define FILLER_INCLUDES_H
# define BUFF_SIZE 999999
# include <limits.h>
# include <stdlib.h>
# include "libftprintf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
typedef struct		s_data
{
	char 			player;
	int				Y;
	int				X;
	int 			i;
	int				plateauX;
	int				plateauY;
	char			*piece;
	char 			*set;
}									t_data;

typedef struct		s_solv
{
	int				Y;
	int				X;
}									t_solv;

int				get_next_line(const int fd, char **line);
void			scan_map(char *sstd, t_solv *answer, t_data *tmp);
void  		stock_info(char *sstd, t_data *tmp);
void  		choose_axe(char *nbr, t_data *tmp, int j);
void  		grep_info(char *sstd, t_data *tmp);
void  		grep_player(char *sstd, t_data *tmp);
t_data    init_struct(void);
t_solv    init_answer(void);

#endif
