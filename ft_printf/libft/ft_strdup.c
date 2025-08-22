/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:41:07 by sangshin          #+#    #+#             */
/*   Updated: 2023/10/15 21:02:14 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		srclen;
	char	*result;

	srclen = ft_strlen(s1);
	result = (char *)malloc(srclen + 1);
	if (result == 0)
		return (0);
	result[srclen] = 0;
	while (--srclen >= 0)
	{
		result[srclen] = s1[srclen];
	}
	return (result);
}
