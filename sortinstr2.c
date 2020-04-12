/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortinstr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:05:45 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/23 19:08:25 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_a(t_stack *stack)
{
	t_node	*tmp;
	int		range;

	tmp = stack->head;
	range = tmp->range;
	if (tmp->data > tmp->next->data)
		s_ab(stack);
	else if (tmp->data < tmp->next->data)
	{
		r_ab(stack, range);
		s_ab(stack);
		rr_ab(stack, range);
		s_ab(stack);
	}
}

void	middle_a(t_stack *stack)
{
	t_node	*tmp;
	int		range;

	tmp = stack->head;
	range = tmp->range;
	s_ab(stack);
	r_ab(stack, range);
	s_ab(stack);
	rr_ab(stack, range);
	s_ab(stack);
}

void	last_a(t_stack *stack)
{
	t_node	*tmp;
	int		range;

	tmp = stack->head;
	range = tmp->range;
	if (tmp->data > tmp->next->data)
	{
		s_ab(stack);
		r_ab(stack, range);
		s_ab(stack);
		rr_ab(stack, range);
	}
	else if (tmp->data < tmp->next->data)
	{
		r_ab(stack, range);
		s_ab(stack);
		rr_ab(stack, range);
	}
}

void	lasthree(t_stack *stack, int min)
{
	t_node	*tmp;

	tmp = stack->head;
	if (tmp->next->data == tmp->range &&
			stack->tail->data == min)
	{
		s_ab(stack);
		rr_ab(stack, tmp->range);
	}
	else if (stack->tail->data == tmp->range &&
				tmp->data == min)
	{
		rr_ab(stack, tmp->range);
		s_ab(stack);
	}
	else if (tmp->data == tmp->range &&
				stack->tail->data == min)
		rr_ab(stack, tmp->range);
	else if (stack->tail->data == tmp->range &&
				tmp->next->data == min)
		r_ab(stack, tmp->range);
	else if (tmp->data == tmp->range &&
				tmp->next->data == min)
		s_ab(stack);
}
