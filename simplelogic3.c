/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplelogic3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:01:18 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/23 19:03:01 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		oddeven(int len)
{
	int	res;

	res = 0;
	if (len % 2 != 0)
		res = len / 2;
	if (len % 2 == 0)
		res = (len / 2) - 1;
	return (res);
}

void	rot_push(t_stack *stack_a, t_stack *stack_b, int len)
{
	t_properties *counters;

	counters = stack_b->prop;
	counters->count_push = oddeven(len);
	counters->var = head_part(stack_b);
	rotnpush(stack_b, stack_a, gt);
}

void	push_rot(t_stack *stack_a, t_stack *stack_b)
{
	t_properties *counters;

	counters = stack_b->prop;
	counters->count_push = 3;
	counters->var = find_min(stack_b);
	rotnpush(stack_b, stack_a, gt);
}

int		find_min(t_stack *stack)
{
	int		min;
	int		range;
	t_node	*tmp;

	tmp = stack->head;
	range = tmp->range;
	min = tmp->data;
	while (tmp && tmp->range == range)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int		half_push(t_stack *stack_a, t_stack *stack_b)
{
	int len;

	len = len_range(stack_b, stack_b->head->range);
	if (len == 4)
		push_rot(stack_a, stack_b);
	if (len > 4)
		rot_push(stack_a, stack_b, len);
	return (0);
}
