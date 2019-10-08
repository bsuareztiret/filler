/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 23:43:57 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/10/07 22:11:58 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler_includes.h"

char		grep_player(char *sstd, t_data *tmp)
{
	char	player;

	get_next_line(0, &sstd);
	if (ft_strstr(sstd, "p1"))
	{
		player = 'O';
		tmp->pen = 'X';
	}
	if (ft_strstr(sstd, "p2"))
	{
		player = 'X';
		tmp->pen = 'O';
	}
	ft_strdel(&sstd);
	return (player);
}

void		stock_board(char *sstd, t_data *tmp, int x)
{
	if (tmp->x && tmp->y)
	{
		if (ft_strstr(sstd, ".") || ft_strstr(sstd, "*"))
			tmp->piece[x] = ft_strdup(sstd);
	}
	else if (ft_strstr(sstd, "x") || ft_strstr(sstd, "X") ||
			ft_strstr(sstd, "o") || ft_strstr(sstd, "O") ||
			ft_strstr(sstd, "."))
	{
		if ((int)ft_strlen(sstd) > tmp->plateauy - 1)
			tmp->set[x] = ft_strsub(sstd, 4, tmp->plateaux);
		else
			tmp->set[x] = ft_strdup(sstd);
	}
}

void		stock_axe(char *sstd, t_data *tmp, int j)
{
	char	**nbr;

	nbr = NULL;
	nbr = ft_strsplit(sstd, ' ');
	if (j == 4)
	{
		tmp->y = ft_atoi(nbr[1]);
		tmp->x = ft_atoi(nbr[2]);
		if (!(tmp->piece = (char**)ft_memalloc((sizeof(char*) * tmp->y) + 1)))
			return ;
		tmp->piece[tmp->y] = NULL;
	}
	if (j == 6)
	{
		tmp->plateauy = ft_atoi(nbr[1]);
		tmp->plateaux = ft_atoi(nbr[2]);
		if (!(tmp->set = (char**)ft_memalloc((sizeof(char*)
			* (tmp->plateauy + 1)))))
			return ;
		tmp->set[tmp->plateauy] = NULL;
	}
	freetab(nbr, 3, 0);
}

void		grep_info(char *sstd, t_data *tmp, int x, int i)
{
	while (i <= tmp->plateauy && get_next_line(0, &sstd) > 0)
	{
		if ((int)ft_strlen(sstd) >= 1)
		{
			if (ft_strstr(sstd, "Plateau"))
			{
				x = -1;
				stock_axe(sstd, tmp, 6);
			}
			if (ft_strstr(sstd, "Piece"))
			{
				x = -2;
				stock_axe(sstd, tmp, 4);
				i -= tmp->y;
			}
			if (i >= 0)
				if (ft_strstr(sstd, " ") || ft_strstr(sstd, "*")
					|| ft_strstr(sstd, "."))
					stock_board(sstd, tmp, ++x);
		}
		i++;
	}
	ft_strdel(&sstd);
}
