/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 20:50:14 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/24 15:31:22 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stop;

	if (argc < 2)
		exit(0);
	stack_a = init('a');
	stack_b = init('b');
	if ((stop = fillstack(argv, argc, stack_a)) > 0)
		simplelogic(stack_a, stack_b);
	if (stop == -1)
		ft_putstr("Error\n");
	delete_stack(&stack_a);
	delete_stack(&stack_b);
	return (0);
}
