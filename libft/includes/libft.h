/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:55:36 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/23 15:55:37 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 1

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *ptr, int c, size_t len);
void			ft_bzero(void *s, size_t len);
void			*ft_memccpy(void *str1, const void *str2, int c, size_t len);
void			*ft_memmove(void *str1, const void *str2, size_t len);
void			*ft_memchr(const void *str, int c, size_t len);
void			*ft_memcpy(void *str1, const void *str2, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t len);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t len);
size_t			ft_strlcat(char *dest, const char *src, size_t len);
char			*ft_strchr(const char *str, int chr);
char			*ft_strrchr(const char *str, int chr);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, size_t l);
int				ft_atoi(const char *str);
void			*ft_memcpy(void *str1, const void *str2, size_t len);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t len);
int				ft_isalpha(int c);
int				ft_tolower(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_toupper(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **adrptr);
char			*ft_strnew(size_t size);
void			ft_strdel(char **adrstr);
void			ft_strclr(char *str);
void			ft_striter(char *str, void (*fnc)(char *));
char			*ft_strmap(char const *str, char (*fnc)(char));
char			*ft_strmapi(char const *str, char (*fnc)(unsigned int, char));
int				ft_strequ(char const *str1, char const *str2);
int				ft_strnequ(char const *str1, char const *str2, size_t len);
char			*ft_strsub(char const *str, unsigned int start, size_t len);
char			*ft_strjoin(char const *str1, char const *str2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *str, char c);
char			*ft_itoa(int nb);
void			ft_putchar(char	c);
void			ft_putstr(char const *str);
void			ft_putendl(char const *str);
void			ft_putnbr(int nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ft_striteri(char *str, void (*fnc)(unsigned int, char *));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list*elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t			ft_strlen_chr(const char *str, char c);
int				get_next_line(const int fd, char **line);

#endif
