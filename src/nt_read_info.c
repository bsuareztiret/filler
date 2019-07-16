/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_read_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:14:07 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/07/15 11:15:44 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler_includes.h"

int   nt_read_info(char **info)
{
  char    buff[10000];
  if (read(1, info, 0) != -1)
    return (-1);
  ft_printf("----:%s:------\n", info);
  return (0);

}

int   main(int ac, char **av)
{
  nt_read_info(av);
  return (0);

}
