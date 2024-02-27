/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:01:45 by sangshin          #+#    #+#             */
/*   Updated: 2023/10/10 18:30:30 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rec_itoa(char *arr, long long int n, int index);

char	*ft_itoa(int n)
{
	int		len;
	int		tmp;
	char	*result;

	tmp = n;
	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (tmp / 10)
	{
		len++;
		tmp /= 10;
	}
	result = (char *)malloc(len + 3);
	if (result == 0)
		return (0);
	return (rec_itoa(result, (long long int)n, len));
}

static char	*rec_itoa(char *arr, long long int n, int index)
{
	if (n < 0)
	{
		arr[0] = '-';
		n *= -1;
		index++;
	}
	if (n == 0)
		return (arr);
	rec_itoa(arr, n / 10, index - 1);
	arr[index] = n % 10 + '0';
	arr[index + 1] = 0;
	return (arr);
}
