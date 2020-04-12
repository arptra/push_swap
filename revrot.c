/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 20:48:32 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/23 20:50:08 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	int		tailmidpoint;
	int		headmidpoint;
	int		part;

	tmp = stack_b->tail;
	part = tmp->range;
	tailmidpoint = tmp->range;
	headmidpoint = stack_b->head->range;
	while (tmp && part == tmp->range && tailmidpoint >= headmidpoint)
	{
		rr_ab(stack_b, tmp->range);
		tmp = stack_b->head;
		if (tmp->data >= tailmidpoint)
			p_ab(stack_b, stack_a, tailmidpoint);
		tmp = stack_b->tail;
	}
}

void	revrota(t_stack *stack)
{
	t_properties	*counters;
	t_node			*tmp;

	tmp = stack->tail;
	counters = stack->prop;
	while (counters->stop && counters->count_rot)
	{
		rr_ab(stack, tmp->range);
		tmp = stack->tail;
	}
}
