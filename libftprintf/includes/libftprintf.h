/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:47:49 by mcabrol           #+#    #+#             */
/*   Updated: 2019/10/08 21:22:49 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <wchar.h>
# include "../libft/libft.h"
# include "colors.h"

# define BUFFSIZE		1000

enum				e_cast
{
	NONE,
	H,
	HH,
	L,
	LL,
	D,
	J,
	Z
};

typedef	union		u_sign
{
	double			dd;
	int64_t			u;
}					t_sign;

typedef struct		s_padding
{
	int				start;
	int				stop;
	int				zero;
	char			*prefix;
}					t_padding;

typedef	struct		s_info
{
	int				res;
	int				buffer;
	int				hash;
	int				plus;
	int				minus;
	int				space;
	int				zero;
	int				precision;
	int				width;
	int				cast;
	char			type;
}					t_info;

int					ft_printf(const char *restrict format, ...);
int					ft_start(const char *format, va_list arg, char *buff);
int					ft_stop(char c, t_info *tmp, va_list arg, char *buff);
void				ft_print(va_list arg, t_info *tmp, char *buff);
void				ft_colors(const char *format, char *buffer, int *i,
					t_info *tmp);

char				*ft_parse_colors(int start, int end, const char *format);
int					ft_is_colors(char *str);
void				ft_put_colors(char *str, char *buff, t_info *tmp, int *i);

void				ft_format(char c, char *buff, t_info *tmp);
void				ft_strformat(char *str, char *buff, t_info *tmp);

void				ft_handle_d(t_padding *padding, t_info *tmp,
					intmax_t nbr, char *str);
void				ft_handle_f(t_padding *padding, t_info *tmp,
					long double nbr, char *str);
t_padding			ft_handle_c(t_info *tmp);
t_padding			ft_handle_x(t_info *tmp, char *str, int nbr);
t_padding			ft_handle_o(t_info *tmp, char *str);
t_padding			ft_handle_s(t_info *tmp, char *str);
t_padding			ft_handle_u(t_info *tmp, char *str);

char				*ft_precision_s(t_info *tmp, char *str, int *del);

void				ft_print_c(int c, t_info *tmp, char *buff);

void				ft_print_d(t_padding *padding, char *str,
					char *buff, t_info *tmp);
void				ft_print_o(t_padding *padding, char *str,
					char *buff, t_info *tmp);
void				ft_print_u(t_padding *padding, char *str,
					char *buff, t_info *tmp);
void				ft_print_s(t_padding *padding, char *str,
					char *buff, t_info *tmp);
void				ft_print_x(t_padding *padding, char *str,
					char *buff, t_info *tmp);
void				ft_print_f(t_padding *padding, char *str,
					char *buff, t_info *tmp);

void				ft_type_d(va_list arg, t_info *tmp, char *buff);
void				ft_type_c(va_list arg, t_info *tmp, char *buff);
void				ft_type_s(va_list arg, t_info *tmp, char *buff);
void				ft_type_o(va_list arg, t_info *tmp, char *buff);
void				ft_type_u(va_list arg, t_info *tmp, char *buff);
void				ft_type_x(va_list arg, t_info *tmp, char *buff);
void				ft_type_f(va_list arg, t_info *tmp, char *buff);

int					ft_is_type(char c);
int					ft_is_flag(char c);
int					ft_is_cast(char c);

void				ft_parse(const char *format, t_info *tmp, int *i);
int					ft_parse_precision(const char *format, int *i);
int					ft_parse_cast(const char *format, int *i, int precast);
void				ft_parse_flag(char flag, t_info *tmp);

intmax_t			ft_cast_d(t_info *tmp, va_list arg);
intmax_t			ft_cast_x(t_info *tmp, va_list arg);
intmax_t			ft_cast_u(t_info *tmp, va_list arg);
uintmax_t			ft_cast_o(t_info *tmp, va_list arg);
long double			ft_cast_f(t_info *tmp, va_list arg);

char				*ft_itoa_b(unsigned long long nbr, int base);
char				*ft_ltoa(intmax_t n);
char				*ft_float(long double nbr, int precision);
char				*ft_sign(t_info *tmp, t_padding *padding, char *str,
					long double f);
char				*ft_strtoupper(char *str);
void				ft_null(t_info *tmp, char **str);
void				ft_print_info(t_info *tmp);
void				ft_print_padding(t_padding padding);
void				ft_ping(void);
void				ft_p(char *str);

t_info				ft_init_tmp(int res, int buffsize);
t_padding			ft_init_padding(void);
t_sign				ft_init_sign(void);

#endif
