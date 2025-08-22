/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:47:32 by sangshin          #+#    #+#             */
/*   Updated: 2023/10/15 18:11:29 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (s1 == 0)
		return (0);
	if (start >= ft_strlen(s1))
		return (ft_strdup(""));
	if (ft_strlen(s1) - start < len)
		len = ft_strlen(s1) - start;
	tmp = (char *)malloc(len + 1);
	if (tmp == 0)
		return (0);
	while (i < len && s1[i + start])
	{
		tmp[i] = s1[i + start];
		i++;
	}
	tmp[len] = 0;
	return (tmp);
}
