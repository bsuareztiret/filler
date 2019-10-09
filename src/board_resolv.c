/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_resolv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:08:07 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/10/09 16:52:48 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler_includes.h"

void		convert_result(int py, int px, t_data *tmp)
{
	freetab(tmp->set, tmp->plateauy - 1, 0);
	freetab(tmp->piece, tmp->y - 1, 0);
	tmp->ifplay = 1;
	ft_printf("%d %d\n", py, px);
}

t_count		choose_path(t_sun *tzu, t_count c, t_data *tmp, int path)
{
	if (path == 1)
	{
		c.px = -1;
		c.py = tzu->d_mefo - 1;
		c.x = -1;
		c.y = -1;
	}
	if (path == 2)
	{
		c.px = -1;
		c.py = tzu->d_meup - tmp->y;
		c.x = -1;
		c.y = -1;
	}
	if (path == 3)
	{
		c.px = tmp->plateaux;
		c.py = tmp->plateauy;
		c.x = tmp->x - 1;
		c.y = tmp->y - 1;
	}
	return (c);
}

void		change_strategy(t_sun *tzu, t_data *tmp, t_count c)
{
	if (tzu->d_meup == 0 && tzu->d_medo <= tmp->plateauy - 1)
		tzu->d_inpo = 0;
	if (tzu->d_meup > 0 || tzu->d_inpo == 1)
	{
		c = choose_path(tzu, c, tmp, 2);
		if (fill_up(tmp, c) == 0)
		{
			c = init_count(1, tmp);
			fill_up(tmp, c);
		}
	}
	else if (tzu->d_medo < tmp->plateauy || tzu->d_inpo == 0)
	{
		c = choose_path(tzu, c, tmp, 3);
		if (fill_do(tmp, c) == 0)
		{
			c = init_count(1, tmp);
			fill_up(tmp, c);
		}
	}
}

void		invade_en(t_data *tmp, t_sun *tzu, t_count c)
{
	c = choose_path(tzu, c, tmp, 1);
	if (tmp->plateauy < 20)
		tmp->posme -= 2;
	if (tmp->posme + 1 >= (tmp->plateaux / 2))
	{
		c = choose_path(tzu, c, tmp, 2);
		if (fill_left(tmp, c) == 0)
		{
			c = init_count(1, tmp);
			fill_left(tmp, c);
		}
	}
	else
	{
		c = choose_path(tzu, c, tmp, 3);
		if (fill_right(tmp, c) == 0)
		{
			c = init_count(-1, tmp);
			fill_right(tmp, c);
		}
	}
}

void		board_resolve(t_data *tmp, t_sun *tzu)
{
	t_count		c;

	if ((int)ft_strlen(tmp->set[0]) != 0)
	{
		scan_map_do(tmp, tzu);
		c = init_count(1, tmp);
		if (tzu->d_meup == 0 && tzu->d_medo == tmp->plateauy - 1
				&& tzu->d_mefo < (tmp->plateauy / 10) * 9 && tzu->d_mefo != -1
				&& tmp->plateauy > 60)
		{
			c = choose_path(tzu, c, tmp, 1);
			if (fill_up(tmp, c) == 0)
			{
				c = init_count(-1, tmp);
				fill_do(tmp, c);
			}
		}
		else if (tzu->d_mefo < 0)
			invade_en(tmp, tzu, c);
		else
			change_strategy(tzu, tmp, c);
	}
}
