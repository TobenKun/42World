/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:50:28 by sangshin          #+#    #+#             */
/*   Updated: 2023/10/15 18:25:23 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *s, char c);
static int	ft_len_until_c(char	const *s, char c);
static void	ft_free_null(char **split);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_count;
	char	**tmp;

	i = -1;
	word_count = word_counter(s, c);
	tmp = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (tmp == 0)
		return (0);
	while (++i < word_count)
	{
		while (*s == c && *s)
			s++;
		tmp[i] = (char *)malloc(ft_len_until_c(s, c) + 1);
		if (tmp[i] == 0)
		{
			ft_free_null(tmp);
			return (0);
		}
		ft_strlcpy(tmp[i], s, ft_len_until_c(s, c) + 1);
		s += ft_len_until_c(s, c);
	}
	tmp[word_count] = 0;
	return (tmp);
}

static void	ft_free_null(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
}

static int	ft_len_until_c(char	const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	word_counter(char const *s, char c)
{
	int	i;
	int	res;

	i = 0;
	if (s == 0)
		return (0);
	res = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			res++;
		else if (s[i] != c && s[i + 1] == 0)
			res++;
		i++;
	}
	return (res);
}
