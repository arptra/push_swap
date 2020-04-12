/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:12:06 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/24 12:27:52 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	correct_value(char *str)
{
	int sign;
	int i;
	int flag;

	sign = 0;
	i = 0;
	flag = checkflag(str);
	while (str[i] != '\0' && !flag)
	{
		if (str[i] == '-' && i == 0)
			sign++;
		else if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	if (flag == 1)
		return (2);
	else if (sign > 1)
		return (-1);
	else if (sign == 1 && ft_strlen(str) == 1)
		return (-1);
	return (1);
}

int	check_dup(t_stack *stack, int value)
{
	t_node *tmp;

	if (stack->size == 0)
		return (1);
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->data == value)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

int	check_value(char buf[], t_stack *stack)
{
	int value;

	if (correct_value(buf) == 1)
	{
		value = ft_atoi(buf);
		if (value == 0 && ft_strcmp(buf, "0") != 0)
			return (-1);
		if (check_dup(stack, value) == -1)
			return (-1);
		pushback(stack, value, 0);
	}
	else if (correct_value(buf) == 2)
		stack->prop->show = 1;
	else
		return (-1);
	return (1);
}

int	grab_value(char **str, t_stack *stack)
{
	int		i;
	int		j;
	char	buf[FILL_SIZE];

	i = 0;
	while (str[0][i] != '\0')
	{
		j = 0;
		while (str[0][i] == ' ')
			i++;
		while (str[0][i] != ' ' && str[0][i] != '\0')
			buf[j++] = str[0][i++];
		buf[j] = '\0';
		if (buf[0] == '\0' && str[0][i] == '\0')
			return (1);
		if (check_value(buf, stack) == -1)
			return (-1);
		ft_strclr(buf);
		if (str[0][i] != '\0')
			i++;
	}
	return (1);
}

int	fillstack(char **argv, int argc, t_stack *stack)
{
	argv++;
	if (!ft_strcmp(*argv, ""))
		return (-1);
	if (argc > 2)
	{
		while (*argv)
		{
			if (grab_value(argv, stack) == -1)
				return (-1);
			argv++;
		}
	}
	else
	{
		if (grab_value(argv, stack) == -1)
			return (-1);
	}
	if (stack->size != 0 && is_sort(stack, asc))
		return (-2);
	return (1);
}
