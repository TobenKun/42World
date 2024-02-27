/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:57:13 by sangshin          #+#    #+#             */
/*   Updated: 2023/10/16 17:21:38 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	tmp_c;

	i = 0;
	tmp_c = c;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == tmp_c)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (NULL);
}
/* 
 * this function will not work with NULL as both params with size
 * original memcpy does not work too.
 * this will be useful for programmers to fix thier code.
*/
