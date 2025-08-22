/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:45:18 by sangshin          #+#    #+#             */
/*   Updated: 2023/10/11 15:48:50 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_end;

	i = 0;
	dst_end = ft_strlen(dst);
	if (dstsize < dst_end)
		return (dstsize + ft_strlen(src));
	while (i + 1 + dst_end < dstsize && src[i])
	{
		dst[dst_end + i] = src[i];
		i++;
	}
	dst[dst_end + i] = 0;
	return (dst_end + ft_strlen(src));
}
