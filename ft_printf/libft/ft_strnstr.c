/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:43:47 by sangshin          #+#    #+#             */
/*   Updated: 2023/10/10 14:56:52 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp(char *s1, char *s2);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[i] == 0)
		return ((char *)haystack);
	while (*haystack != 0 && i + ft_strlen(needle) <= len)
	{
		if (ft_strcmp((char *)needle, (char *)haystack) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (0);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
/*
 * ex) ft_strnstr("abcdef", "abcdef", 3); -> this returns 0
 * because there is no "abcdef" in "abc"
 */
