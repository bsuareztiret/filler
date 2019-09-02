/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_read_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:14:07 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/08/29 21:39:55 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler_includes.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		*scan_map(char *sstd)
{
	int i;
	int *nbr;
	char *nxt;
	char *set;

	i = 0;
	while (sstd[i] != '\0')
	  {
	    if (set_start(sstd, i))
	      set = set_splitcpy(sstd, i);
			if (sstd[i] == 'P')
					j = is_p(sstd, i);
			if (j == 1)
					nbr = axe_info(sstd, i);
			if (j == 2)
					nxt = stock_piece(sstd, i);
	    i++;
	  }
	if (i = set_resolve(nbr, nxt, set))
		return (i);
	return (0);
}

int   main(int ac, char **av)
{
	int ret;
	int y;
	int x;
	char *ans;
	char *sstd;

	ret = 0;
	while ((ret = get_next_line(1, &sstd)) > 0)
	{
		ans = scan_map(sstd);
		y = convert_ans(ans, 1)
		x = convert_ans(ans, 2);
		ft_printf("%d %d\n", y, x);
	}
	return (0);
}
