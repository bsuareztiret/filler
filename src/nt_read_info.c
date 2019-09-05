/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_read_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:14:07 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/09/05 18:51:19 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler_includes.h"

void		scan_map(char *sstd, t_solv *answer, t_data *tmp)
{
	int i;
//	t_data	tmp;
	char *set;

	i = 0;

	if (!(set = ft_strnew(ft_strlen(sstd))))
		return ;
	ft_printf("****tmp.players = %c\n", tmp->player);
	grep_info(sstd, i, tmp);
	// set_splitcpy(sstd, set, i);
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

	//tmp = init_struct();
	i = 0;
	j = 0;
	answer.X = 0;
	answer.Y = 0;
	sstd = ft_strnew(60000);
	tmp = init_struct();
	grep_player(sstd, &tmp);
	ft_printf("tmp.players = %c\n", tmp.player);

	// while (1)
	// {
			//ft_printf("eh ben?\n");
			//ft_printf("%s\n", sstd);
			// ft_printf("ecris un truc stp\n");
	scan_map(sstd, &answer, &tmp);
	//	ft_printf("%d %d\n", ans);
// }


	return (0);
}
