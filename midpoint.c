/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 20:38:36 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/23 20:44:55 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		head_part(t_stack *stack)
{
	t_node	*tmp;
	t_stack	*aux_stack;
	int		part;
	int		midpoint;

	midpoint = 0;
	if (stack)
	{
		aux_stack = init('x');
		tmp = stack->head;
		part = tmp->range;
		while (tmp && tmp->range == part)
		{
			pushfront(aux_stack, tmp->data, tmp->range);
			tmp = tmp->next;
		}
		midpoint = find_midpoint(aux_stack);
		delete_stack(&aux_stack);
	}
	return (midpoint);
}

void	rerange(t_stack *stack)
{
	int		midpoint;
	t_node	*tmp;
	int		part;

	if (stack->size != 0)
	{
		tmp = stack->head;
		part = tmp->range;
		midpoint = head_part(stack);
		while (tmp && tmp->range == part)
		{
			tmp->range = midpoint;
			tmp = tmp->next;
		}
	}
}

int		len_range(t_stack *stack, int range)
{
	int		len;
	t_node	*tmp;

	len = 0;
	tmp = stack->head;
	while (tmp && tmp->range == range)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	qsortrec(int *mas, int size)
{
	int i;
	int j;
	int mid;
	int tmp;

	i = 0;
	j = size - 1;
	mid = mas[size / 2];
	while (i <= j)
	{
		while (mas[i] < mid)
			i++;
		while (mas[j] > mid)
			j--;
		if (i <= j)
		{
			tmp = mas[i];
			mas[i++] = mas[j];
			mas[j--] = tmp;
		}
	}
	if (j > 0)
		qsortrec(mas, j + 1);
	if (i < size)
		qsortrec(&mas[i], size - i);
}

int		find_midpoint(t_stack *stack)
{
	int		i;
	int		*arr;
	t_node	*tmp;
	int		midpoint;

	i = -1;
	tmp = stack->head;
	arr = (int *)malloc(sizeof(int) * stack->size);
	while (++i < stack->size)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
	}
	qsortrec(arr, stack->size);
	midpoint = arr[stack->size / 2];
	free(arr);
	return (midpoint);
}
