/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:47:06 by stestein          #+#    #+#             */
/*   Updated: 2018/06/22 13:20:33 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define STEVEN int i = 0; int w = 0; int pos = 0; char *str;
# define TRIM 	int i = 0; char *str; int n = 0;
# define BUFF_SIZE 1024

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

# define ABS(a) (val * ((val > 0) * 2 - 1))
# define ARRLEN(a) (sizeof(a)/sizeof(a[0]))
# define EVEN(n) (n % 2 == 0)
# define ODD(n) (n % 2 == 1)
# define ISSPACE(a) ((a >= 9 && a <= 13) || (a == 32))
# define ISALPHA(a) (((unsigned)a | 32) - 97 < 26u)
# define ISASCII(a) ((unsigned)a < 128u)
# define ISDIGIT(a) (((unsigned)a-48) < 10u)
# define ISALNUM(a) (ISALPHA(a) || ISDIGIT(a))
# define ISPRINT(a) (((unsigned)a - 32) < 95u)
# define TOLOWER(a) (((unsigned)a- 65) < 26u ? a + 32 : a)
# define TOUPPER(a) (((unsigned)a - 97) < 26u ? a - 32 : a)
# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define MIN(a, b) (((a) < (b)) ? (a) : (b))
# define FAILED -1
# define SUCCESS 0

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_data
{
	char			*last;
	int				fd;
	struct s_data	*next;
	int				end;
}					t_data;

typedef struct		s_libft
{
	int				i;
	unsigned char	a;
	uintmax_t		intmx;
	intmax_t		size;
	char			*ret;
	void			*new_ptr;
}					t_libft;

typedef	struct		s_uimax
{
	uintmax_t		i_val;
	size_t			size;
	char			*retrn;
}					t_uimax;

int					ft_abs(int n);
void				ft_splitdel(char ***split);
size_t				ft_num_words(const char *str, char sep);
int					ft_strchrpos(const char *s, int c);
int					get_next_line(int const fd, char **line);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t len);
int					ft_isalpha(int x);
int					ft_isdigit(int x);
int					ft_isalnum(int x);
int					ft_isascii(int x);
int					ft_isprint(int x);
int					ft_toupper(int x);
int					ft_tolower(int x);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, char *src, size_t dstsize);
char				*ft_strstr(const char *str, const char *to_find);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int x, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_strclr(char *s);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
char				ft_piscine(char const *str);
char				ft_youtube(char const *str);
char				*ft_skipspace(char *str);
char				*ft_strrev(char *str);
int					*ft_range(int min, int max);
char				*ft_strndup(const char *src, size_t len);
size_t				ft_findchr(const char *s, int c);
void				*ft_realloc(void *ptr, size_t src_size, size_t new_size);
void				*ft_recalloc(void *ptr, size_t src_size, size_t new_size);
char				*ft_itoa_base(int value, int base);
char				*ft_imaxtoa(intmax_t value);
int					ft_isnan(double num);
void				ft_insrt_to_str(char **s1, char *s2);
char				*ft_uimaxtoa_base(uintmax_t value, int8_t base,
															const char *str);
#endif
