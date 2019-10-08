/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:54:26 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/10/08 20:32:53 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler_includes.h"

void		scan_map_up(t_data *tmp, t_sun *tzu)
{
	int		i;
	int		j;
	int		check;

	i = tmp->plateauy - 1;
	while (i >= 0)
	{
		j = tmp->plateaux - 1;
		check = 0;
		while (j >= 0)
		{
			if (tmp->set[i][j] == tmp->pme)
				tzu->d_meup = i;
			if (tmp->set[i][j] == tmp->pme)
				check++;
			if (check <= 5 && j == 0)
				tzu->d_mefo = i;
			j--;
		}
		i--;
	}
	if (tzu->d_meup == 0 && tzu->d_medo == tmp->plateauy - 1
		&& tmp->plateauy < 60)
		tzu->d_mefo = -1;
}

void		scan_map_do(t_data *tmp, t_sun *tzu)
{
	int		i;
	int		j;

	i = -1;
	while (++i < tmp->plateauy)
	{
		j = -1;
		while (++j < tmp->plateaux)
		{
			if (tmp->set[i][j] == tmp->pme)
				tzu->d_medo = i;
		}
	}
	if (tmp->posme == -1)
		tmp->posme = tzu->d_medo;
	if ((tmp->plateauy / 2) > tmp->posme)
		tzu->d_inpo = 0;
	if ((tmp->plateauy / 2) < tmp->posme)
		tzu->d_inpo = 1;
	scan_map_up(tmp, tzu);
}
