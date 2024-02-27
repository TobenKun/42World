/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:13:33 by sangshin          #+#    #+#             */
/*   Updated: 2023/12/25 16:30:56 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stacks *stacks, int caller)
{
	t_stack	*new_tail;

	if (stacks->a_head == 0 || stacks->a_tail->prev == 0)
		return ;
	new_tail = stacks->a_tail->prev;
	new_tail->next = 0;
	stacks->a_tail->prev = 0;
	stacks->a_tail->next = stacks->a_head;
	stacks->a_head->prev = stacks->a_tail;
	stacks->a_head = stacks->a_tail;
	stacks->a_tail = new_tail;
	if (caller == 0)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stacks *stacks, int caller)
{
	t_stack	*new_tail;

	if (stacks->b_head == 0 || stacks->b_tail->prev == 0)
		return ;
	new_tail = stacks->b_tail->prev;
	new_tail->next = 0;
	stacks->b_tail->prev = 0;
	stacks->b_tail->next = stacks->b_head;
	stacks->b_head->prev = stacks->b_tail;
	stacks->b_head = stacks->b_tail;
	stacks->b_tail = new_tail;
	if (caller == 0)
		ft_printf("rrb\n");
}

void	reverse_rotate_both(t_stacks *stacks, int caller)
{
	t_stack	*new_tail;

	if (stacks->a_head == 0 || stacks->a_tail->prev == 0)
		return ;
	if (stacks->b_head == 0 || stacks->b_tail->prev == 0)
		return ;
	new_tail = stacks->a_tail->prev;
	new_tail->next = 0;
	stacks->a_tail->prev = 0;
	stacks->a_tail->next = stacks->a_head;
	stacks->a_head->prev = stacks->a_tail;
	stacks->a_head = stacks->a_tail;
	stacks->a_tail = new_tail;
	new_tail = stacks->b_tail->prev;
	new_tail->next = 0;
	stacks->b_tail->prev = 0;
	stacks->b_tail->next = stacks->b_head;
	stacks->b_head->prev = stacks->b_tail;
	stacks->b_head = stacks->b_tail;
	stacks->b_tail = new_tail;
	if (caller == 0)
		ft_printf("rrr\n");
}
