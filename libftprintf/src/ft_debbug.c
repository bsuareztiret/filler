/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debbug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:11:45 by mcabrol           #+#    #+#             */
/*   Updated: 2019/06/26 16:40:55 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_info(t_info *tmp)
{
	printf("\n\nhash = %d\n", tmp->hash);
	printf("plus = %d\n", tmp->plus);
	printf("minus = %d\n", tmp->minus);
	printf("space = %d\n", tmp->space);
	printf("zero = %d\n", tmp->zero);
	printf("width = %d\n", tmp->width);
	printf("precision = %d\n", tmp->precision);
	printf("cast = %d\n", tmp->cast);
}

void	ft_print_padding(t_padding padding)
{
	printf("\n\nstart = %d\n", padding.start);
	printf("stop = %d\n", padding.stop);
	printf("zero = %d\n", padding.zero);
	printf("prefix = %s\n", padding.prefix);
}

void	ft_ping(void)
{
	ft_putendl("###PING###");
}

void	ft_p(char *str)
{
	printf("\n\nadr = %p\n", &str);
}
