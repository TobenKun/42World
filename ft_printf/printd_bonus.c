/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:06:58 by sangshin          #+#    #+#             */
/*   Updated: 2023/11/08 23:03:19 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	printd(t_flag *flag, va_list ap)
{
	long	tmp;

	tmp = va_arg(ap, int);
	flag->word_count = len_check(flag, (long long)tmp, 10);
	if (flag->minus_zero == '0' && flag->is_dot != 0)
		flag->minus_zero = 0;
	if (flag->minus_zero == 0)
		if (fill_width_space(flag, tmp) == -1)
			return (-1);
	if (minus_checker(flag, &tmp) == -1)
		return (-1);
	else if (flag->true_val >= 0 && flag->plus_space != 0)
		if (write(1, &flag->plus_space, 1) < 0 || 0 * flag->total_len++)
			return (-1);
	if (flag->minus_zero == '0')
		if (fill_width_space(flag, tmp) == -1)
			return (-1);
	if (fill_precision_num(tmp, flag, 10) < 0)
		return (-1);
	if (flag->minus_zero == '-')
		return (fill_width_space(flag, tmp));
	return (flag->total_len);
}

int	fill_precision_num(long tmp, t_flag *flag, int base)
{
	int	i;

	i = 0;
	if (len_check(flag, (long long )tmp, base) >= flag->precision)
	{
		if (flag->type == 'u' || flag->type == 'x' || flag->type == 'X')
			return (print_unum(tmp, flag, base, 1));
		return (print_number((long long)tmp, flag, base));
	}
	while (flag->precision - len_check(flag, tmp, base) > i++)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		flag->total_len++;
	}
	if (flag->type == 'u' || flag->type == 'x' || flag->type == 'X')
		return (print_unum(tmp, flag, base, 1));
	return (print_number(tmp, flag, base));
}

int	fill_width_space(t_flag *flag, long tmp)
{
	int		i;
	int		len;
	char	space;

	i = 0;
	space = ' ';
	if (flag->minus_zero == '0' && flag->precision == 0)
		space = '0';
	len = flag->word_count;
	if (flag->word_count < flag->precision)
		len = flag->precision;
	if ((tmp < 0 || (flag->plus_space != 0 && flag->true_val >= 0))
		&& (flag->type != 'x' && flag->type != 'X'))
		len++;
	while (flag->width > len + i++)
	{
		if (write(1, &space, 1) < 0)
			return (-1);
		flag->total_len++;
	}
	return (flag->total_len);
}

int	len_check(t_flag *flag, long long num, int base)
{
	int			len;
	long long	dividx;

	dividx = 1;
	len = 0;
	while (num / dividx)
	{
		dividx *= base;
		len++;
	}
	if (flag->is_dot == 1 && flag->precision == 0)
		return (len);
	if (len == 0)
		len++;
	return (len);
}

int	print_number(long long num, t_flag *flag, int base)
{
	char			*numbers;
	long long		dividx;

	numbers = "0123456789abcdef";
	if (num == 0 && flag->is_dot == 1 && flag->precision == 0)
		return (0);
	if (num == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		return (++(flag->total_len));
	}
	dividx = 1;
	while (num / dividx >= (long long)base)
		dividx *= base;
	while (dividx)
	{
		if (write(1, &numbers[num / dividx], 1) < 0)
			return (-1);
		num = num % dividx;
		dividx = dividx / base;
		flag->total_len++;
	}
	return (0);
}
