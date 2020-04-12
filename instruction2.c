/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:49:15 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/23 18:51:48 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_ab(t_stack *stack, int range)
{
	int				tmp;
	t_properties	*counters;

	if (stack->size != 0)
	{
		counters = stack->prop;
		tmp = popback(stack);
		pushfront(stack, tmp, range);
		counters->count_rot--;
		counters->count_revrot++;
	}
	if (stack->prop->print)
	{
		ft_putstr("rr");
		ft_putchar(stack->prop->name);
		ft_putchar('\n');
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int range)
{
	int	swicher;

	swicher = 0;
	if (stack_a->prop->print && stack_b->prop->print)
	{
		stack_a->prop->print = 0;
		stack_b->prop->print = 0;
		swicher = 1;
	}
	rr_ab(stack_a, range);
	rr_ab(stack_b, range);
	if (swicher)
	{
		ft_putstr("rr\n");
		stack_a->prop->print = 1;
		stack_b->prop->print = 1;
	}
}
