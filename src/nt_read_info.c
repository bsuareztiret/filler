/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_read_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:14:07 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/09/03 17:52:24 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler_includes.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

t_solv		scan_map(char *sstd, t_solv answer, t_data *tmp)
{
	int i;
//	t_data	tmp;
//	char *set;

	i = 0;
//	tmp = init_struct();
	grep_info(sstd, i, tmp);
//	set = set_splitcpy(sstd, i);
	/*if (i = set_resolve(nbr, nxt, set))
		return (i);*/
	return (answer);
}

int   main(void)
{
	int ret;
	char *sstd;
	t_solv answer;
	t_data tmp;

	ret = 0;
	tmp = init_struct();
	answer.X = 0;
	answer.Y = 0;
	while ((ret = get_next_line(1, &sstd)) > 0)
	{
			//ft_printf("%s\n", sstd);
			answer = scan_map(sstd, answer, &tmp);
	//	ft_printf("%d %d\n", ans);
	}
	ft_printf("%s", sstd);
	return (0);
}
