/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:27:08 by akhanye           #+#    #+#             */
/*   Updated: 2017/07/26 14:37:38 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# define MAX_BUFFER 5000
# define BUFF_SIZE	32

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_htoi(const char *nptr);
int					ft_getlines(char *filename);
int					ft_abs(int num);
int					get_next_line(int fd, char **line);
void				ft_putstr(const char *str);
void				ft_putchar(char c);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putnbr(int num);
size_t				ft_strlen(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
char				*ft_strdup(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
int					ft_isnumbers(char *str);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t len);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				ft_printallhex(unsigned char *bytes, size_t sz);
void				ft_printhex(unsigned char c);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strtrim(const char *str);
char				*ft_strnstr(const char *hay, const char *needle, size_t sz);
int					ft_isascii(int c);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_putcharmem(char *s);
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
void				ft_toupmem(unsigned int c, char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *str, unsigned int start, size_t len);
char				*ft_strjoin(char *dest, const char *src);
char				**ft_strsplit(char const *s, char c);
int					ft_digits(int num);
char				*ft_itoa(int n);
void				ft_putendl(const char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putnbr_fd(int num, int fd);
void				ft_strdel(char **as);
unsigned char		*ft_memdup(const unsigned char *mem, size_t sz);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_putline();
int					ft_skipempty(const char *s);
int					ft_lastal(const char *str);
char				*ft_strcpysub(char *d, const char *src, int s, int l);
void				ft_memdel(void **ap);
int					ft_inarray(char *search, char **array);
int					ft_inarrayc(char search, char **array);
void				ft_freestrsplit(char **str);

#endif
