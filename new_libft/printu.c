/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:44:24 by sangshin          #+#    #+#             */
/*   Updated: 2023/11/25 22:59:02 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printu(t_flag *flag, va_list ap)
{
	unsigned int	tmp;

	tmp = va_arg(ap, int);
	flag->word_count = ulen_check(flag, tmp, 10);
	if (flag->minus_zero == '0' && flag->is_dot != 0)
		flag->minus_zero = 0;
	if (flag->minus_zero != '-')
		if (fill_width_space(flag, tmp) == -1)
			return (-1);
	if (fill_precision_num(tmp, flag, 10) < 0)
		return (-1);
	if (flag->minus_zero == '-')
		if (fill_width_space(flag, tmp) == -1)
			return (-1);
	return (flag->total_len);
}

int	minus_checker(t_flag *flag, long *tmp)
{
	if ((*tmp) < 0)
	{
		flag->true_val = *tmp;
		if (write(1, "-", 1) < 0)
			return (-1);
		(*tmp) *= -1;
		flag->total_len++;
		flag->width--;
	}
	return (0);
}
