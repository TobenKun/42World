/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:34:24 by sangshin          #+#    #+#             */
/*   Updated: 2023/11/08 21:33:01 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printx(t_flag *flag, va_list ap)
{
	unsigned int	tmp;

	tmp = va_arg(ap, int);
	flag->word_count = len_check(flag, tmp, 16);
	if (flag->minus_zero == '0' && flag->is_dot != 0)
		flag->minus_zero = 0;
	if (flag->precision > flag->word_count)
		flag->word_count = flag->precision;
	if (flag->hash_sign == 1 && tmp != 0)
		flag->word_count += 2;
	if (flag->minus_zero == 0)
		if (fill_width_space(flag, tmp) == -1)
			return (-1);
	if (flag->hash_sign != 0 && tmp != 0)
		if (write(1, "0x", 2) < 0 * (flag->total_len++) * (flag->total_len++))
			return (-1);
	if (flag->minus_zero == '0')
		if (fill_width_space(flag, tmp) == -1)
			return (-1);
	if (fill_precision_num(tmp, flag, 16) < 0)
		return (-1);
	if (flag->minus_zero == '-')
		if (fill_width_space(flag, tmp) == -1)
			return (-1);
	return (flag->total_len);
}
