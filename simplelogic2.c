/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplelogic2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:58:05 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/23 19:00:35 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		desc(int a, int b)
{
	if (a > b)
		return (0);
	return (1);
}

void	push_rot_a(t_stack *stack_a, t_stack *stack_b)
{
	t_properties	*counters;

	counters = stack_a->prop;
	counters->count_push = 1;
	counters->var = find_min(stack_a);
	rotnpush(stack_a, stack_b, eq);
	revrota(stack_a);
}

void	pushtob(t_stack *stack_a, t_stack *stack_b)
{
	t_node			*tmp;
	t_properties	*counters;

	tmp = stack_a->head;
	counters = stack_a->prop;
	while (tmp->data < counters->midpoint && counters->count_push)
	{
		p_ab(stack_a, stack_b, counters->midpoint);
		tmp = stack_a->head;
	}
}

void	pushtoa(t_stack *stack_a, t_stack *stack_b)
{
	int		part;
	t_node	*tmp;

	tmp = stack_a->head;
	part = tmp->range;
	while (tmp && tmp->range == part)
	{
		p_ab(stack_a, stack_b, part);
		tmp = stack_a->head;
	}
}

void	sort_stack(t_stack *stack, int (*f)(int, int))
{
	rerange(stack);
	if (!is_sort(stack, f))
	{
		if (stack->size == 3 && stack->prop->name == 'a')
			lasthree(stack, find_min(stack));
		else if (len_range(stack, stack->head->range) == 2)
			s_ab(stack);
		else if (len_range(stack, stack->head->range) > 2)
			instr_sort(stack);
	}
}
