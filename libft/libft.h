/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:19:51 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 20:26:06 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isalpha(int alpha);
int			ft_isdigit(int Num);
int			ft_isalnum(int alnum);
int			ft_isascii(int asc);
int			ft_isprint(int printable);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *dest, int charac, size_t len);
void		ft_bzero(void *string, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *string, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char const *string, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *string, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *string, char (*f)(unsigned int, char));
void		ft_striteri(char *string, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *string, int fd);
void		ft_putendl_fd(char *string, int fd);
void		ft_putnbr_fd(int n, int fd);
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_lst;
typedef int		(*t_cmpfn)(void *, void *);
typedef void	(*t_delfn)(void *);
t_lst		*ft_lstnew(void *content);
void		ft_lstadd_front(t_lst **alst, t_lst *new);
int			ft_lstsize(t_lst *lst);
t_lst		*ft_lstlast(t_lst *lst);
void		ft_lstadd_back(t_lst **alst, t_lst *new);
void		ft_lstdelone(t_lst *lst, void (*del)(void *));
void		ft_lstclear(t_lst **lst, void (*del)(void *));
void		ft_lstiter(t_lst *lst, void (*f)(void *));
t_lst		*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *));
//
void		lst_put_orderly_sorted(t_lst **lst, t_lst *new);
void		lst_put_orderly_new(t_lst **lst, t_lst *new, t_cmpfn cmpfn);
size_t		ft_strspn(const char *string, const char *charset);
char		*ft_strsep(char **str, const char *sep);
int			ft_strnlen(const char *str, int n);
size_t		ft_strcspn(const char *string, const char *charset);
int			ft_strcmp(char *s1, char *s2);
void		ft_lstrm(t_lst **lst, t_lst *to_rm);
t_lst		*lst_put_orderly(t_lst **lst, char *d_name);
long long	ft_atoll(const char *str);

#endif
