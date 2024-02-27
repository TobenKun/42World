/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:25:46 by sangshin          #+#    #+#             */
/*   Updated: 2023/10/08 18:56:03 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tmp;

	i = 0;
	tmp = c;
	while (s[i])
	{
		if (s[i] == tmp)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (s[i] == 0 && tmp == 0)
		return ((char *)s + i);
	return (0);
}
