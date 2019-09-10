/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_read_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:14:07 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/09/10 17:07:08 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler_includes.h"

int			is_placable(t_data *tmp, int i)
{
	int j;
	int l;

	j = ft_strichr(src, '*', 0);
	l = 0;
	while (j <= (int)ft_strlen(tmp->piece))
	{
		if (j % tmp->X == 0)
			i += 17;
		if (i % tmp->plateauX == 0 && j % tmp->X != 0)
			i += 17 - (j % tmp->X);
		if (tmp->set[i] == tmp->player && tmp->piece[j] == '*')
			l++;
		if (tmp->set[i] == tmp->player - 32 && tmp->piece[j] == '*')
			l++;
		if (!tmp->set[i] == '.' && !tmp->piece[j] == '.')
			return (0);
		if (l > 1)
			return (0);
		// if (tmp->set[i] == '.' && tmp->piece[j] == '*')
		i++;
		j++;
	}
	return (1);
}

int			ft_strichr(char *src, char c, int i)
{
	int	len;

	len = ft_strlen(src);
	while (i < len)
	{
		if (src[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void 		set_block(t_data *tmp, t_solv *answer, int i)
{
	ft_printf("||||%i\n", i);
	while (answer->X == 0 && answer->Y == 0)
	{
		if ((i = ft_strichr(tmp->set, tmp->player, i)) > 0)
		{
			ft_printf("||||%i\n", i);
			ft_printf("----- %c\n", tmp->set[i]);
			if (is_placable(tmp, i) == 1)
			{
				answer->X = i % tmp->plateauX;
				answer->Y = i / tmp->plateauX;
			}
			else
			set_block(tmp, answer, i + 1);
		}
	}
}

void 		set_resolve(t_data *tmp, t_solv *answer)
{
	// answer->X = 0;
	// answer->Y = 0;
	set_block(tmp, answer, 0);
	// if (ft_strchr(tmp->set, tmp->player))
	//
	// if (ft_strchr(tmp->set, tmp->player - 32))

}

void		scan_map(char *sstd, t_solv *answer, t_data *tmp)
{
	// if (!(set = ft_strnew(ft_strlen(sstd))))
	// 	return ;
	grep_info(sstd, tmp);
	//ft_printf("TMP->PIECE : %i ----- TMP.X*Y+1 : %i\n", (int)ft_strlen(tmp->piece), tmp->X * tmp->Y);
	if (tmp->X > 0 && tmp->Y > 0)
	{
		if ((int)ft_strlen(tmp->piece) == tmp->X * tmp->Y)
			set_resolve(tmp, answer);
	}
	// answer->X = 0;
	// answer->Y = 0;
	// ft_printf("%03d %d", answer->Y, answer->X);
}
void call_system(int i, t_data tmp)
{
	char 	*sys;
	// char	*tem;
	char	*name;

	if (i == 1)
	{
		system("rm -rf ./graphics/set_game_xo");
		system("mkdir ./graphics/set_game_xo");
	}
	if (i == 2)
	{
			// if (!(sys = ft_strnew(tmp.plateauX * tmp.plateauY + 20))
			// 		&& !(tem = ft_strnew(tmp.plateauX * tmp.plateauY + 20))
			// 		&& !(name = ft_strnew(20)))
			// 	return ;
			sys = "echo > \"";
			ft_printf("%s", sys);
			// tem = ft_strcat(ft_itoa(tmp.plateauX), ft_itoa(tmp.plateauY));
			// ft_printf("%s", tem);
			// sys = ft_strcat(sys, tem);
			// if (tmp.player == 'X')
			// 	name = ft_strcat(ft_itoa(tmp.i), "-p2");
			// if (tmp.player == 'Y')
			name = ft_strcat("\" ", ft_itoa(tmp.i));
			sys = ft_strcat(sys, name);
			sys = ft_strcat(sys, "-p1");
			// system(sys);
	}
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
	sstd = ft_strnew(60000);
	tmp = init_struct();
	grep_player(sstd, &tmp);
	ft_printf("tmp.players = %c\n", tmp.player);
	// call_system(1, tmp);
	 while (1)
	 {
		 	if (answer.X != 0 || answer.Y != 0)
		 		answer = init_answer();
			// ft_printf("tmp.AA||||||.X = %d\n", answer.X);
			// ft_printf("tmp.AA||||||.Y = %d\n", answer.Y);
			scan_map(sstd, &answer, &tmp);
			// if (tmp.X != 0)
			// 	call_system(2, tmp);
			ft_printf("tmp.AA.X = %d\n", answer.X);
			ft_printf("tmp.AA.Y = %d\n", answer.Y);
 	 }
	return (0);
}
