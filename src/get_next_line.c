/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:37:01 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/10/08 21:32:19 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler_includes.h"

static int	ft_read(const int fd, char **str)
{
	int		i;
	char	*buffer;
	char	*rest;

	if (!(buffer = ft_strnew(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	i = read(fd, buffer, BUFF_SIZE);
	if (i > 0)
	{
		buffer[i] = '\0';
		if (!(rest = ft_strjoin(*str, buffer)))
			return (-1);
		free(*str);
		*str = rest;
	}
	free(buffer);
	return (i);
}

static int	get_line(char **line, char **end, char **str)
{
	if (!(*line = ft_strsub(*str, 0, ft_strlen(*str) - ft_strlen(*end))))
		return (-1);
	if (!(*end = ft_strdup(*end + 1)))
		return (-1);
	free(*str);
	*str = *end;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			i;
	static char	*str[OPEN_MAX];
	char		*end;

	if (fd < 0 || fd > OPEN_MAX || !line || \
			(!str[fd] && !(str[fd] = ft_strnew(0))))
		return (-1);
	while ((end = ft_strchr(str[fd], '\n')) == NULL)
	{
		i = ft_read(fd, &str[fd]);
		if (i == 0)
		{
			if (ft_strlen(str[fd]) == 0)
			{
				free(str[fd]);
				return (0);
			}
			str[fd] = ft_strjoin(str[fd], "\n");
		}
		if (i < 0)
			return (-1);
		else
			end = ft_strchr(str[fd], '\n');
	}
	return (get_line(line, &end, &str[fd]));
}
