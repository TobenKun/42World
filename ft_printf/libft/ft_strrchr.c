/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:44:50 by sangshin          #+#    #+#             */
/*   Updated: 2023/10/08 20:00:10 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		last_char;
	char	tmp;

	tmp = c;
	last_char = ft_strlen(s);
	while (last_char >= 0)
	{
		if (s[last_char] == tmp)
		{
			return ((char *)s + last_char);
		}
		last_char--;
	}
	return (0);
}
