/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_placable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:58:34 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/10/07 14:52:28 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler_includes.h"

int			in_play_area(t_data *tmp, t_count c, int check)
{
	if (c.py + c.y < 0 || c.px + c.x < 0 || c.py + c.y > tmp->plateauy - 1
			|| c.px + c.x > tmp->plateaux - 1 || check > 1)
		return (-1);
	if (tmp->set[c.py + c.y][c.px + c.x] == tmp->pen
			|| tmp->set[c.py + c.y][c.px + c.x] == tmp->pen + 32)
		return (-1);
	return (1);
}

int			is_placable_up(t_data *tmp, t_count c, int check)
{
	while (++c.y < tmp->y)
	{
		c.x = -1;
		while (++c.x < tmp->x)
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

int			fill_up(t_data *tmp, t_count c)
{
	while (++c.py < tmp->plateauy)
	{
		c.px = -1 - tmp->x;
		while (++c.px < tmp->plateaux)
		{
			if (is_placable_up(tmp, c, 0) == 1)
			{
				convert_result(c.py, c.px, tmp);
				return (1);
			}
		}
	}
	return (0);
}

int			is_placable_do(t_data *tmp, t_count c, int check)
{
	while (c.y >= 0)
	{
		c.x = tmp->x - 1;
		while (c.x >= 0)
		{
			if (tmp->piece[c.y][c.x] == '*')
			{
				if (in_play_area(tmp, c, check) == -1)
					return (-1);
				if (tmp->set[c.py + c.y][c.px + c.x] == tmp->pme)
					check++;
			}
			c.x--;
		}
		c.y--;
	}
	return (check == 1 ? 1 : -1);
}

int			fill_do(t_data *tmp, t_count c)
{
	while (c.py >= 0)
	{
		c.px = tmp->plateaux + tmp->x;
		while (c.px >= 0)
		{
			if (is_placable_do(tmp, c, 0) == 1)
			{
				convert_result(c.py, c.px, tmp);
				return (1);
			}
			c.px--;
		}
		c.py--;
	}
	return (0);
}
