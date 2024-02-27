/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:31:45 by sangshin          #+#    #+#             */
/*   Updated: 2023/11/25 22:58:50 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printp(t_flag *flag, va_list ap)
{
	void	*tmp;

	tmp = va_arg(ap, void *);
	flag->word_count = ulen_check(flag, (unsigned long long)tmp, 16) + 2;
	if (flag->minus_zero != '-')
		if (fill_width(flag, flag->word_count) == -1)
			return (-1);
	if (write(1, "0x", 2) < 0
		|| print_unum((unsigned long long)tmp, flag, 16, 1) < 0)
		return (-1);
	flag->total_len += 2;
	if (flag->minus_zero == '-')
		if (fill_width(flag, flag->word_count) == -1)
			return (-1);
	return (flag->total_len);
}

int	ulen_check(t_flag *flag, unsigned long long tmp, int base)
{
	unsigned long long	dividx;
	int					len;

	dividx = 1;
	len = 0;
	while (tmp)
	{
		tmp /= base;
		len++;
	}
	if (flag->is_dot == 1 && flag->precision == 0)
		return (len);
	if (len == 0)
		len++;
	return (len);
}

int	print_unum(unsigned long num, t_flag *flag, int base, long dividx)
{
	char		*numbers;

	numbers = "0123456789abcdef";
	if (num == 0 && flag->is_dot == 1 && flag->precision == 0)
		return (0);
	if (flag->type == 'X')
		numbers = "0123456789ABCDEF";
	if (num == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		return (++(flag->total_len));
	}
	while (num / dividx >= (unsigned long)base)
		dividx *= base;
	while (dividx)
	{
		if (write(1, &numbers[num / dividx], 1) < 0)
			return (-1);
		num = num % dividx;
		dividx /= base;
		flag->total_len++;
	}
	return (0);
}
