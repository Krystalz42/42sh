/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:08:28 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/02 18:08:30 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <get_next_line.h>

# define ABS(x)	(x > 0 ? x : -x)

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RST   "\x1B[0m"

# define PRED   ft_putstr("\x1B[31m")
# define PGRN   ft_putstr("\x1B[32m")
# define PYEL   ft_putstr("\x1B[33m")
# define PBLU   ft_putstr("\x1B[34m")
# define PMAG   ft_putstr("\x1B[35m")
# define PCYN   ft_putstr("\x1B[36m")
# define PWHT   ft_putstr("\x1B[37m")
# define P_INV_FD(x)   ft_putstr_fd("\x1B[7m", x)
# define P_RST_FD(x)   ft_putstr_fd("\x1B[0m", x)

# define NL			ft_putchar('\n')
# define NBR(x)		ft_putnbr(x)
# define NBR_FD(x, y)		ft_putnbr_fd(x, y)
# define STR(x)		ft_putstr(x)
# define STR_FD(x, y)		ft_putstr_fd(x, y)
# define END(x)		ft_putendl(x)
# define CHAR(x)	ft_putchar(x)
# define CHAR_FD(x, y)	ft_putchar_fd(x, y)

# define BASE_HEX "0123456789ABCDEF"
# define BASE_DEC "0123456789"
# define BASE_OCT "01234567"
# define BASE_BIN "01"

typedef struct		s_remain
{
	int				fd;
	char			*content;
}					t_remain;

void				ft_memdel_tab(char ***ta);
char				**ft_str_to_tab(char *str);
char				*ft_str_charnoutrev(char const *s, char *l, size_t start);
char				*ft_strrev(char *str);
int					ft_recursive_power(int nb, int power);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
size_t				ft_tablen(char **ta);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(char const *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dst, char const *src);
char				*ft_strncat(char *dst, char const *src, size_t n);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *litle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_nbrlen(int nbr);
int					ft_atoi(const char *str);
unsigned int		ft_atoui(const char *str);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_firstchar(char *str, char c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t len);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *str, void (*f)(char *));
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_double_delete(char **tmp, char **tmp1);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_ustrncmp(const char *s1, const char *s2, size_t n);
char				*ft_strtrim(char const *s);
char				*ft_str_charout(char const *s, char *listc);
char				*ft_str_charnout(char const *s, char *listc, size_t start);
char				**ft_strsplit(char const *s1, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstrtab(char **ta, char separator);
void				ft_putstrtab_fd(char **ta, char separator, int fd);
t_list				*ft_lstcpy(t_list *list);
t_list				*ft_lstnew(const void *content, size_t size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
char				*ft_filetostr(char *filepath);
void				*ft_realloc(void **ptr, size_t oldsize, size_t newsize);
char				*ft_newcat(char *str1, char *str2);
char				**ft_split(const char *str, const char *separator);
int					ft_countchar(const char *s, char c);
void				ft_debug(int nb, int need);
int					ft_atoi_base(char *nbr, char *base);
char				*ft_convert_base(char *nbr, char *base_from, char *bas_to);
char				*ft_convert_ubase(char *nbr, char *base_from, char *bas_to);
unsigned int		ft_itounsigned(int n);
char				*ft_uitoa(unsigned int nbr);
char				*ft_ustoa(unsigned short nbr);
char				*ft_ulltoa(unsigned long long nbr);
char				*ft_ultoa(unsigned long nbr);
char				*ft_lltoa(long long nbr);
char				*ft_ltoa(long nbr);
char				*ft_ftoa(double nbr, size_t precision);
char				*ft_stoa(short nbr);
char				*ft_str_tolower(char *str);
char				*ft_str_toupper(char *str);
int					ft_chrchar(char *str, char chr);

#endif
