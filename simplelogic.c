/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplelogic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:52:15 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/23 18:57:24 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_counters(t_stack *stack)
{
	t_node			*tmp;
	t_properties	*counters;

	tmp = stack->head;
	counters = stack->prop;
	counters->count_push = len_range(stack, tmp->range) / 2;
	counters->count_rot = 0;
	counters->count_revrot = 0;
	counters->midpoint = head_part(stack);
}

void	rotnpush(t_stack *stack_a, t_stack *stack_b, int (*f)(int, int))
{
	t_node			*tmp;
	t_properties	*counters;

	counters = stack_a->prop;
	tmp = stack_a->head;
	while (counters->count_push)
	{
		if (f(tmp->data, counters->var))
			p_ab(stack_a, stack_b, counters->midpoint);
		else
			r_ab(stack_a, tmp->range);
		tmp = stack_a->head;
	}
}

void	first_step(t_stack *stack_a, t_stack *stack_b)
{
	t_properties	*counters;

	rerange(stack_a);
	init_counters(stack_a);
	if (stack_a->size != 0 && len_range(stack_a, stack_a->head->range) == 4)
		push_rot_a(stack_a, stack_b);
	else
	{
		while (stack_a->size != 0 &&
				len_range(stack_a, stack_a->head->range) > 3)
		{
			counters = stack_a->prop;
			init_counters(stack_a);
			rerange(stack_a);
			counters->var = counters->midpoint;
			pushtob(stack_a, stack_b);
			rotnpush(stack_a, stack_b, lt);
			revrota(stack_a);
			rerange(stack_b);
		}
	}
	sort_stack(stack_a, asc);
}

void	second_step(t_stack *stack_a, t_stack *stack_b)
{
	t_node *tmp;

	tmp = stack_b->head;
	if (stack_b->size != 0 && len_range(stack_b, tmp->range) <= 3)
	{
		sort_stack(stack_b, desc);
		pushtoa(stack_b, stack_a);
	}
	else
		half_push(stack_a, stack_b);
	if (stack_a->size != 0 && len_range(stack_a, stack_a->head->range) > 3)
		first_step(stack_a, stack_b);
	else
		sort_stack(stack_a, asc);
	if (stack_b->size != 0 &&
			stack_b->size != len_range(stack_b, stack_b->head->range))
		revrotb(stack_a, stack_b);
}

void	simplelogic(t_stack *stack_a, t_stack *stack_b)
{
	int	stop;

	stack_a->prop->stop = 0;
	stop = 1;
	while (stop)
	{
		first_step(stack_a, stack_b);
		if (stack_b->size != 0)
		{
			rerange(stack_b);
			stack_a->prop->stop = 1;
			second_step(stack_a, stack_b);
			stop = stack_b->size;
		}
		else
			stop = 0;
	}
}
