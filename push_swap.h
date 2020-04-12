/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:46:35 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/24 14:42:47 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "stdint.h"

# define FILL_SIZE 20

typedef struct		s_node
{
	int				data;
	int				range;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_properties
{
	char			name;
	int				print;
	int				show;
	int				range;
	int				count_push;
	int				count_rot;
	int				count_revrot;
	int				midpoint;
	int				stop;
	int				var;
	int				swicher;
	int				pass;
}					t_properties;

typedef struct		s_stack
{
	int				size;
	t_node			*head;
	t_node			*tail;
	t_properties	*prop;
}					t_stack;

t_stack				*init(char name);
void				delete_stack(t_stack **stack);
void				pushfront(t_stack *stack, int value, int range);
int					popfront(t_stack *stack);
void				pushback(t_stack *stack, int value, int range);
int					popback(t_stack *stack);
t_node				*getnth(t_stack *stack, size_t index);
void				insert(t_stack *stack, size_t index, int value);
int					deletenth(t_stack *stack, size_t index);
void				s_ab(t_stack *stack);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				p_ab(t_stack *stack_a, t_stack *stack_b, int range);
void				r_ab(t_stack *stack, int range);
void				rr(t_stack *stack_a, t_stack *stack_b, int range);
void				rr_ab(t_stack *stack, int range);
void				rrr(t_stack *stack_a, t_stack *stack_b, int range);
int					fillstack(char **argv, int argc, t_stack *stack);
void				block_instr(int instr, t_stack *stack_a, t_stack *stack_b);
int					find_midpoint(t_stack *stack);
int					find_min(t_stack *stack);
void				simplelogic(t_stack *stack_a, t_stack *stack_b);
void				sort_stack(t_stack *stack, int (*f)(int, int));
int					len_range(t_stack *stack, int range);
int					is_sort(t_stack *stack, int (*f)(int, int));
int					asc(int a, int b);
int					desc(int a, int b);
void				pushtoa(t_stack *stack_a, t_stack *stack_b);
void				pushtob(t_stack *stack_a, t_stack *stack_b);
int					head_part(t_stack *stack);
void				instr_sort(t_stack *stack);
int					half_push(t_stack *stack_a, t_stack *stack_b);
void				push_rot_a(t_stack *stack_a, t_stack *stack_b);
void				revrotb(t_stack *stack_a, t_stack *stack_b);
void				revrota(t_stack *stack);
void				rerange(t_stack *stack);
void				first_a(t_stack *stack);
void				middle_a(t_stack *stack);
void				last_a(t_stack *stack);
void				first_b(t_stack *stack);
void				middle_b(t_stack *stack);
void				last_b(t_stack *stack);
void				lasthree(t_stack *stack, int min);
int					eq(int a, int b);
int					lt(int a, int b);
int					gt(int a, int b);
void				rotnpush(t_stack *stack_a, t_stack *stack_b,\
									int (*f)(int, int));
int					checkflag(char *str);
void				showstacks(t_stack *stack_a, t_stack *stack_b);
int					correct_value(char *str);
int					check_dup(t_stack *stack, int value);
int					check_value(char buf[], t_stack *stack);
int					grab_value(char **str, t_stack *stack);
void				qsortrec(int *mas, int size);
void				init_counters(t_stack *stack);
void				first_step(t_stack *stack_a, t_stack *stack_b);
void				second_step(t_stack *stack_a, t_stack *stack_b);
int					oddeven(int len);
void				rot_push(t_stack *stack_a, t_stack *stack_b, int len);
void				push_rot(t_stack *stack_a, t_stack *stack_b);
void				select_stack(t_stack *stack, int num);
int					len(long n);
void				formater(int len, int num, int print, char c);
t_node				*check_pass(t_node *tmp, int pass, char c);
void				statestack(t_node *tmp_a, t_node *tmp_b,\
								t_node *stop, t_stack *stack_a);
#endif
