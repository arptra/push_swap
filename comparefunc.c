/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparefunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:22:07 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/23 19:22:46 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	eq(int a, int b)
{
	if (a == b)
		return (1);
	return (0);
}

int	lt(int a, int b)
{
	if (a < b)
		return (1);
	return (0);
}

int	gt(int a, int b)
{
	if (a > b)
		return (1);
	return (0);
}

int	asc(int a, int b)
{
	if (a < b)
		return (0);
	return (1);
}

int	is_sort(t_stack *stack, int (*f)(int, int))
{
	t_node	*tmp;
	int		part;

	tmp = stack->head;
	part = tmp->range;
	while (tmp->next && tmp->range == part &&
				tmp->next->range == part)
	{
		if (f(tmp->data, tmp->next->data))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
