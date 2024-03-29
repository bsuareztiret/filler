/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:54:18 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/16 15:01:31 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_format(char c, char *buff, t_info *tmp)
{
	if (tmp->res >= BUFFSIZE)
	{
		write(1, buff, tmp->res);
		ft_bzero(buff, BUFFSIZE);
		tmp->res = 0;
		(tmp->buffer)++;
	}
	buff[tmp->res] = c;
	(tmp->res)++;
}

void		ft_strformat(char *str, char *buff, t_info *tmp)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			ft_format(str[i], buff, tmp);
			i++;
		}
	}
}
