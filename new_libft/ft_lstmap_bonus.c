/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:20:48 by sangshin          #+#    #+#             */
/*   Updated: 2023/10/16 20:13:14 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	void	*new_content;
	t_list	*node_tmp;

	map = 0;
	if (f == 0 || del == 0)
		return (0);
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			ft_lstclear(&map, del);
			return (0);
		}
		node_tmp = ft_lstnew(new_content);
		if (node_tmp == 0)
		{
			if (new_content)
				del(new_content);
		}
		ft_lstadd_back(&map, node_tmp);
		lst = lst->next;
	}
	return (map);
}
