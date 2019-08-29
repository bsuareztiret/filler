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
	char *set;

	i = 0;
	nbr = areas_info(sstd);
	nxt = piece_info(sstd);
	set = set_transform(sstd);
	if (i = set_resolve(nbr, nxt, set))
		return (i);
	return (0);
}

int   main(int ac, char **av)
{
	int ret;
	int *ans;
	char *sstd;

	ret = 0;
	while ((ret = get_next_line(1, &sstd)) > 0)
	{
		ans = scan_map(sstd)
		ft_printf("%d %d\n", ans);
	}
	return (0);
}
