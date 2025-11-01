/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:47:43 by sangshin          #+#    #+#             */
/*   Updated: 2025/11/01 21:01:21 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	prints(t_flag *flag, va_list ap)
{
	char	*tmp;
	int		len;

	tmp = va_arg(ap, char *);
	if (tmp == 0)
		tmp = "(null)";
	len = ft_strlen(tmp);
	if ((int)ft_strlen(tmp) > flag->precision && flag->is_dot != 0)
		len = flag->precision;
	if (flag->minus_zero != '-')
		if (fill_width(flag, len) == -1)
			return (-1);
	if (write(1, tmp, len) < 0)
		return (-1);
	flag->total_len += len;
	if (flag->minus_zero == '-')
		if (fill_width(flag, len) == -1)
			return (-1);
	return (flag->total_len);
}

int	fill_width(t_flag *flag, int len)
{
	int	i;

	i = 0;
	while (flag->width > len + i++)
	{
		if (write(1, " ", 1) < 0)
			return (-1);
		flag->total_len++;
	}
	return (0);
}
