/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:53:36 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/10/09 16:58:04 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler_includes.h"

int			main(void)
{
	char	*sstd;
	t_sun	tzu;
	t_data	tmp;

	sstd = NULL;
	if ((tmp.pme = grep_player(sstd, &tmp)) == 0)
		return (EXIT_FAILURE);
	tmp = init_info(&tmp);
	while (1)
	{
		tmp = init_info_while(&tmp);
		tzu = init_war();
		if (grep_info(sstd, &tmp, -1, -3) == -1)
			return (EXIT_FAILURE);
		board_resolve(&tmp, &tzu);
		if (tmp.ifplay == 0)
		{
			freetab(tmp.set, tmp.plateauy - 1, 0);
			freetab(tmp.piece, tmp.y - 1, 0);
			ft_printf("%d %d\n", 0, 0);
			return (0);
		}
	}
}
