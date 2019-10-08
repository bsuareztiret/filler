/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:29:25 by mcabrol           #+#    #+#             */
/*   Updated: 2019/06/28 17:13:37 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_null(t_info *tmp, char **str)
{
	if (*str == 0)
	{
		*str = "(null)";
		tmp->type = 's';
		tmp->cast = 0;
	}
}

char	*ft_sign(t_info *tmp, t_padding *padding, char *str, long double f)
{
	t_sign	sign;
	char	*inf;

	sign = ft_init_sign();
	sign.dd = f;
	if (sign.u < 0)
	{
		padding->prefix = "-";
		f *= -1;
	}
	if (f == (1 / 0.0))
	{
		tmp->zero = 0;
		inf = ft_strdup("inf");
		free(str);
		return (inf);
	}
	if (sign.u == 9221120237041090560)
	{
		tmp->zero = 0;
		inf = ft_strdup("nan");
		free(str);
		return (inf);
	}
	return (str);
}

char	*ft_strtoupper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
