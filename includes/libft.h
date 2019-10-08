/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:06:00 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/10/06 21:53:05 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 32
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memchr(const void *src, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *src, int c, size_t len);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *dst, const char *src, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
char				*ft_strstr(const char *lab, const char *sol);
char				*ft_strnstr(const char *lab, const char *sol, size_t len);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(const char *str);
void				ft_putstr_fd(const char *str, int fd);
void				*ft_memalloc(size_t len);
void				ft_memdel(void **adr);
char				*ft_strnew(size_t len);
void				ft_strdel(char **adr);
void				ft_strclr(char *str);
void				ft_striter(char *str, void (*f)(char *));
void				ft_putendl(const char *str);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putnbr(int nbr);
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *str, char (*f)(char));
char				*ft_strmapi(const char *str, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t len);
char				*ft_strsub(const char *str, unsigned int start, size_t len);
void				ft_putnbr_fd(int nbr, int fd);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *str);
char				*ft_itoa(int nbr);
char				*ft_itoa_b(unsigned long long nbr, int base);
char				**ft_strsplit(const char *str, char c);
t_list				*ft_lstnew(const void *content, size_t conent_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *news);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					get_next_line(const int fd, char **line);

#endif
