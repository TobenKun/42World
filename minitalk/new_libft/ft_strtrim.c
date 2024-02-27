/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:22:30 by sangshin          #+#    #+#             */
/*   Updated: 2023/10/15 18:15:46 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int	front_idx;
	int	back_idx;

	front_idx = 0;
	if (s1 == 0 || set == 0)
		return (0);
	back_idx = ft_strlen(s1) - 1;
	while (is_set(s1[front_idx], set))
		front_idx++;
	while (is_set(s1[back_idx], set))
		back_idx--;
	return (ft_substr(s1, front_idx, back_idx - front_idx + 1));
}

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
