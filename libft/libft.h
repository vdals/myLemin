/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:01:18 by jnydia            #+#    #+#             */
/*   Updated: 2019/09/16 15:52:19 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>

# define BUFF_SIZE 32
# define RET_VALUE(ret) ret > 0 ? 1 : ret

# define RED				"\x1b[31m"
# define GREEN				"\x1b[32m"
# define YELLOW				"\x1b[33m"
# define BLUE				"\x1b[34m"
# define MAGENTA			"\x1b[35m"
# define CYAN				"\x1b[36m"
# define RESET				"\x1b[0m"
# define ABS(i) (((i) < 0) ? -(i) : (i))
# define F_HH				1
# define F_H				2
# define F_L				3
# define F_LL				4
# define F_LD				5

typedef struct				s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}							t_list;

typedef    struct			s_arg
{
    char				*fmt;
    char				*s;
    char				c;
    long int			p;
    unsigned int		u_i;
    unsigned char		hha;
    unsigned short		ha;
    unsigned long long	lla;
    unsigned long long	ull;
    unsigned long		la;
    int					i;
    char				hhi;
    short				hi;
    long long			lli;
    long long			lls;
    long				li;
    int					lnint;
    int					flg;
    int					hsh;
    int					num;
    int					zero;
    int					space;
    int					space2;
    int					move;
    int					plus;
    int					minus;
    int					minus2;
    int					wiedth;
    int					point;
    int					star;
    int					und_beh;
    double				f;
    double				lf;
    long double			ld;
    long double			ldd;
    int					precision;
    char				*fstr;
    long double			head;
    long double			tail;
    int					l1;
    int					l2;
    long				i_h;
    int					counter;
}							t_arg;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_atoi(const char *str);
int 			ft_abs(int i);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strncat(char *dest, const char *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnstr(const char *haystack, \
		const char *needle, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_clean_array(char **array);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **qp);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
/*void			ft_strclr(char *s);*/
void			ft_striter(char *s, void (*f)(char *));
/*void			ft_putchar(char c);*/
void			ft_putchar_fd(char c, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
/*void			ft_putstr(char const *ptr);*/
void			ft_putstr_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strtrim(char const *s);
int				gwl(char const *str, char c);
char			**ft_strsplit(char const *s, char c);
int				ft_countwords(char const *str, char c);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ineg(int *n, int *neg);
char			*ft_itoa(int n);
char			*ft_strrev(char *str);
int				gla(int s);
int				get_next_line(const int fd, char **line);
int				ft_countword(char const *s, char c);
int				ft_printf(const char *format, ...);
int				ft_pow(int x, unsigned int y);
int				get_flag(t_arg *r, va_list ap, int ret);
int				ft_shorter_i(t_arg *r, va_list ap, int ret);
int				ft_print_base(t_arg *r, int sum);
int				pars(t_arg *r, va_list ap);
int				ft_putchar(char c);
int				ft_print_symb(t_arg *r, va_list ap);
int				ft_print_symb2(t_arg *r, va_list ap);
int				ft_putstr(const char *str);
void			print_base(unsigned long long num, unsigned \
				long long base);
void			print_base_i(long long num, long long base);
void			print_base_high(unsigned long long num, unsigned \
				long long base);
int				length_of_num(unsigned long long int i, int base);
int				length_of_num_i(long long int i, int base);
int				ft_print_hash(t_arg *r);
int				shorter_u_i(t_arg *r, int base, int sum);
int				shorter_u_i_high(t_arg *r, int base, int sum);
int				shorter_i(t_arg *r, int base, int sum);
int				ft_check_hash(t_arg *r);
int				ft_check_zero(t_arg *r);
int				ft_check_num(t_arg *r);
int				ft_check_space(t_arg *r);
int				ft_check_plus(t_arg *r);
int				ft_check_minus(t_arg *r);
int				ft_check_star(va_list ap, t_arg *r);
int				ft_check_undefined_behavior(t_arg *r);
int				ft_size_print(t_arg *r, int length);
int				ft_size_print2(t_arg *r, int length);
int				ft_size_print_minus(t_arg *r, int length);
void			ft_check_wiedth(t_arg *r);
int				ft_putstr2(const char *str, int size);
int				ft_putstr3(const char *str, int size);
int				ft_shorter_f(t_arg *r, va_list ap, int ret);
int				shorter_f(t_arg *r, int sum);
char			*ft_ltoa(int length, t_arg *r);
int				check_hash_help(t_arg *r);
int				m_s_u_i_high2(t_arg *r, int base, int sum);
int				h1_u_i_high2(t_arg *r, int base, int sum);
int				h1_u_i_high3(t_arg *r, int sum);
int				wiedth_help_i2(t_arg *r, int sum);
int				helper_i2(t_arg *r, int sum);
int				ft_print_symb22(t_arg *r, int sum);
int				ft_print_ptr2(t_arg *r, int sum);
int				ft_print_ptr3(t_arg *r, int sum);
int				ft_print_ptr4(t_arg *r, int sum);
int				ft_print_str2(t_arg *r, int sum);
int				ft_print_str3(t_arg *r, int sum);
int				ft_print_str4(t_arg *r);
int				m_s_u_i2(t_arg *r, int sum);
int				h1_u_i2(t_arg *r, int base, int sum);
int				h1_u_i3(t_arg *r, int sum);
int				h1_u_i4(t_arg *r, int sum);
int				h1_u_i5(t_arg *r, int base, int sum);
int				h1_u_i6(t_arg *r, int base, int sum);

#endif
