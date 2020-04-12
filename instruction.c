/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:43:06 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/24 13:37:48 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_ab(t_stack *stack)
{
	t_node	*tmp;
	int		save1;
	int		save2;

	tmp = stack->head;
	if (stack->size > 1)
	{
		save1 = tmp->data;
		tmp = tmp->next;
		save2 = tmp->data;
		tmp->data = save1;
		tmp = tmp->prev;
		tmp->data = save2;
	}
	if (stack->prop->print)
	{
		ft_putchar('s');
		ft_putchar(stack->prop->name);
		ft_putchar('\n');
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	swicher;

	swicher = 0;
	if (stack_a->prop->print && stack_b->prop->print)
	{
		stack_a->prop->print = 0;
		stack_b->prop->print = 0;
		swicher = 1;
	}
	s_ab(stack_a);
	s_ab(stack_b);
	if (swicher)
	{
		ft_putstr("ss\n");
		stack_a->prop->print = 1;
		stack_b->prop->print = 1;
	}
}

void	p_ab(t_stack *stack_a, t_stack *stack_b, int range)
{
	int				tmp;
	t_properties	*counters;

	counters = stack_a->prop;
	if (stack_a->size != 0)
	{
		tmp = popfront(stack_a);
		pushfront(stack_b, tmp, range);
	}
	counters->count_push--;
	if (stack_a->prop->print && stack_b->prop->print)
	{
		ft_putchar('p');
		ft_putchar(stack_b->prop->name);
		ft_putchar('\n');
	}
}

void	r_ab(t_stack *stack, int range)
{
	int				tmp;
	t_properties	*counters;

	if (stack->size != 0)
	{
		counters = stack->prop;
		tmp = popfront(stack);
		pushback(stack, tmp, range);
		counters->count_rot++;
		counters->count_revrot--;
	}
	if (stack->prop->print)
	{
		ft_putchar('r');
		ft_putchar(stack->prop->name);
		ft_putchar('\n');
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b, int range)
{
	int	swicher;

	swicher = 0;
	if (stack_a->prop->print && stack_b->prop->print)
	{
		stack_a->prop->print = 0;
		stack_b->prop->print = 0;
		swicher = 1;
	}
	r_ab(stack_a, range);
	r_ab(stack_b, range);
	if (swicher)
	{
		ft_putstr("rr\n");
		stack_a->prop->print = 1;
		stack_b->prop->print = 1;
	}
}
