/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_includes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:23:43 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/08/29 20:33:08 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_INCLUDES_H
# define FILLER_INCLUDES_H
# define BUFF_SIZE 32
# include <limits.h>
# include "libftprintf.h"

typedef struct		s_padding
{
	int				start;
	int				stop;
	int				zero;
	char			*prefix;
}					t_padding;

int		get_next_line(const int fd, char **line);

#endif
