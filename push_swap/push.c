/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:09:00 by sangshin          #+#    #+#             */
/*   Updated: 2023/12/25 17:04:28 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stacks, int caller)
{
	t_stack	*tmp;

	if (stacks->b_head == 0)
		return ;
	if (stacks->a_head == 0)
		push_first(stacks, 0);
	else
		add_front(&stacks->a_head, stacks->b_head->content);
	if (stacks->b_head->next)
	{
		stacks->b_head->next->prev = 0;
		tmp = stacks->b_head;
		stacks->b_head = stacks->b_head->next;
		free(tmp);
	}
	else
	{
		free(stacks->b_head);
		stacks->b_head = 0;
		stacks->b_tail = 0;
	}
	if (caller == 0)
		ft_printf("pa\n");
}

void	push_b(t_stacks *stacks, int caller)
{
	t_stack	*tmp;

	if (stacks->a_head == 0)
		return ;
	if (stacks->b_head == 0)
		push_first(stacks, 1);
	else
		add_front(&stacks->b_head, stacks->a_head->content);
	if (stacks->a_head->next)
	{
		stacks->a_head->next->prev = 0;
		tmp = stacks->a_head;
		stacks->a_head = stacks->a_head->next;
		free(tmp);
	}
	else
	{
		free(stacks->a_head);
		stacks->a_head = 0;
		stacks->a_tail = 0;
	}
	if (caller == 0)
		ft_printf("pb\n");
}

void	push_first(t_stacks *stacks, int to_where)
{
	if (to_where == 0)
	{
		stacks->a_head = ft_calloc(1, sizeof(t_stack));
		if (stacks->a_head == 0)
			exit(1);
		stacks->a_head->content = stacks->b_head->content;
		stacks->a_tail = stacks->a_head;
	}
	else
	{
		stacks->b_head = ft_calloc(1, sizeof(t_stack));
		if (stacks->b_head == 0)
			exit(1);
		stacks->b_head->content = stacks->a_head->content;
		stacks->b_tail = stacks->b_head;
	}
}
