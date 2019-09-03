/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_includes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:23:43 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/09/03 17:53:46 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_INCLUDES_H
# define FILLER_INCLUDES_H
# define BUFF_SIZE 32
# include <limits.h>
# include "libftprintf.h"

typedef struct		s_data
{
	int				Y;
	int				X;
	int				plateauX;
	int				plateauY;
	char			*piece;
}									t_data;

typedef struct		s_solv
{
	int				Y;
	int				X;
}									t_solv;

int				get_next_line(const int fd, char **line);
t_solv		scan_map(char *sstd, t_solv answer, t_data *tmp);
int   		set_start(char *sstd, int i);
int   		is_char_game(char c);
char  		*set_splitcpy(char *sstd, int i);
int   		is_p(char* sstd, int i);
void  		stock_info(char *sstd, t_data *tmp, int i, int j);
void  		choose_axe(char *nbr, t_data *tmp, int j);
void  		grep_info(char *sstd, int i, t_data *tmp);
t_data    init_struct(void);

#endif
