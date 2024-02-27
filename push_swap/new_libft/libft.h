/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:16:31 by sangshin          #+#    #+#             */
/*   Updated: 2023/11/25 22:57:50 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_flag
{
	int		true_val;
	int		is_dot;
	int		type;
	int		width;
	int		precision;
	int		hash_sign;
	int		plus_space;
	int		minus_zero;
	int		word_count;
	int		total_len;
}				t_flag;	

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s1, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_printf(const char *s, ...);
int		format_print(char *string, va_list ap, t_flag *flag);
int		type_check(char c, t_flag *flag);
int		printc(t_flag *flag, va_list ap);
int		prints(t_flag *flag, va_list ap);
int		printp(t_flag *flag, va_list ap);
int		printd(t_flag *flag, va_list ap);
int		printu(t_flag *flag, va_list ap);
int		printx(t_flag *flag, va_list ap);
int		print_percent(t_flag *flag, va_list ap);
int		print_bigx(t_flag *flag, va_list ap);
int		fill_width(t_flag *flag, int len);
int		len_check(t_flag *flag, long long num, int base);
int		print_number(long long num, t_flag *flag, int base);
int		fill_precision_num(long tmp, t_flag *flag, int base);
int		fill_width_space(t_flag *flag, long tmp);
int		print_unum(unsigned long num, t_flag *flag, int base, long dividx);
int		ulen_check(t_flag *flag, unsigned long long tmp, int base);
int		minus_checker(t_flag *flag, long *tmp);
void	flag_check(char c, t_flag *flag);
void	read_number(char **s, t_flag *flag);

#endif
