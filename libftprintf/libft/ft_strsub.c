/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:06:58 by mcabrol           #+#    #+#             */
/*   Updated: 2018/10/25 20:26:43 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len > 0)
	{
		*(str + i) = *(s + start + i);
		i++;
		len--;
	}
	*(str + i + 1) = 0;
	return (str);
}
