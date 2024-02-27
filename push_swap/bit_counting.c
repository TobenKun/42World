/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_counting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:30:15 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/11 16:39:05 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bit_count(int num_tmp)
{
	int				bit;
	unsigned int	num;

	bit = 0;
	num = num_tmp;
	while (num != 0)
	{
		num &= num - 1;
		bit++;
	}
	return (bit);
}

int	extra_bit_count(int num, int mod, int type)
{
	int	magic_num;

	magic_num = 0;
	if (type == 0)
	{
		mod--;
		while (mod >= 0)
		{
			magic_num += (1 << mod);
			mod--;
		}
	}
	else
	{
		mod++;
		while (mod <= 31)
		{
			magic_num += (1 << mod);
			mod++;
		}
	}
	num &= magic_num;
	return (bit_count(num));
}
