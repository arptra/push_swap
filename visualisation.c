/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:33:40 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/24 13:36:00 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		len(long n)
{
	int i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	formater(int len, int num, int print, char c)
{
	int i;
	int count;

	i = 0;
	count = (16 - len) / 2;
	ft_putchar('|');
	while (i++ < count)
		ft_putchar(' ');
	if (print)
		ft_putnbr(num);
	else
		len = 0;
	while (i++ < 17 - len)
		ft_putchar(' ');
	ft_putchar('|');
	ft_putchar(c);
}

t_node	*check_pass(t_node *tmp, int pass, char c)
{
	if (tmp && pass <= 0)
	{
		formater(len(tmp->data), tmp->data, 1, c);
		tmp = tmp->next;
	}
	else
		formater(1, 0, 0, c);
	return (tmp);
}

void	statestack(t_node *tmp_a, t_node *tmp_b, t_node *stop, t_stack *stack_a)
{
	while (stop)
	{
		if (stack_a->prop->swicher == 0)
		{
			formater(len(tmp_a->data), tmp_a->data, 1, '\t');
			tmp_a = tmp_a->next;
			tmp_b = check_pass(tmp_b, stack_a->prop->pass, '\n');
		}
		if (stack_a->prop->swicher == 1 && tmp_b)
		{
			tmp_a = check_pass(tmp_a, stack_a->prop->pass, '\t');
			formater(len(tmp_b->data), tmp_b->data, 1, '\n');
			tmp_b = tmp_b->next;
		}
		stop = stop->next;
		stack_a->prop->pass--;
	}
}

void	showstacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node *tmp_a;
	t_node *tmp_b;
	t_node *stop;

	tmp_a = stack_a->head;
	tmp_b = stack_b->head;
	stack_a->prop->swicher = 0;
	stop = tmp_a;
	stack_a->prop->pass = stack_a->size - stack_b->size;
	if (stack_a->size < stack_b->size)
	{
		stack_a->prop->swicher = 1;
		stack_a->prop->pass = stack_b->size - stack_a->size;
		stop = tmp_b;
	}
	ft_putchar('\n');
	statestack(tmp_a, tmp_b, stop, stack_a);
	ft_putstr("_________________\t _________________\n");
	ft_putstr("    STACK_A      \t       STACK_B    \n");
}
