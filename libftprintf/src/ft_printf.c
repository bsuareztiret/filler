/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:13:44 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/16 15:56:50 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list			arg;
	int				i;
	char			*buff;

	i = 0;
	buff = (char *)malloc(sizeof(char) * BUFFSIZE);
	va_start(arg, format);
	ft_bzero(buff, BUFFSIZE);
	i = ft_start(format, arg, buff);
	va_end(arg);
	return (i);
}

void	ft_print(va_list arg, t_info *tmp, char *buff)
{
	if (tmp->type == '%')
		return (ft_print_c('%', tmp, buff));
	else if (tmp->type == 'd' || tmp->type == 'i' || tmp->type == 'D')
		return (ft_type_d(arg, tmp, buff));
	else if (tmp->type == 'c' || tmp->type == 'C')
		return (ft_type_c(arg, tmp, buff));
	else if (tmp->type == 's' || tmp->type == 'S')
		return (ft_type_s(arg, tmp, buff));
	else if (tmp->type == 'o' || tmp->type == 'O')
		return (ft_type_o(arg, tmp, buff));
	else if (tmp->type == 'u' || tmp->type == 'U')
		return (ft_type_u(arg, tmp, buff));
	else if (tmp->type == 'x' || tmp->type == 'X' || tmp->type == 'p')
		return (ft_type_x(arg, tmp, buff));
	else if (tmp->type == 'f' || tmp->type == 'F')
		return (ft_type_f(arg, tmp, buff));
	else
		return ;
}
