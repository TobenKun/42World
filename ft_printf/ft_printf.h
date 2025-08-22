/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:56:23 by sangshin          #+#    #+#             */
/*   Updated: 2023/11/08 21:46:24 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

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
