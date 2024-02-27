/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:12:51 by sangshin          #+#    #+#             */
/*   Updated: 2023/12/25 16:30:06 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks, int caller)
{
	t_stack	*new_head;

	if (stacks->a_head == 0 || stacks->a_head->next == 0)
		return ;
	new_head = stacks->a_head->next;
	new_head->prev = 0;
	stacks->a_head->next = 0;
	stacks->a_tail->next = stacks->a_head;
	stacks->a_head->prev = stacks->a_tail;
	stacks->a_tail = stacks->a_head;
	stacks->a_head = new_head;
	if (caller == 0)
		ft_printf("ra\n");
}

void	rotate_b(t_stacks *stacks, int caller)
{
	t_stack	*new_head;

	if (stacks->b_head == 0 || stacks->b_head->next == 0)
		return ;
	new_head = stacks->b_head->next;
	new_head->prev = 0;
	stacks->b_head->next = 0;
	stacks->b_tail->next = stacks->b_head;
	stacks->b_head->prev = stacks->b_tail;
	stacks->b_tail = stacks->b_head;
	stacks->b_head = new_head;
	if (caller == 0)
		ft_printf("rb\n");
}

void	rotate_both(t_stacks *stacks, int caller)
{
	t_stack	*new_head;

	if (stacks->a_head == 0 || stacks->a_head->next == 0)
		return ;
	if (stacks->b_head == 0 || stacks->b_head->next == 0)
		return ;
	new_head = stacks->a_head->next;
	new_head->prev = 0;
	stacks->a_head->next = 0;
	stacks->a_tail->next = stacks->a_head;
	stacks->a_head->prev = stacks->a_tail;
	stacks->a_tail = stacks->a_head;
	stacks->a_head = new_head;
	new_head = stacks->b_head->next;
	new_head->prev = 0;
	stacks->b_head->next = 0;
	stacks->b_tail->next = stacks->b_head;
	stacks->b_head->prev = stacks->b_tail;
	stacks->b_tail = stacks->b_head;
	stacks->b_head = new_head;
	if (caller == 0)
		ft_printf("rr\n");
}
