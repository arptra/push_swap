/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:36:19 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/24 13:37:16 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_stack(t_stack **stack)
{
	t_node	*tmp;
	t_node	*next;

	tmp = (*stack)->head;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free((*stack)->prop);
	free(*stack);
	(*stack) = NULL;
}

int		checkflag(char *str)
{
	if (!ft_strcmp("-v", str))
		return (1);
	return (0);
}
