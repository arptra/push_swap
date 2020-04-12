/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:07:58 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/24 14:45:26 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	block_instr(int instr, t_stack *stack_a, t_stack *stack_b)
{
	if (instr == 1)
		p_ab(stack_b, stack_a, 0);
	else if (instr == 2)
		p_ab(stack_a, stack_b, 0);
	else if (instr == 3)
		s_ab(stack_a);
	else if (instr == 4)
		s_ab(stack_b);
	else if (instr == 5)
		ss(stack_a, stack_b);
	else if (instr == 6)
		r_ab(stack_a, 0);
	else if (instr == 7)
		r_ab(stack_b, 0);
	else if (instr == 8)
		rr(stack_a, stack_b, 0);
	else if (instr == 9)
		rr_ab(stack_a, 0);
	else if (instr == 10)
		rr_ab(stack_b, 0);
	else if (instr == 11)
		rrr(stack_a, stack_b, 0);
}

int		get_instr(char *instr)
{
	if (!ft_strcmp(instr, "pa"))
		return (1);
	else if (!ft_strcmp(instr, "pb"))
		return (2);
	else if (!ft_strcmp(instr, "sa"))
		return (3);
	else if (!ft_strcmp(instr, "sb"))
		return (4);
	else if (!ft_strcmp(instr, "ss"))
		return (5);
	else if (!ft_strcmp(instr, "ra"))
		return (6);
	else if (!ft_strcmp(instr, "rb"))
		return (7);
	else if (!ft_strcmp(instr, "rr"))
		return (8);
	else if (!ft_strcmp(instr, "rra"))
		return (9);
	else if (!ft_strcmp(instr, "rrb"))
		return (10);
	else if (!ft_strcmp(instr, "rrr"))
		return (11);
	else if (*instr == '\0')
		return (0);
	return (-1);
}

void	check_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size != 0 && stack_b->size == 0 && is_sort(stack_a, asc))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int		readinstr(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;
	int		value;

	value = 0;
	if (stack_a->prop->show)
		showstacks(stack_a, stack_b);
	while (get_next_line(0, &line) > 0)
	{
		value = get_instr(line);
		if (value > 0)
		{
			block_instr(value, stack_a, stack_b);
			if (stack_a->prop->show)
				showstacks(stack_a, stack_b);
		}
		else if (value == -1)
		{
			ft_putstr("Error\n");
			break ;
		}
		free(line);
	}
	return (value);
}

int		main(int argc, char **argv)
{
	int		value;
	int		flag;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(0);
	stack_a = init('a');
	stack_b = init('b');
	stack_a->prop->print = 0;
	stack_b->prop->print = 0;
	value = 0;
	if ((flag = fillstack(argv, argc, stack_a)) > 0 || flag == -2)
		value = readinstr(stack_a, stack_b);
	else
		ft_putstr("Error\n");
	if (value != -1 && flag != -1)
		check_sort(stack_a, stack_b);
	delete_stack(&stack_a);
	delete_stack(&stack_b);
	return (0);
}
