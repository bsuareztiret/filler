/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invasion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:32:34 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/10/08 20:32:36 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler_includes.h"

int			is_placable_left(t_data *tmp, t_count c, int check)
{
	while (++c.x < tmp->x)
	{
		c.y = -1;
		while (++c.y < tmp->y)
		{
			if (tmp->piece[c.y][c.x] == '*')
			{
				if (in_play_area(tmp, c, check) == -1)
					return (-1);
				if (tmp->set[c.py + c.y][c.px + c.x] == tmp->pme)
					check++;
			}
		}
	}
	return (check == 1 ? 1 : -1);
}

int			fill_left(t_data *tmp, t_count c)
{
	while (++c.px < tmp->plateaux)
	{
		c.py = -1 - tmp->y;
		while (++c.py < tmp->plateauy)
		{
			if (is_placable_left(tmp, c, 0) == 1)
			{
				convert_result(c.py, c.px, tmp);
				return (1);
			}
		}
	}
	return (0);
}

int			is_placable_right(t_data *tmp, t_count c, int check)
{
	while (c.x >= 0)
	{
		c.y = tmp->y - 1;
		while (c.y >= 0)
		{
			if (tmp->piece[c.y][c.x] == '*')
			{
				if (in_play_area(tmp, c, check) == -1)
					return (-1);
				if (tmp->set[c.py + c.y][c.px + c.x] == tmp->pme)
					check++;
			}
			c.y--;
		}
		c.x--;
	}
	return (check == 1 ? 1 : -1);
}

int			fill_right(t_data *tmp, t_count c)
{
	while (c.px >= 0)
	{
		c.py = tmp->plateauy + tmp->y;
		while (c.py >= 0)
		{
			if (is_placable_right(tmp, c, 0) == 1)
			{
				convert_result(c.py, c.px, tmp);
				return (1);
			}
			c.py--;
		}
		c.px--;
	}
	return (0);
}
