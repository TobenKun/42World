/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:29:52 by sangshin          #+#    #+#             */
/*   Updated: 2023/11/08 23:03:07 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	printc(t_flag *flag, va_list ap)
{
	char	tmp;
	int		i;

	i = 0;
	tmp = va_arg(ap, int);
	while (i++ < flag->width - 1 && flag->minus_zero != '-')
	{
		if (write(1, " ", 1) < 0)
			return (-1);
		flag->total_len++;
	}
	if (write(1, &tmp, 1) < 0)
		return (-1);
	flag->total_len++;
	i = 0;
	while (i++ < flag->width - 1 && flag->minus_zero == '-')
	{
		if (write(1, " ", 1) < 0)
			return (-1);
		flag->total_len++;
	}
	return (flag->total_len);
}

int	print_percent(t_flag *flag, va_list ap)
{
	int		i;
	char	space;

	space = ' ' * (flag->minus_zero != '0') + '0' * (flag->minus_zero == '0');
	i = 0;
	if (flag->minus_zero != '-')
		while (flag->width - 1 > i++)
			if (write(1, &space, 1) < (0 * (long long)ap)
				|| 0 * flag->total_len++)
				return (-1);
	if (write (1, "%", 1) < 0)
		return (-1);
	i = 0;
	if (flag->minus_zero == '-')
		while (flag->width - 1 > i++)
			if (write(1, &space, 1) < 0 || 0 * flag->total_len++)
				return (-1);
	return (++(flag->total_len));
}
