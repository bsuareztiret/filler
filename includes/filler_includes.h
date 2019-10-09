/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_includes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 21:50:03 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/10/09 16:30:21 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_INCLUDES_H
# define FILLER_INCLUDES_H
# define BUFF_SIZE 300
# include <limits.h>
# include <stdlib.h>
# include "../libftprintf/includes/libftprintf.h"

typedef struct		s_data
{
	char			pme;
	char			pen;
	int				x;
	int				y;
	int				plateaux;
	int				plateauy;
	char			**piece;
	char			**set;
	int				posme;
	int				ifplay;
}					t_data;

typedef struct		s_sun
{
	int				d_meup;
	int				d_medo;
	int				d_inpo;
	int				d_mefo;
}					t_sun;

typedef struct		s_count
{
	int				px;
	int				py;
	int				x;
	int				y;
}					t_count;

int					get_next_line(const int fd, char **line);
int					in_play_area(t_data *tmp, t_count c, int check);
int					fill_up(t_data *tmp, t_count c);
int					fill_do(t_data *tmp, t_count c);
int					fill_left(t_data *tmp, t_count c);
int					fill_right(t_data *tmp, t_count c);
int					is_placable_do(t_data *tmp, t_count c, int check);
int					is_placable_up(t_data *tmp, t_count c, int check);
int					is_placable_left(t_data *tmp, t_count c, int check);
int					is_placable_right(t_data *tmp, t_count c, int check);
void				invade_en(t_data *tmp, t_sun *tzu, t_count c);
void				board_resolve(t_data *tmp, t_sun *tzu);
void				change_strategy(t_sun *tzu, t_data *tmp, t_count c);
t_count				choose_path(t_sun *tzu, t_count c, t_data *tmp, int path);
void				convert_result(int py, int px, t_data *tmp);
int					grep_info(char *sstd, t_data *tmp, int x, int i);
char				grep_player(char *sstd, t_data *tmp);
int					stock_board(char *sstd, t_data *tmp, int x);
int					stock_axe(char *sstd, t_data *tmp, int j);
void				scan_map_do(t_data *tmp, t_sun *tzu);
void				scan_map_up(t_data *tmp, t_sun *tzu);
t_data				init_info(t_data *tmp);
t_data				init_info_while(t_data *tmp);
t_sun				init_war(void);
t_count				init_count(int sign, t_data *tmp);
void				freetab(char **tab, int size, int i);

#endif
