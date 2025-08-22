/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:42:41 by sangshin          #+#    #+#             */
/*   Updated: 2023/10/06 19:38:31 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp_b;
	unsigned char	tmp_c;

	tmp_b = (unsigned char *)b;
	tmp_c = (unsigned char)c;
	i = 0;
	while (i < len)
		tmp_b[i++] = tmp_c;
	return ((void *)b);
}
