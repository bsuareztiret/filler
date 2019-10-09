/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:13:59 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/10/09 16:17:28 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler_includes.h"

t_data		init_info(t_data *tmp)
{
	tmp->pme = tmp->pme;
	tmp->pen = tmp->pen;
	tmp->x = 0;
	tmp->y = 0;
	tmp->plateaux = 1;
	tmp->plateauy = 1;
	tmp->piece = NULL;
	tmp->set = NULL;
	tmp->posme = -1;
	return (*tmp);
}

t_data		init_info_while(t_data *tmp)
{
	tmp->pme = tmp->pme;
	tmp->pen = tmp->pen;
	tmp->plateauy = tmp->plateauy;
	tmp->plateaux = tmp->plateaux;
	tmp->x = 0;
	tmp->y = 0;
	tmp->piece = NULL;
	tmp->set = NULL;
	tmp->posme = tmp->posme;
	tmp->ifplay = 0;
	return (*tmp);
}

t_sun		init_war(void)
{
	t_sun	tzu;

	tzu.d_meup = 0;
	tzu.d_medo = 0;
	tzu.d_inpo = 0;
	tzu.d_mefo = -1;
	return (tzu);
}

t_count		init_count(int sign, t_data *tmp)
{
	t_count	c;

	if (sign == 1)
	{
		c.px = 0 - tmp->x - 1;
		c.py = 0 - tmp->y - 1;
		c.x = -1;
		c.y = -1;
	}
	if (sign == -1)
	{
		c.px = tmp->plateaux - 1 + tmp->x;
		c.py = tmp->plateauy - 1 + tmp->y;
		c.x = tmp->x;
		c.y = tmp->y - 1;
	}
	return (c);
}

void		freetab(char **tab, int size, int i)
{
	if (!tab)
		return ;
	while (i < size)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
}
