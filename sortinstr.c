/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortinstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:03:08 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/23 19:05:18 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_b(t_stack *stack)
{
	t_node	*tmp;
	int		range;

	tmp = stack->head;
	range = tmp->range;
	if (tmp->data < tmp->next->data)
		s_ab(stack);
	else if (tmp->data > tmp->next->data)
	{
		r_ab(stack, range);
		s_ab(stack);
		rr_ab(stack, range);
		s_ab(stack);
	}
}

void	middle_b(t_stack *stack)
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

void	last_b(t_stack *stack)
{
	t_node	*tmp;
	int		range;

	tmp = stack->head;
	range = tmp->range;
	if (tmp->data < tmp->next->data)
	{
		s_ab(stack);
		r_ab(stack, range);
		s_ab(stack);
		rr_ab(stack, range);
	}
}

void	select_stack(t_stack *stack, int num)
{
	if (stack->prop->name == 'a' && num == 1)
		first_a(stack);
	else if (stack->prop->name == 'b' && num == 1)
		first_b(stack);
	else if (stack->prop->name == 'a' && num == 2)
		middle_a(stack);
	else if (stack->prop->name == 'b' && num == 2)
		middle_b(stack);
	else if (stack->prop->name == 'a' && num == 3)
		last_a(stack);
	else if (stack->prop->name == 'b' && num == 3)
		last_b(stack);
}

void	instr_sort(t_stack *stack)
{
	int		midpoint;
	t_node	*tmp;

	tmp = stack->head;
	midpoint = head_part(stack);
	if (tmp->data == midpoint)
		select_stack(stack, 1);
	else if (tmp->next->data == midpoint &&
				tmp->data > tmp->next->next->data)
		select_stack(stack, 2);
	else if (tmp->next->next->data == midpoint)
		select_stack(stack, 3);
}
