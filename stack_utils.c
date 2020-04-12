/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:12:55 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/23 19:16:55 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init(char name)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_node) + sizeof(t_properties));
	tmp->prop = (t_properties *)malloc(sizeof(t_properties));
	tmp->head = NULL;
	tmp->tail = NULL;
	tmp->size = 0;
	tmp->prop->name = name;
	tmp->prop->stop = 0;
	tmp->prop->range = 0;
	tmp->prop->count_push = 0;
	tmp->prop->count_revrot = 0;
	tmp->prop->count_rot = 0;
	tmp->prop->midpoint = 0;
	tmp->prop->var = 0;
	tmp->prop->print = 1;
	tmp->prop->show = 0;
	tmp->prop->swicher = 0;
	tmp->prop->pass = 0;
	return (tmp);
}

void	pushfront(t_stack *stack, int value, int range)
{
	t_node *tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (tmp == NULL)
		exit(1);
	tmp->data = value;
	tmp->range = range;
	tmp->next = stack->head;
	tmp->prev = NULL;
	if (stack->head)
		stack->head->prev = tmp;
	stack->head = tmp;
	if (stack->tail == NULL)
		stack->tail = tmp;
	stack->size++;
}

int		popfront(t_stack *stack)
{
	t_node	*prev;
	int		tmp;

	if (stack->head == NULL)
		exit(1);
	prev = stack->head;
	stack->head = stack->head->next;
	if (stack->head)
		stack->head->prev = NULL;
	if (prev == stack->tail)
		stack->tail = NULL;
	tmp = prev->data;
	free(prev);
	stack->size--;
	return (tmp);
}

void	pushback(t_stack *stack, int value, int range)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (tmp == NULL)
		exit(1);
	tmp->data = value;
	tmp->range = range;
	tmp->next = NULL;
	tmp->prev = stack->tail;
	if (stack->tail)
		stack->tail->next = tmp;
	stack->tail = tmp;
	if (stack->head == NULL)
		stack->head = tmp;
	stack->size++;
}

int		popback(t_stack *stack)
{
	t_node	*next;
	int		tmp;

	if (stack->tail == NULL)
		exit(1);
	next = stack->tail;
	stack->tail = stack->tail->prev;
	if (stack->tail)
		stack->tail->next = NULL;
	if (next == stack->head)
		stack->head = NULL;
	tmp = next->data;
	free(next);
	stack->size--;
	return (tmp);
}
