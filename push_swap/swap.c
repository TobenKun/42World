/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:08:13 by sangshin          #+#    #+#             */
/*   Updated: 2023/12/25 17:09:27 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks, int caller)
{
	int	tmp;

	if (stacks->a_head == 0 || stacks->a_head->next == 0)
		return ;
	tmp = stacks->a_head->content;
	stacks->a_head->content = stacks->a_head->next->content;
	stacks->a_head->next->content = tmp;
	if (caller == 0)
		ft_printf("sa\n");
}

void	swap_b(t_stacks *stacks, int caller)
{
	int	tmp;

	if (stacks->b_head == 0 || stacks->b_head->next == 0)
		return ;
	tmp = stacks->b_head->content;
	stacks->b_head->content = stacks->b_head->next->content;
	stacks->b_head->next->content = tmp;
	if (caller == 0)
		ft_printf("sb\n");
}

void	swap_both(t_stacks *stacks, int caller)
{
	int	tmp;

	if (stacks->a_head == 0 || stacks->a_head->next == 0)
		return ;
	tmp = stacks->a_head->content;
	stacks->a_head->content = stacks->a_head->next->content;
	stacks->a_head->next->content = tmp;
	if (stacks->b_head == 0 || stacks->b_head->next == 0)
		return ;
	tmp = stacks->b_head->content;
	stacks->b_head->content = stacks->b_head->next->content;
	stacks->b_head->next->content = tmp;
	if (caller == 0)
		ft_printf("ss\n");
}
