/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_read_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:14:07 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/09/06 17:19:37 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler_includes.h"

void		scan_map(char *sstd, t_solv *answer, t_data *tmp)
{
	// if (!(set = ft_strnew(ft_strlen(sstd))))
	// 	return ;
	grep_info(sstd, tmp);
	/*if (i = set_resolve(nbr, nxt, set))
		return (i);*/
	answer->X = 0;
	answer->Y = 0;
	// ft_printf("%03d %d", answer->Y, answer->X);
}

int   main(void)
{
	char *sstd;
	t_solv answer;
	t_data tmp;
	int 	 i;
	int		 j;

	i = 0;
	j = 0;
	answer.X = 0;
	answer.Y = 0;
	sstd = ft_strnew(60000);
	tmp = init_struct();
	grep_player(sstd, &tmp);
	ft_printf("tmp.players = %c\n", tmp.player);

	 while (1)
	 {
			scan_map(sstd, &answer, &tmp);
 	 }
	return (0);
}
