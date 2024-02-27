/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:38:23 by sangshin          #+#    #+#             */
/*   Updated: 2024/02/24 10:31:27 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MALLOC_SIZE (67108865)
// 67108864 == (1 << 26)
// for under 5000
// # define MALLOC_SIZE 160
// could be much faster

# include "./new_libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_stacks
{
	struct s_stack	*a_head;
	struct s_stack	*b_head;
	struct s_stack	*a_tail;
	struct s_stack	*b_tail;
}					t_stacks;

// for stack manage
void	fill_stack(t_stacks *a, char **argv);
void	add_front(t_stack **head, int content);
void	add_last(t_stack **tail, int content);
void	push_first(t_stacks *stacks, int to_where);
int		strict_atoi(char *str);
void	duplication_check(int	**map, long long num);
void	connect_head(t_stacks *stacks);
void	for_numbers(char **numbers, int **map);
void	minus_or_plus(t_stacks *stacks, char **list,
			int **map, int minus_count);
//	for command
void	swap_a(t_stacks *stacks, int caller);
void	swap_b(t_stacks *stacks, int caller);
void	swap_both(t_stacks *stacks, int caller);
void	push_a(t_stacks *stacks, int caller);
void	push_b(t_stacks *stacks, int caller);
void	rotate_a(t_stacks *stacks, int caller);
void	rotate_b(t_stacks *stacks, int caller);
void	rotate_both(t_stacks *stacks, int caller);
void	reverse_rotate_a(t_stacks *stacks, int caller);
void	reverse_rotate_b(t_stacks *stacks, int caller);
void	reverse_rotate_both(t_stacks *stacks, int caller);
// for sorting
void	sorting(t_stacks *stacks);
void	a_to_b(t_stacks *stacks, int total, int pivot, int pivot2);
void	b_to_a(t_stacks *stacks);
int		counting_command(t_stacks *stacks, t_stack *ptr);
void	do_command(t_stacks *stacks, int index);
void	indexing(t_stacks *stacks, int **map, char **argv);
int		bit_count(int num);
int		extra_bit_count(int num, int mod, int type);
void	plus_indexing(t_stacks *stacks, int **map, int num, int minus_count);
void	minus_indexing(t_stacks *stacks, int *map, long long num);
int		is_sorted(t_stack *head);
int		stack_count(t_stack *head);
int		if_min_max(t_stack *head, int num);
void	put_end(t_stacks *stacks);
void	put_middle(t_stacks *stacks);
void	last_sort(t_stacks *stacks);
void	idt_finder(t_stacks *stacks, int *arr, int num);
int		index_value(t_stack *head, int idx);
void	set_bstack(t_stacks *stacks, int index);
int		how_many_ra(t_stacks *stacks, int target);
//	for manual_sort
void	manual_sort(t_stacks *stacks, int total);
void	sort_three(t_stacks *stacks);
void	sort_four(t_stacks *stacks);
void	sort_five(t_stacks *stacks);
void	print_error(void);
//
//	FOR CHECKER
//
void	command_check(t_stacks *stacks);
void	read_command(t_stacks *stacks);
void	exec_command(t_stacks *stacks, char *line);
#endif
